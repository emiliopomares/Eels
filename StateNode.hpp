#ifndef STATENODE_DEF
#define STATENODE_DEF

#include "Rule.hpp"
#include "RuleActivation.hpp"
#include "RuleExecution.hpp"
#include "DataSequence.hpp"
#include <vector>
#include <stack>

class Rule;
class RuleActivation;

class StateNode {

private:
	std::vector<Rule *>* rule;
	DataSequence *dataNode;

public:
	StateNode(std::vector<Rule *>*rulelist);
	~StateNode();

	int NumRules();
	//void AddRule();
	Rule *GetRule(int i);
	RuleActivation *GetActivation(int i);
	void RemoveFromStack(int i);

	std::vector<std::stack<RuleActivation *> *> activation;
	StateNode *sibling;

	std::vector<RuleExecution *> execute;

};

#endif