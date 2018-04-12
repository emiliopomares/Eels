#include <stdio.h>
#include "StreamReader.h"

StreamReader::StreamReader(FILE *f) {

	fseek(f, 0L, SEEK_END);
	long sz = ftell(f);
	rewind(f);

	data = (char *)malloc(sz);
	size = fread(data, 1, sz, f);
	offset = 0;
	fclose(f);

}

char StreamReader::Get() {

	if(offset < size) {

		data[offset++];

	}
	else return EOF;

}

void StreamReader::Rewind() {

	offset = 0;

}

void StreamReader::Seek(int ofst) {

	offset = ofst;

}

int StreamReader::Length() {

	return size;

}