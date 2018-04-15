#ifndef RULEACTIVATION_DEF
#define RULEACTIVATION_DEF

#include "Rule.hpp"
#include "RuleActivationStatus.hpp"

class Rule;

enum RuleState { RuleActivated, RuleInactive, RuleCompleted };



class RuleActivation {

private:
	Rule *rule;
	std::vector<RuleActivationStatus> branch;

public:
	RuleActivation(Rule *r);
	RuleActivationStatus GetBranchActivation(int b);
	void SetBranchActivation(int b, RuleActivationStatus sts);
	RuleState state;
	int branchActivated;
	Rule *GetRule();
	

};

#endif