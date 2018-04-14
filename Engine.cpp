#include <iostream>

#include "Segment.hpp"
#include "Sequence.hpp"
#include "MetaActions.hpp"
#include "StateNode.hpp"
#include "Symboltype.hpp"
#include "Datatype.hpp"

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
//======================== TEST ==========================



}

Rule *Engine::AddRule(int sym) {

	Rule *newRule = new Rule();
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
	int max = 5;
	while(r!=PARSE_END) {

	 	r = Step();
	 	--max;
	 	if(max == 0) return 0;

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

void Engine::AttemptAdvanceRule(int rulenum, Symboltype s) {

	RuleActivation *act = state->GetActivation(rulenum);
	Rule *rule = rules[rulenum];

	int dis = rule->GetBody()->NDisjuntives();

	if(dis == 1) {


	
	}
	else {



		
	}


}

int Engine::Step() {

	int skip;

	if(parser->HeadIsEmpty()) {
		//std::cout << "head was empty\n";
		// check short-cuts, makes parsing a lot faster
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
			std::cout << "head was not empty and it contained a symbol:" << s.symbol << "\n";
		}
		else {
			std::cout << "head was not empty and it contained the char '"<< s.c <<"'\n";	
		}
	}	

	// if parser head is not empty, or couldn't catch any of the shortcut cases, proceed here...
	//char c = parser->GetChar();

	for(int i = 0; i < state->NumRules(); ++i) {

		Rule *r = state->GetRule(i);
		// AttemptAdvanceRule(i, parser->GetSymbolAtHead());
		// if(r->IsCompleted()) {

		// 	r->onCompleted(r, this, 0);
		// 	Symboltype s;
		// 	s.symbol = r->GetSymbol();
		// 	parser->push(s);
		// 	Datatype d = r->GetData();
		// 	state->RemoveFromStack(r->GetIndex());

		// 	return PARSE_CONTINUE;

		// }
		parser->ClearHead();

	}

	return PARSE_CONTINUE;

}