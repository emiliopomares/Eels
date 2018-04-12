enum RuleState { RuleActivated, RuleInactive, RuleCompleted };

class Rule {

	int symbol_id;
	RuleState state = RuleInactive;
	Sequence body;
	void (*onCompleted)();

}