//
//  Parser.cpp
//  Eels!
//
//  Created by Remilia Scarlet on 10/04/2018.
//  Copyright © 2018 DDI. All rights reserved.
//

#include "Parser.hpp"

Parser::Parser() {
    
    headIndex = -1;
    buffer = nullptr;
    length = 0;
    
}

Parser::Parser(FILE *f) {
    
    fseek(f, 0, SEEK_END);
    long fileLength = ftell(f);
    rewind(f);
    buffer = new char[fileLength+1];
    fread(f, 1, fileLength, buffer);
    buffer[fileLength-1] = PARSER_EOB;
    length = fileLength;
    
}

Parser::Parser(char *buf, int l) {
    
    
}

Parser::Parser(char *buf, int l, int copy) {
    

}

Parser::~Parser() {
    
    
}

char Parser::CharAt(int offset) {
    
    if(offset < length)
        return buffer[offset];
    
    else return PARSER_EOB;
        
}
