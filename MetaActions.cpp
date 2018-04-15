#include "StreamWriter.hpp"
#include "StreamReader.hpp"
#include "MetaActions.hpp"

void onAdditionComplete(DataSequence *d, Engine *e, int pass) {

	StreamWriter *out = e->GetStreamWriter();
	out->PutString("Addition executed\n");
	//Datatype op1 = r->body->GetElement(0)->GetData();
	//Datatype op2 = r->body->GetElement(2)->GetData();
	//int res = op1.basic.int_val + op2.basic.int_val;
	//out->WriteString(std::to_string(res));

}

void onSubstractionComplete(DataSequence *d, Engine *e, int pass) {

	StreamWriter *out = e->GetStreamWriter();
	out->PutString("Substraction executed\n");

}