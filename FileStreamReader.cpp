#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "FileStreamReader.hpp"

FileStreamReader::FileStreamReader(FILE *f) {

	fseek(f, 0L, SEEK_END);
	long sz = ftell(f);
	rewind(f);

	data = (char *)std::malloc(sz);
	size = fread(data, 1, sz, f);
	offset = 0;
	fclose(f);

}

FileStreamReader::FileStreamReader(char *fname) {

	FILE *f = fopen(fname, "rb");
	if(f!=NULL) {
		fseek(f, 0L, SEEK_END);
		long sz = ftell(f);
		rewind(f);


		data = (char *)std::malloc(sz);
		size = fread(data, 1, sz, f);	
		offset = 0;
		fclose(f);
	}

}


char FileStreamReader::GetChar() {

	if(offset < size) {
		
		return data[offset++];

	}
	else return STREAM_EOS;

}


char FileStreamReader::GetCharAt(int off) {

	if(off < size) {
		
		//std::cout << "GetCharAt: " << off << " = " << data[off] << "\n";
		return data[off];

	}
	else return STREAM_EOS;

}

int FileStreamReader::GetChars(int count, char *buffer) {

	if(offset < (size-count)) {

		for(int i = 0; i < count; ++i) {

			buffer[i] = data[offset++];

		}
		return count;

	}
	else {

		int actualCount = (size-1-offset);
		for(int i = 0; i < actualCount; ++i) {

			buffer[i] = data[offset++];

		}
		return actualCount;

	}


}


void FileStreamReader::Rewind() {

	offset = 0;

}

void FileStreamReader::Seek(int ofst) {

	offset = ofst;

}

int FileStreamReader::Length() {

	return size;

}