#include <iostream>
#include <cstring>

#include "Segment.hpp"
#include "Sequence.hpp"
#include "MetaActions.hpp"
#include "StateNode.hpp"
#include "Symboltype.hpp"
#include "Datatype.hpp"
#include "RuleExecution.hpp"

void Engine::FillInMetaRules() {

	//int sym = symTable->RegisterSymbol("rule");
	//state->AddRule(sym);
	//state->AddSegment(Segment::CreateNonTerminal());
	//state->AddSegment(Segment::CreateLiteral(":="));
	//state->


//======================== TEST ==========================
	// test stuff, remove later: let's make it just an adding machine for now
	int sym = symTable->RegisterSymbol("addition");
	Rule *r = AddRule(sym);
	r->AddSegment(Segment::Integer());
	r->AddSegment(Segment::Literal("+"));
	r->AddSegment(Segment::Integer());
	r->SetAction(onAdditionComplete);
	r->print(0);

	r = AddRule(sym);
	r->AddSegment(Segment::Integer());
	r->AddSegment(Segment::Literal("-"));
	r->AddSegment(Segment::Integer());
	r->SetAction(onSubstractionComplete);
	r->print(0);
//======================== TEST ==========================



}

Rule *Engine::AddRule(int sym) {

	Rule *newRule = new Rule(rules.size());
	rules.push_back(newRule);
	return newRule;
	
}

StreamWriter *Engine::GetStreamWriter() {

	return out;

}

void Engine::Initialize() {

	rules.clear();
	symTable = new SymbolTable();
	FillInMetaRules();
	//state = new StateNode(&rules);
	

}

int Engine::Process() {

	int r;
	r = Step();

	while(r!=PARSE_END) {

	 	r = Step();


	}

	// ejecute list
	int MAXPASSES = 1;
	for(int pass = 0; pass < MAXPASSES; ++pass) {
		
		for(int i = 0; i < state->execute.size(); ++i) {

			state->execute[i]->f(state->execute[i]->dataseq, this, pass);

		}

	}

	return 0;

}

int Engine::NumRules() {

	return rules.size();

}

Engine::Engine(StreamReader *strin, StreamWriter *strout) {

	parser = new Parser(strin);
	out = strout;
	Initialize();

	state = new StateNode(&rules);

	std::cout << "new Engine created\n";

}

RuleActivationStatus Engine::matchSegmentToSymbol(Segment *seg, Symboltype sym, RuleActivationStatus stats) {

	RuleActivationStatus newActiv;
	int segmentSymbol = seg->GetSymbol();

	if(segmentSymbol != -1) {  // segment requires a non-terminal symbol to match

		//std::cout << " $$$$$$$$$$$$ segment contains symbol, trying to match " << sym.symbol << " to " << segmentSymbol << " \n";

		if(segmentSymbol == sym.symbol) {

			newActiv.segment = stats.segment+1;
			newActiv.subsegment = 0;
			//std::cout << "                      matched, newActiv.segment= " << newActiv.segment << ", newActiv.subsegment= " << newActiv.subsegment << " \n";
			return newActiv;

		}

	}
	else {

		const char *chars = seg->GetLiteral();

		std::cout << " $$$$$$$$$$$$ segment contains literal, trying to match " << sym.c << " to " << std::string(chars) << " \n";

		if(stats.subsegment < std::strlen(chars)) {

			if(chars[stats.subsegment] == sym.c) {

				std::cout << " $$$$$$$$$$$$ ... and it was matched \n";

				newActiv.segment = stats.segment;
				newActiv.subsegment = stats.subsegment+1;
				if(newActiv.subsegment == std::strlen(chars)) {

					newActiv.segment++;
					newActiv.subsegment = 0;
					return newActiv;

				}

			}

		}
		std::cout << " $$$$$$$$$$$$ ... and it was NOT matched \n";

	}

	newActiv.segment = 0;
	newActiv.subsegment = 0;
	return newActiv;

}

RuleActivationStatus Engine::matchSequenceToSymbol(Sequence *seq, Symboltype sym, RuleActivationStatus stats) {

	RuleActivationStatus newActiv;

	if(seq->baseCase != NULL) {


		return matchSegmentToSymbol(seq->baseCase, sym, stats);


	}
	else {

		if(stats.segment < seq->NSegments()) {

			//std::cout << " ############ trying to match segment " << stats.segment << "\n";
			return matchSequenceToSymbol(seq->segmentlist[stats.segment], sym, stats);

		}

	}

	newActiv.segment = 0;
	newActiv.subsegment = 0;
	return newActiv;

}

void Engine::AttemptAdvanceRule(int rulenum, Symboltype s) {

	std::cout << "trying to advance rule " << rulenum << " with symbol (" << s.symbol << ", " << s.c << ")\n";

	RuleActivation *act = state->GetActivation(rulenum);
	Rule *rule = rules[rulenum];

	Sequence *current = rule->GetBody();
	int dis = current->NDisjuntives();

	RuleActivation *thisRuleActiv = state->GetActivation(rulenum);
	int branch = 0;
	std::cout << "        >>>>>>>>>>>>>>>>>   this rule activation was before " << thisRuleActiv->GetBranchActivation(0).segment << " , " << thisRuleActiv->GetBranchActivation(0).subsegment << "\n";

	if(dis == 1) {

		RuleActivationStatus newStats;
		newStats = matchSequenceToSymbol(current, s, thisRuleActiv->GetBranchActivation(0));
		//std::cout << "        >>>>>>>>>>>>>>>>>   newStats is " << newStats.segment << " , " << newStats.subsegment << "\n";
		if((newStats.segment == 0) && (newStats.subsegment == 0)) { // rule advance fail

			thisRuleActiv->state = RuleInactive;
			RuleActivationStatus resetStats;
			resetStats.segment = 0;
			resetStats.subsegment = 0;
			thisRuleActiv->SetBranchActivation(0, resetStats); // reset the rule

		}
		else {

			if((newStats.segment == current->NSegments()) && (newStats.subsegment == 0)) { // rule completed

				//std::cout << "rule " << rulenum << "has been completed ";
				thisRuleActiv->state = RuleInactive;
				thisRuleActiv->GetRule()->SetCompleted(true);
				RuleActivationStatus resetStats;
				resetStats.segment = 0;
				resetStats.subsegment = 0;
				thisRuleActiv->SetBranchActivation(0, resetStats); // reset the rule

			}
			else { // rule advanced one symbol

				thisRuleActiv->SetBranchActivation(0, newStats);

			}

		}
	
	}
	else {

		// process disjuntives

		
	}
	std::cout << "        <<<<<<<<<<<<<<<<<<<   this rule activation is after " << thisRuleActiv->GetBranchActivation(0).segment << " , " << thisRuleActiv->GetBranchActivation(0).subsegment << "\n";


}

int Engine::Step() {

	int skip;

	if(parser->HeadIsEmpty()) {
		//std::cout << "head was empty\n";
		// check short-cuts, makes parsing a lot faster
		skip = parser->ParserDetectStandardSpacers();
		if(skip > 0) {

			parser->AdvanceHead(skip);
			return PARSE_CONTINUE;

		}


		skip = parser->ParserDetectInteger();
		if(skip > 0) {

			//std::cout << "integer detected\n";

			// Datatype d;
			// d.SymbolID = SymbolTable::Builtin_Integer;
			// d.type = DT_SYMBOL;
			// parser->push(d);
		
			Symboltype s;
			s.symbol = SymbolTable::Builtin_Integer;
			//d.basic.int_val = 0; //atoi(parser->Extract().c_str());
			parser->AdvanceHead(skip);
			parser->SetSymbolAtHead(s);

			return PARSE_CONTINUE;

		}

		skip = parser->ParserDetectNonTerminal();
		if(skip > 0) {

			//std::cout << "non terminal detected\n";

			// Datatype d;
			// d.SymbolID = SymbolTable::Builtin_NonTerminal;
			// d.type = DT_SYMBOL;
			// parser->push(d);
		
			Symboltype s;
			s.symbol = SymbolTable::Builtin_NonTerminal;
			//d.basic.str_val = ""; //parser->Extract();
			parser->AdvanceHead(skip);
			parser->SetSymbolAtHead(s);

			return PARSE_CONTINUE;

		}

		// if all else fails...

		
		Symboltype s;
		s.symbol = SYMBOL_CHAR;
		s.c = parser->GetChar();
		//std::cout << "one boring char: "<<s.c<<"\n";
		parser->SetSymbolAtHead(s);
		parser->AdvanceHead(1);

		if(s.c == PARSER_EOB) return PARSE_END;
			else return PARSE_CONTINUE;
	}
	else {
		Symboltype s = parser->GetSymbolAtHead();
		if(s.symbol != -1) {
			//std::cout << "head was not empty and it contained a symbol:" << s.symbol << "\n";
		}
		else {
			//std::cout << "head was not empty and it contained the char '"<< s.c <<"'\n";	
		}
	}	

	// if parser head is not empty, or couldn't catch any of the shortcut cases, proceed here...
	//char c = parser->GetChar();

	for(int i = 0; i < state->NumRules(); ++i) {

		Rule *r = state->GetRule(i);
		AttemptAdvanceRule(i, parser->GetSymbolAtHead());
		if(r->IsCompleted()) {

			std::cout << " engine saw that rule "<< i <<" was completed\n";

			RuleExecution *re = new RuleExecution;
			re->f = r->onCompleted;
			re->dataseq = NULL;
			state->execute.push_back(re);
			r->SetCompleted(false);
		// 	r->onCompleted(r, this, 0);
		// 	Symboltype s;
		// 	s.symbol = r->GetSymbol();
		// 	parser->push(s);
		// 	Datatype d = r->GetData();
		// 	state->RemoveFromStack(r->GetIndex());
			Symboltype newSym;
			newSym.symbol = r->GetSymbol();
			newSym.c = ' ';
			parser->SetSymbolAtHead(newSym);
		 	return PARSE_CONTINUE;

		}
		

	}
	parser->ClearHead();

	return PARSE_CONTINUE;

}