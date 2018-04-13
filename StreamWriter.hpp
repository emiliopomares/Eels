#ifndef STREAMWRITER_DEF
#define STREAMWRITER_DEF

#include <string>

class StreamWriter {

public:
	virtual void PutChar(char c) = 0; 
	virtual int PutChars(char *b) = 0;
	virtual void PutInt(int i) = 0;
	virtual void PutString(std::string s) = 0;
	virtual void PutFloat(float f) = 0;
	virtual void PutDouble(double d) = 0;
	virtual void PutBool(bool b) = 0;
	virtual void Flush() = 0;	

};

#endif