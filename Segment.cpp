#include "SymbolTable.hpp"
#include "Segment.hpp"
#include <iostream>

Segment::Segment(int symbol) {

	symbol_id = symbol;

}

Segment::Segment(std::string lit) {

	symbol_id = -1;
	literal = lit;
	literal_cstr = (char *)lit.c_str();
	matchedCharacters = 0;

}

Segment * Segment::Integer() {

	Segment *newSegment;
	newSegment = new Segment(SymbolTable::Builtin_Integer);
	return newSegment;


}
Segment * Segment::Literal(std::string s) {

	Segment *newSegment;
	newSegment = new Segment(s);
	return newSegment;

}

// for debug purposes
void Segment::print(int level) {

	for(int i = 0; i < level; ++i) std::cout << "\t";
	if(symbol_id!=-1) {

		std::cout << "segment symbol: " << symbol_id;

	}
	else {

		std::cout << "segment literal: " << literal;

	}
	std::cout << "\n";

}
