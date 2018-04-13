#include <iostream>
#include "FileStreamReader.hpp"
#include "ConsoleStreamWriter.hpp"

int main(int argc, char **argv) {

	ConsoleStreamWriter *w = new ConsoleStreamWriter();
	FileStreamReader *r = new FileStreamReader(argv[1]);

	int exitTrance = 30;
	char c = r->GetChar();
	while(c != STREAM_EOS) {

		char d = (c-1);
		w->PutChar(d);
		c = r->GetChar();
		--exitTrance;
		if(exitTrance == 0) return 0;

	}

	
	return 0;

}
