#include "Rule.hpp"
#include "RuleExecution.hpp"
#include <iostream>

Rule::Rule(int nrule) {

	isCompleted = false;
	symbol_id = nrule;
	body = new Sequence();

}

void Rule::AddSegment(Segment *s) {

	body->AddSegment(s);

}

void Rule::SetAction(void (*f)(DataSequence *d, Engine *e, int pass)) {

	onCompleted = f;

}

bool Rule::IsCompleted() {

	return isCompleted;

}

void Rule::SetCompleted(bool c) {

	isCompleted = c;

}

int Rule::GetSymbol() {

	return symbol_id;

}

Datatype Rule::GetData() {

	Datatype data;
	return data;

}

int Rule::GetIndex() {

	return symbol_id;

}

Sequence * Rule::GetBody() {

	return body;

}

bool Rule::AttemptAdvance(RuleActivationStatus &act, int b) {

	if(body->disjuntive.size() == 0) {

				

	}
	else {


	}
	return false;

}

void Rule::print(int level) {

	for(int i = 0; i < level; ++i) {

		std::cout << "\t";

	}
	std::cout << "printing rule: " << GetIndex() << "...\n";

	body->print(level+1);

	for(int i = 0; i < level; ++i) {

		std::cout << "\t";

	}
	std::cout << "...rule done\n\n\n";

}