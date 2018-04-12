#include "StateNode.hpp"
#include "StreamReader.hpp"
#include "StreamWriter.hpp"
#include <string>

#define PARSE_OK 0
#define PARSE_CONTINUE 2
#define PARSE_EOS -1

class Engine {
	
public:
	StateNode *state;
	SymbolTable *symTable;

	Parser *parser;
	StreamWriter *out;

	void Initialize(StreamReader *strin, StreamWriter *strout);
	void FillInMetaRules();

	void AttachReader(StreamReader *r);
	void AttachWriter(StreamWriter *w);

	int Process();

	std::string GetError();
	int GetErrorCode();

private:
	int Step();
	int line;
	std::string error;
	int errorCode;

}