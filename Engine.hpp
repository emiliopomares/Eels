#ifndef ENGINE_DEF
#define ENGINE_DEF

#include "StateNode.hpp"
#include "StreamReader.hpp"
#include "StreamWriter.hpp"
#include "SymbolTable.hpp"
#include "Parser.hpp"
#include <string>

#define PARSE_OK 0
#define PARSE_CONTINUE 2
#define PARSE_EOS -1

class StateNode;
class Rule;

class Engine {
	
public:
	StateNode *state;
	SymbolTable *symTable;

	Parser *parser;
	
	Engine(StreamReader *strin, StreamWriter *strout);

	Rule *AddRule(int sym);

	int NumRules();
	Rule *GetRule(int idx);

	void Initialize();
	void FillInMetaRules();

	void AttachReader(StreamReader *r);
	void AttachWriter(StreamWriter *w);

	int Process();

	std::string GetError();
	int GetErrorCode();

	StreamWriter *GetStreamWriter();

private:
	StreamWriter *out;
	std::vector<Rule *> rules;
	int Step();
	int line;
	std::string error;
	int errorCode;

};

#endif