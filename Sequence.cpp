#include "Sequence.hpp"
#include <iostream>

Sequence::Sequence() {

	singleSegmentUsed = false;
	baseCase = NULL;

}

Sequence::Sequence(Segment *seg) {

	singleSegmentUsed = true;
	baseCase = seg;

}

Sequence::~Sequence() {


}

int Sequence::NDisjuntives() {

	if(disjuntive.size() == 0) return 1;
	return disjuntive.size();

}

void Sequence::AddSegment(Segment *s) {

	if(singleSegmentUsed==false) {

		baseCase = s;
		singleSegmentUsed = true;

	}
	else {

		if(segmentlist.size() == 0) {

			Sequence *newSeq = new Sequence(baseCase);
			baseCase = NULL;
			segmentlist.push_back(newSeq);

		}

		Sequence *newSeq2 = new Sequence(s);
		segmentlist.push_back(newSeq2);

	}

	

}

void Sequence::print(int level) {

	for(int i = 0; i < level; ++i) {

		std::cout << "\t";

	}
	std::cout << "printing sequence... \n";
	if(baseCase != NULL) {

		baseCase->print(level+1);

	}
	else {

		for(int i = 0; i < segmentlist.size(); ++i) {

			segmentlist[i]->print(level+1);

		}

	}
	for(int i = 0; i < level; ++i) {

		std::cout << "\t";

	}
	std::cout << "...end of sequence\n\n";
	std::cout << "\n";

}