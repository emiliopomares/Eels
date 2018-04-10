//
//  Parser.hpp
//  Eels!
//
//  Created by Remilia Scarlet on 10/04/2018.
//  Copyright © 2018 DDI. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include <stdio.h>

#endif /* Parser_hpp */

#define PARSER_EOB 0

class Parser {
    
private:
    
    long length;
    long headIndex;
    char *buffer;
    
    
public:
    
    Parser();
    Parser(FILE *f);
    Parser(char *buf, int l);
    Parser(char *buf, int l, bool copy);
    ~Parser();
    
    char CharAt(int offset);
    void AdvanceHead(int offset);
    
};
