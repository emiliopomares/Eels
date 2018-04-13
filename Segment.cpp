#include "Segment.hpp"


Segment * Segment::Integer() {

	Segment *newSegment;
	newSegment = new Segment();
	return newSegment;


}
Segment * Segment::Literal(std::string s) {

	Segment *newSegment;
	newSegment = new Segment();
	newSegment->literal = s;
	return newSegment;

}
