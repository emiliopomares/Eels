#ifndef SYMTABLE_DEF
#define SYMTABLE_DEF

#include <vector>
#include <string>

class SymbolTable {

public:
	std::vector<std::string> entry;
	int RegisterSymbol(std::string s);

	const static int Builtin_Integer = 1024;
	const static int Builtin_NonTerminal = 1025;
	const static int Builtin_Char = 1026;


};

#endif