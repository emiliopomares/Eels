//
//  Parser.hpp
//  Eels!
//
//  Created by Emilio Pomares on 10/04/2018.
//  Copyright © 2018 DDI. All rights reserved.
//

#ifndef PARSER_DEF
#define PARSER_DEF

#include <stdio.h>
#include <string>
#include "Builtin.hpp"
#include "StreamReader.hpp"
#include "Datatype.hpp"

#define PARSER_EOB 0

class Parser {
    
private:
    
    long length;
    long headIndex;
    char *buffer;
    StreamReader *reader;
    Datatype headValue;
    
    
public:
    
    Parser();
    Parser(StreamReader *r);
    ~Parser();
    
    char GetChar();
    char CharAt(int offset);
    void AdvanceHead(int offset);
    long Offset();
    bool HeadIsEmpty();
    int DetectInteger();
    int DetectNonTerminal();
    void push(Datatype symbol);
    std::string Extract();
    void SetValueAtHead(Datatype d);
    Datatype GetSymbol();
    
};


#endif /* Parser_hpp */
