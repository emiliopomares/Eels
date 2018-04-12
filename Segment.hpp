#include <string>

enum Qualifier { MULTIPLICITY_NONE, MULTIPLICITY_STAR, MULTIPLICITY_PLUS };

class Segment {

public:
	std::string	literal;
	int symbol_id;
	Qualifier q;

};