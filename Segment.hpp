#ifndef SEGMENT_DEF
#define SEGMENT_DEF

#include <string>

enum Qualifier { MULTIPLICITY_NONE, MULTIPLICITY_STAR, MULTIPLICITY_PLUS };

class Segment {

private:
	char *literal_cstr;
	int matchedCharacters;

public:
	std::string	literal;
	int integer;
	int symbol_id;
	Qualifier q;
	Segment(int symbol);
	Segment(std::string lit);
	~Segment();
	static Segment *Integer();
	static Segment *Literal(std::string s);
	void print(int level);

};

#endif