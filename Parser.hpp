//
//  Parser.hpp
//  Eels!
//
//  Created by Emilio Pomares on 10/04/2018.
//  Copyright © 2018 DDI. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include <stdio.h>
#include "Builtin.hpp"



#define PARSER_EOB 0

class Parser {
    
private:
    
    long length;
    long headIndex;
    char *buffer;
    
    
public:
    
    Parser();
    Parser(FILE *f);
    Parser(char *buf, long l);
    Parser(char *buf, long l, bool copy);
    ~Parser();
    
    char CharAt(int offset);
    void AdvanceHead(int offset);
    long Offset();
    
};


#endif /* Parser_hpp */
