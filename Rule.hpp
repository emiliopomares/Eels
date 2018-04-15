#ifndef RULE_DEF
#define RULE_DEF

#include "Datatype.hpp"
#include "Symboltype.hpp"
#include "Sequence.hpp"
#include "RuleActivation.hpp"
#include "RuleActivationStatus.hpp"
#include "Engine.hpp"
#include "DataSequence.hpp"

class Engine;
class Sequence;

class Rule {

private:

	int symbol_id;
	Sequence *body;
	bool isCompleted;

public:

	Rule(int nrule);
	Datatype result;
	void (*onCompleted)(DataSequence *d, Engine *e, int pass);
	void AddSegment(Segment *s);
	void SetAction(void (*f)(DataSequence *d, Engine *e, int pass));
	Sequence *GetBody();
	bool AttemptAdvance(RuleActivationStatus &act, int b);
	bool IsCompleted();
	int GetSymbol(); // TODO: Split Datatype and Symboltype (the latter being more lightweight)
	Datatype GetData();
	int GetIndex();
	void SetCompleted(bool c);
	void print(int level);

};

#endif