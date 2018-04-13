#include "SymbolTable.hpp"

int SymbolTable::RegisterSymbol(std::string s) {
	
	entry.push_back(s);
	return entry.size()+255;

}