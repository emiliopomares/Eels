#ifndef CONSOLESTREAMWRITER_DEF
#define CONSOLESTREAMWRITER_DEF

#include "StreamWriter.hpp"

class ConsoleStreamWriter : public StreamWriter {

public:
	ConsoleStreamWriter();
	virtual void PutChar(char c); 
	virtual int PutChars(char *b);
	virtual void PutInt(int i);
	virtual void PutString(std::string s);
	virtual void PutFloat(float f);
	virtual void PutDouble(double d);
	virtual void PutBool(bool b);
	virtual void Flush();

};

#endif