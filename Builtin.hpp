//
//  Builtin.hpp
//  Eels!
//
//  Created by Emilio Pomares on 10/04/2018.
//  Copyright © 2018 DDI. All rights reserved.
//

#ifndef Builtin_hpp
#define Builtin_hpp

#include <stdio.h>

class Parser;

extern "C" bool IsValidRangeCharacter(char c);
extern "C" int DetectLabelCharacter(Parser *p);
extern "C" int DetectRange(Parser *p);
extern "C" int DetectString(Parser *p);


#endif /* Builtin_hpp */
