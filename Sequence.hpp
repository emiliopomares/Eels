#ifndef SEQUENCE_DEF
#define SEQUENCE_DEF

#include "Segment.hpp"
#include <vector>

class Sequence {

private:
	bool singleSegmentUsed;

public:
	Sequence();
	Sequence(Segment *seg);
	~Sequence();
	Segment *baseCase;	
	std::vector<Sequence *> segmentlist;
	std::vector<Sequence *> disjuntive;
	Qualifier q;
	int NDisjuntives();
	void AddSegment(Segment *s);
	void print(int level);

};

#endif