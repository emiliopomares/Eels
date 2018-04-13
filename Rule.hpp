#ifndef RULE_DEF
#define RULE_DEF

#include "Datatype.hpp"
#include "Sequence.hpp"
#include "Engine.hpp"

class Engine;
class Sequence;

class Rule {

private:
	static int nrules;

public:
	Rule();
	int symbol_id;
	Datatype result;
	Sequence *body;
	void (*onCompleted)(Rule *r, Engine *e, int pass);
	void AddSegment(Segment *s);
	void SetAction(void (*f)(Rule *r, Engine *e, int pass));
	void AttemptAdvance(Datatype sym);
	bool IsCompleted();
	Datatype GetSymbol(); // TODO: Split Datatype and Symboltype (the latter being more lightweight)
	Datatype GetData();
	int GetIndex();

};

#endif