#ifndef SYMTABLE_DEF
#define SYMTABLE_DEF

#include <vector>
#include <string>

class SymbolTable {

public:
	std::vector<std::string> entry;
	int RegisterSymbol(std::string s);

	const static int Builtin_Integer = 0;
	const static int Builtin_NonTerminal = 1;
	const static int Builtin_Char = 2;


};

#endif