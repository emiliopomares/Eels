//
//  Builtin.cpp
//  Eels!
//
//  Created by Emilio Pomares on 10/04/2018.
//  Copyright © 2018 DDI. All rights reserved.
//

#include "Builtin.hpp"
#include "Parser.hpp"

#include <iostream>

bool IsValidDecDigit(char c) {

    return (c>='0' && c<='9');

}

bool IsValidRangeCharacter(char c) {
    
    if(c>='A' && c<='Z') return true;
    if(c>='a' && c<='z') return true;
    if(c>='0' && c<='9') return true;
    return false;
    
}

/// hard coded character detection. Returns how many positions the head must advance
int DetectLabelCharacter(Parser *p) {
    
    char c = p->CharAt(0);
    if(IsValidRangeCharacter(c)) return 1;
    if(c=='_') return 1;
    
    return 0;
    
}

bool IsValidStandardSpacer(char c) {

    if (c==' ') return true;
    if (c=='\n') return true;
    if (c=='\r') return true;
    if (c=='\t') return true;
    return false;

}

/// Returns >0 is parser head is pointing at the beginning of a region comprised of blank characters [' ', '\n', '\r', '\t']
int DetectStandardSpacers(Parser *p) {

    int offset = 0;
    while(IsValidStandardSpacer(p->CharAt(offset))) ++offset;
    //std::cout << "call to detect... " << offset << " separators counted\n";
    return offset;

}

/// Returns >0 if parser head is pointing at the beginning of a range
int DetectRange(Parser *p) {

    if(IsValidRangeCharacter(p->CharAt(0)) && IsValidRangeCharacter(p->CharAt(2)) && p->CharAt(1)=='-') return 3;
    return 0;

}

int DetectString(Parser *p) {

    if(p->CharAt(0) == '"') {

        int offset = 1;
        while((p->CharAt(offset) != '"') && (p->CharAt(offset) != PARSER_EOB)) ++offset;

        if(p->CharAt(offset) == '"') return offset;

    }

    return 0;

}

int DetectInteger(Parser *p) {

    int offset = 0;
     while(IsValidDecDigit(p->CharAt(offset))) ++offset;
    return offset;


}

