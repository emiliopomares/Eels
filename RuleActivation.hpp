#ifndef RULEACTIVATION_DEF
#define RULEACTIVATION_DEF

#include "Rule.hpp"

class Rule;

enum RuleState { RuleActivated, RuleInactive, RuleCompleted };

class RuleActivation {

private:
	Rule *rule;

public:
	RuleActivation(Rule *r);
	RuleState state;
	int branch;
	int segmentsCompleted;

};

#endif