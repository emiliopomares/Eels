#ifndef SEQUENCE_DEF
#define SEQUENCE_DEF

#include "Segment.hpp"
#include <vector>

class Sequence {

public:
	Segment *singleSegment;	
	std::vector<Sequence *> basicSegment;
	std::vector<Sequence *> disjuntive;
	Qualifier q;

};

#endif