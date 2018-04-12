#include <vector>
#include <stack>

class StateNode {

public:
	StateNode();

	std::vector<std::stack<Rule>> state;
	StateNode *parent;

}