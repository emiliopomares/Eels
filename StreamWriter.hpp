#include <string>

class StreamWriter {

public:
	void PutChar(char c);
	void PutInt(int i);
	void PutString(std::string s);
	void PutFloat(float f);
	void PutDouble(double d);
	void PutBool(bool b);
	void flush();	

};