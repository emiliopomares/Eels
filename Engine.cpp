#include <iostream>

#include "Segment.hpp"
#include "Sequence.hpp"
#include "MetaActions.hpp"
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
	while(r!=PARSE_EOS) {

		r = Step();

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

	std::cout << "new Engine created\n";

}

int Engine::Step() {

	int skip;

	if(parser->HeadIsEmpty()) {
		// check short-cuts, makes parsing a lot faster
		skip = parser->DetectInteger();
		if(skip > 0) {

			Datatype d;
			d.SymbolID = SymbolTable::Builtin_Integer;
			d.type = DT_SYMBOL;
			parser->push(d);
		

			d.type = DT_INT;
			d.basic.int_val = 0; //atoi(parser->Extract().c_str());
			parser->SetValueAtHead(d);

			return PARSE_CONTINUE;

		}

		skip = parser->DetectNonTerminal();
		if(skip > 0) {

			Datatype d;
			d.SymbolID = SymbolTable::Builtin_NonTerminal;
			d.type = DT_SYMBOL;
			parser->push(d);
		
			d.type = DT_STRING;
			d.basic.str_val = ""; //parser->Extract();
			parser->SetValueAtHead(d);

			return PARSE_CONTINUE;

		}

		// if all else fails...

		
		Datatype d;
		d.SymbolID = SymbolTable::Builtin_Char;
		d.type = DT_SYMBOL;
		d.basic.char_val = parser->GetChar();
		parser->push(d);

		return PARSE_CONTINUE;
	}

	// if parser head is not empty, or couldn't catch any of the shortcut cases, proceed here...
	//char c = parser->GetChar();

	for(int i = 0; i < state->NumRules(); ++i) {

		Rule *r = state->GetRule(i);
		r->AttemptAdvance(parser->GetSymbol());
		if(r->IsCompleted()) {

			r->onCompleted(r, this, 0);
			parser->push(r->GetSymbol());
			Datatype d = r->GetData();
			state->RemoveFromStack(r->GetIndex());

			return PARSE_CONTINUE;

		}

	}

	return PARSE_CONTINUE;

}