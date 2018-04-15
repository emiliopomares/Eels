#include "RuleActivation.hpp"

RuleActivation::RuleActivation(Rule *r) {

	for(int i = 0; i < r->GetBody()->NDisjuntives(); ++i) {

		RuleActivationStatus sts;
		sts.segment = 0;
		sts.subsegment = 0;
		branch.push_back(sts);

	}

	state = RuleInactive;
	rule = r;


}

RuleActivationStatus RuleActivation::GetBranchActivation(int b) {

	return branch[b];

}

void RuleActivation::SetBranchActivation(int b, RuleActivationStatus sts) {

	branch[b] = sts;

}

Rule *RuleActivation::GetRule() {

	return rule;

}