#include "Segment.hpp"
#include "Sequence.hpp"
#include "Datatype.hpp"

void Engine::FillInMetaRules() {

	//int sym = symTable->RegisterSymbol("rule");
	//state->AddRule(sym);
	//state->AddSegment(Segment::CreateNonTerminal());
	//state->AddSegment(Segment::CreateLiteral(":="));
	//state->

	// test stuff, remove later: let's make it just an adding machine for now
	int sym = symTable->RegisterSymbol("addition");
	state->AddRule(sym);
	state->AddSegment(Segment::Integer());
	state->AddSegment(Segment::Literal("+"));
	state->AddSegment(Segment::Integer());

	Action *act = new Action();
	act->AddOp(Action::Plus);
	act->AddParam(0, 0);
	act->AddParam(1, 2);
	act->AddOp(Action::Print);
	act->AddParam(0);
	state->AddAction(act);

}

void Engine::Initialize(StreamReader *strin, StreamWriter *strout) {

	state = new StateNode();
	symTable = new SymbolTable();
	FillInMetaRules();

	parser = new Parser(strin);
	out = strout;

}

void Engine::Process() {

	int r;
	r = Step();
	while(r!=PARSER_EOS) {

		r = Step();

	}

}

int Engine::Step() {

	int skip;

	if(parser->HeadIsEmpty()) {
		// check short-cuts, makes parsing a lot faster
		skip = parser->DetectInteger();
		if(skip > 0) {

			parser->push(SymbolTable::Builtin_Integer);
			Datatype d;
			d.type = DT_INT;
			d.basic.int_val = atoi(parser->Extract());
			parser->SetValueAtHead(d);

			return PARSE_CONTINUE;

		}

		skip = parser->DetectNonTerminal();
		if(skip > 0) {

			parser->push(SymbolTable::Builtin_NonTerminal);
			Datatype d;
			d.type = DT_STRING;
			d.basic.str_val = new String(parser->Extract());
			parser->SetValueAtHead(d);

			return PARSE_CONTINUE;

		}

		// if all else fails...
		parser->push(SymbolTable::Builtin_Char);
		Datatype d;
		d.type = DT_CHAR;
		d.basic.char_val = parser->GetChar();

		return PARSE_CONTINUE;
	}

	// if parser head is not empty, or couldn't catch any of the shortcut cases, proceed here...
	//char c = parser->GetChar();

	for(int i = 0; i < state->NumRules(); ++i) {

		Rule *r = state->GetRule(i);
		r->AttemptAdvance(parser->GetSymbol());
		if(r->IsCompleted()) {

			parser->push(r->GetSymbol());
			Datatype d = r->GetData();
			state->RemoveFromStack(r->GetIndex());

			return PARSE_CONTINUE;

		}

	}

}