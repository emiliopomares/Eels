//
//  Parser.cpp
//  Eels!
//
//  Created by Emilio Pomares on 10/04/2018.
//  Copyright © 2018 DDI. All rights reserved.
//

#include "Parser.hpp"
#include <cstring>
#include <cstdio>

Parser::Parser() {
    
    headIndex = -1;
    buffer = NULL;
    length = 0;
    
}

Parser::Parser(FILE *f) {
    
    std::fseek(f, 0, SEEK_END);
    long fileLength = ftell(f);
    std::rewind(f);
    buffer = new char[fileLength+1];
    std::fread(buffer, 1, fileLength, f);
    buffer[fileLength-1] = PARSER_EOB;
    length = fileLength;
    headIndex = 0;
    
}

/// Reference the passed buffer
Parser::Parser(char *buf, long l) {
    
    length = l;
    buffer = buf;
    headIndex = 0;
    
}

/// Optionally copy the passed buffer
Parser::Parser(char *buf, long l, bool copy) {
    
    if(copy) {
        
        buffer = new char[l+1];
        std::memcpy(buffer, buf, l);
        buffer[l-1] = PARSER_EOB;
        headIndex = 0;
    
    }
    else Parser(buf, l);

}

Parser::~Parser() {
    
    delete[] buffer;
    headIndex = -1;
    length = 0;
    
}

char Parser::CharAt(int offset) {
    
    long effectiveOffset = headIndex + offset;
    if(effectiveOffset < length)
        return buffer[effectiveOffset];
    
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
