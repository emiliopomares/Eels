//
//  Builtin.cpp
//  Eels!
//
//  Created by Remilia Scarlet on 10/04/2018.
//  Copyright © 2018 DDI. All rights reserved.
//

#include "Builtin.hpp"
#include "Parser.hpp"

/// hard coded character detection. Returns how many positions the head must advance
inline int DetectLabelCharacter(Parser *p) {
    
    char c = p->CharAt(0);
    if(c >= 'A' && c <= 'Z') return 1;
    if(c=='_') return 1;
    if(c >= 'a' && c <= 'z') return 1;
    if(c >= '0' && c <= '9') return 1;
    
    return 0;
    
}

/// Returns true if parser head is pointing at the beginning of a range
inline int DetectRange(Parser *p) {

    char sc = p->CharAt(0);
    
    

}

