//
//  Parser.cpp
//  Eels!
//
//  Created by Emilio Pomares on 10/04/2018.
//  Copyright © 2018 DDI. All rights reserved.
//

#include "StreamReader.hpp"
#include "Parser.hpp"
#include <cstring>
#include <cstdio>
#include <iostream>

Parser::Parser() {
    
    reader = NULL;

    headIndex = -1;
    buffer = NULL;
    length = 0;

    std::cout << "New parser created\n";
    
}


Parser::Parser(StreamReader *r) {
    
    reader = r;

    headIndex = -1;
    buffer = NULL;
    length = 0;

    std::cout << "New parser created\n";
    
}

void Parser::SetValueAtHead(Datatype d) {

    headValue = d;

}

void Parser::push(Datatype symbol) {


}

Datatype Parser::GetSymbol() {

    return headValue;

}

int Parser::DetectInteger() {

    return 0;

}

int Parser::DetectNonTerminal() {

    return 0;

}

bool Parser::HeadIsEmpty() {

    return true;

}

std::string Extract() {

    return "";

}


Parser::~Parser() {
    
    headIndex = -1;
    length = 0;
    
}

char Parser::GetChar() {

    return reader->GetCharAt(headIndex);

}

char Parser::CharAt(int offset) {
    
    long effectiveOffset = headIndex + offset;
    if(effectiveOffset < length)
        return reader->GetCharAt(effectiveOffset);
    
    else return PARSER_EOB;
        
}

void Parser::AdvanceHead(int offset) {
    
    long newIndex = headIndex + offset;
    if(newIndex > length) newIndex = length;
    headIndex = newIndex;
    
}

long Parser::Offset() {
    
    return headIndex;
    
}
