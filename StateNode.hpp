#ifndef STATENODE_DEF
#define STATENODE_DEF

#include "Rule.hpp"
#include "RuleActivation.hpp"
#include <vector>
#include <stack>

class StateNode {

private:
	std::vector<Rule *>* rule;

public:
	StateNode(std::vector<Rule *>*rulelist);
	~StateNode();

	int NumRules();
	void AddRule();
	Rule *GetRule(int i);
	void RemoveFromStack(int i);

	std::vector<std::stack<RuleActivation *> *> activation;
	StateNode *sibling;


};

#endif