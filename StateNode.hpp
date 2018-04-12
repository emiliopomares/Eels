#include <vector>
#include <stack>

class StateNode {

public:
	StateNode();
	~StateNode();

	std::vector<std::stack<Rule *>> rule;
	StateNode *sibling;

	int NumRules();
	Rule *GetRule(int idx);

}