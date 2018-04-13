#ifndef SEGMENT_DEF
#define SEGMENT_DEF

#include <string>

enum Qualifier { MULTIPLICITY_NONE, MULTIPLICITY_STAR, MULTIPLICITY_PLUS };

class Segment {

public:
	std::string	literal;
	int integer;
	int symbol_id;
	Qualifier q;
	static Segment *Integer();
	static Segment *Literal(std::string s);

};

#endif