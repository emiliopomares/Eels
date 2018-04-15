#ifndef RULEEXECUTION_DEF
#define RULEEXECUTION_DEF

#include "Engine.hpp"
#include "DataSequence.hpp"

class Engine;
class DataSequence;

class RuleExecution {
	
public:
	DataSequence *dataseq;
	void (*f)(DataSequence *d, Engine *e, int pass);

};

#endif