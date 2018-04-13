#include <iostream>
#include "ConsoleStreamWriter.hpp"

ConsoleStreamWriter::ConsoleStreamWriter() {


}

void ConsoleStreamWriter::PutChar(char c) {

	std::cout << c;

}

int ConsoleStreamWriter::PutChars(char *b) {

	std::cout << new std::string(b);
	return strlen(b);

}

void ConsoleStreamWriter::PutInt(int i) {

	std::cout << i;

}

void ConsoleStreamWriter::PutString(std::string s) {

	std::cout << s;

}

void ConsoleStreamWriter::PutFloat(float f) {

	std::cout << f;

}

void ConsoleStreamWriter::PutDouble(double d) {

	std::cout << d;

}

void ConsoleStreamWriter::PutBool(bool b) {

	std::cout << b;

}

void ConsoleStreamWriter::Flush() {


}