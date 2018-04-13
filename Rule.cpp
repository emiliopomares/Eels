#include "Rule.hpp"


Rule::Rule() {


}

void Rule::AddSegment(Segment *s) {


}

void Rule::SetAction(void (*f)(Rule *r, Engine *e, int pass)) {

	onCompleted = f;

}

void Rule::AttemptAdvance(Datatype sym) {


}

bool Rule::IsCompleted() {

	return false;

}

Datatype Rule::GetSymbol() {

	Datatype res;
	return res;

}

Datatype Rule::GetData() {

	Datatype data;
	return data;

}

int Rule::GetIndex() {

	return symbol_id;

}
