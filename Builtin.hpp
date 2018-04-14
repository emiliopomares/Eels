//
//  Builtin.hpp
//  Eels!
//
//  Created by Emilio Pomares on 10/04/2018.
//  Copyright © 2018 DDI. All rights reserved.
//

#ifndef BUILTIN_DEF
#define BUILTIN_DEF

#include <stdio.h>

typedef struct {

	char start;
	char end;

} Basic_Range_T;

#define BASIC_TYPE_RANGE 0
#define BASIC_TYPE_STRING 1
#define BASIC_TYPE_INT 2
#define BASIC_TYPE_FLOAT 3
#define BASIC_TYPE_DOUBLE 4
#define BASIC_TYPE_CHAR 5

class Parser;

extern "C" bool IsValidRangeCharacter(char c);
extern "C" int DetectLabelCharacter(Parser *p);
extern "C" int DetectRange(Parser *p);
extern "C" int DetectString(Parser *p);
extern "C" int DetectInteger(Parser *p);


#endif /* Builtin_hpp */


