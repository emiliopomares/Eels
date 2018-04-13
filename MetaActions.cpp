#include "StreamWriter.hpp"
#include "StreamReader.hpp"
#include "MetaActions.hpp"

void onAdditionComplete(Rule *r, Engine *e, int pass) {

	StreamWriter *out = e->GetStreamWriter();
	//Datatype op1 = r->body->GetElement(0)->GetData();
	//Datatype op2 = r->body->GetElement(2)->GetData();
	//int res = op1.basic.int_val + op2.basic.int_val;
	//out->WriteString(std::to_string(res));

}