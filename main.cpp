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
#include "Engine.hpp"

#include "FileStreamReader.hpp"
#include "ConsoleStreamWriter.hpp"

int main(int argc, const char * argv[]) {

	FileStreamReader *reader;
	ConsoleStreamWriter *writer;
    
    std::FILE *f = fopen(argv[1], "rb");
    if(f!=NULL) {
     reader = new FileStreamReader(f);
     writer = new ConsoleStreamWriter();
    
   	 Engine *e = new Engine(reader, writer);
	}

    return 0;
}
