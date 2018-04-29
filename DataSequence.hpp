#ifndef DATASEQUENCE_DEF
#define DATASEQUENCE_DEF

#include "DataSegment.hpp"
#include <vector>

class DataSequence {

private:
	bool singleSegmentUsed;

public:
	DataSequence();
	DataSequence(DataSegment *seg);
	DataSequence(std::string extract, Datatype type);
	~DataSequence();
	DataSegment *baseCase;	
	std::vector<DataSequence *> segmentlist;
	std::vector<DataSequence *> disjuntive;
	std::vector<DataSequence *> sequcenlist; // when multiplicity is != NONE
	Qualifier q;
	//int NDisjuntives();
	//void AddSegment(Segment *s);
	//int NSegments();
	//void print(int level);

};

#endif