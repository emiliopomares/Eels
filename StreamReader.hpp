#ifndef STREAMREADER_DEF
#define STREAMREADER_DEF

#define STREAM_EOS 0

class StreamReader {

public:
	virtual char GetChar() = 0;
	virtual char GetCharAt(int offset) = 0;
	virtual int GetChars(int count, char *buffer) = 0;
	virtual void Rewind() = 0;
	virtual void Seek(int offset) = 0;
	virtual int Length() = 0;

};

#endif