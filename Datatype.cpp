#include "Datatype.hpp"

Field InvalidField;

/// will leave *dest untouched if cannot get value
void Datatype::GetValue(void *dest) {

	if(type == DT_INT) *((int *)dest) = basic.int_val;
	else if(type == DT_FLOAT) *((float *)dest) = basic.float_val;
	else if(type == DT_DOUBLE) *((double *)dest) = basic.double_val;
	else if(type == DT_CHAR) *((char *)dest) = basic.char_val;
	else if(type == DT_BOOL) *((bool *)dest) = basic.bool_val;

}

/// will leave *dest untouched if cannot get field
Field Datatype::GetField(std::string name) {

	for(int i = 0; i < fields.size(); ++i) {

		if(fields[i].name == name) {

			return fields[i];

		}

	}

	return InvalidField;

}

Field Datatype::GetField(int n) {

	if(fields.size() > n) return fields[n];

	return InvalidField;

}

int Datatype::NumFields() {

	return fields.size();

}