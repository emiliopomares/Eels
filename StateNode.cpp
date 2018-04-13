#include "StateNode.hpp"

StateNode::StateNode(std::vector<Rule *>*rulelist) {

	for(int i = 0; i < rulelist->size(); ++i) {

		std::stack<RuleActivation *> *newStack = new std::stack<RuleActivation *>();
		activation.push_back(newStack);

	}
	sibling = NULL;
	rule = rulelist;

}

void StateNode::AddRule() {

	Rule *newRule = new Rule();
	std::stack<Rule *> newStack;
	//newStack.

}

int StateNode::NumRules() {

	return rule->size();

}

Rule *StateNode::GetRule(int i) {

	return rule->at(i);

}

void StateNode::RemoveFromStack(int i) {

	
}