//
//  main.cpp
//  Eels!
//
//  Created by Emilio Pomares on 10/04/2018.
//  Copyright © 2018 DDI. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>

#include "Parser.hpp"

int main(int argc, const char * argv[]) {
    
    std::FILE *f = fopen(argv[1], "rb");
    Parser *p = new Parser(f);
    std::fclose(f);
    
    int r = 0;
    int sc = 0;
    int strs = 0;
    while(p->CharAt(0) != PARSER_EOB) {
        
        int skip;
        bool somethingDetected = false;
        
        // test for a range
        skip = DetectRange(p);
        if(skip > 0) {
            p->AdvanceHead(skip);
            ++r;
            somethingDetected = true;
        }
        else {
            // if not a range, test simple character
            skip = DetectLabelCharacter(p);
            if(skip > 0) {
                p->AdvanceHead(skip);
                ++sc;            
                somethingDetected = true;
            }

            else {

                // try to detect a string
                skip = DetectString(p);
                if(skip > 0) {

                    p->AdvanceHead(skip);
                    ++strs;
                    somethingDetected = true;

                }

            }

        }

        if(!somethingDetected) p->AdvanceHead(1);

        
    }
    
    
    std::cout << r << " ranges detected\n";
    std::cout << sc << " simple characters detected\n";
    std::cout << strs << " strings detected\n";
    return 0;
}
