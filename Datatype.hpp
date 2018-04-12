#include <vector>
#include <string>

enum Datatype_e { DT_INT, DT_STRING, DT_BOOL, DT_FLOAT, DT_DOUBLE, DT_CHAR, DT_COMPOUND };

union BasicDatatype {

	std::string str_val;
	int	int_val;
	float float_val;
	bool bool_val;
	char char_val;

};

struct SelectionRange {

	int startOffset;
	int endOffset;

};

class Datatype;

struct Field {

	std::string name;
	Datatype value;

};

extern Field InvalidField;

class Datatype {

public:
	Datatype_e type;
	SelectionRange selectionRange;
	BasicDatatype basic;
	std::vector<Field> fields;

	void GetValue(void *dest);
	Field GetField(std::string name);
	Field GetField(int n);
	int NumFields();

};