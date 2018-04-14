#ifndef RULE_DEF
#define RULE_DEF

#include "Datatype.hpp"
#include "Symboltype.hpp"
#include "Sequence.hpp"
#include "RuleActivation.hpp"
#include "RuleActivationStatus.hpp"
#include "Engine.hpp"

class Engine;
class Sequence;

class Rule {

private:
	static int nrules;
	int symbol_id;
	Sequence *body;

public:
	Rule();
	Datatype result;
	void (*onCompleted)(Rule *r, Engine *e, int pass);
	void AddSegment(Segment *s);
	void SetAction(void (*f)(Rule *r, Engine *e, int pass));
	Sequence *GetBody();
	bool AttemptAdvance(RuleActivationStatus &act, int b);
	bool IsCompleted();
	int GetSymbol(); // TODO: Split Datatype and Symboltype (the latter being more lightweight)
	Datatype GetData();
	int GetIndex();
	void print(int level);

};

#endif