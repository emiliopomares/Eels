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
#include "Symboltype.hpp"

#define SYMBOL_EMPTY -2
#define SYMBOL_CHAR -1

#define PARSER_EOB 0

class Parser {
    
private:
    
    long length;
    long headIndex;
    char *buffer;
    StreamReader *reader;
    Symboltype headSymbol;
    
    
public:
    
    Parser();
    Parser(StreamReader *r);
    ~Parser();
    
    char GetChar();
    char CharAt(int offset);
    void AdvanceHead(int offset);
    long Offset();
    bool HeadIsEmpty();
    int ParserDetectInteger();
    int ParserDetectNonTerminal();
    int ParserDetectStandardSpacers();
    void push(Symboltype symbol);
    std::string Extract(bool resetPointers);
    void SetSymbolAtHead(Symboltype s);
    Symboltype GetSymbolAtHead();
    void ClearHead();
    
};


#endif /* Parser_hpp */
