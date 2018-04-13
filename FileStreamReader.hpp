#ifndef FILESTREAMREADER_DEF
#define FILESTREAMREADER_DEF

#include <stdio.h>
#include <string>
#include "StreamReader.hpp"

class FileStreamReader : public StreamReader {

public:
	FileStreamReader(FILE *f);
	FileStreamReader(char* fname);
	virtual char GetChar();
	virtual char GetCharAt(int offset);
	virtual int GetChars(int count, char *buffer);
	virtual void Rewind();
	virtual void Seek(int offset);
	virtual int Length();

private:
	char *data;
	long size;
	long offset;

};

#endif