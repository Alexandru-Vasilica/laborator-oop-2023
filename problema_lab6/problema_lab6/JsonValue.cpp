#define _CRT_SECURE_NO_WARNINGS
#include "JsonValue.h"
#include <cstring>
JsonValue::~JsonValue(){
}
NumberValue::NumberValue(int x): value(x) {
}

void NumberValue::print(std::ostream& out) {
    out << value;
}

StringValue::StringValue(const char* value) {
    string = new char[256];
    strcpy(string, value);
}

void StringValue::print(std::ostream& out) {
    out << string;
}

BoolValue::BoolValue(bool x) {
    value = x;
}

void BoolValue::print(std::ostream& out) {
    out << value;
}

NullValue::NullValue() {
    value = new char[5];
    value = strcpy(value,"null");
}

void NullValue::print(std::ostream& out) {
    out << value;
}

ObjectValue::ObjectValue(): count(0){
    values = new JsonValue*[16];
    fieldnames = new char*[16];
}

ObjectValue::operator unsigned() {
    return count;
}


void ObjectValue::add(const char* name, JsonValue* value) {
    fieldnames[count] = new char[256];
    strcpy(fieldnames[count], name);
    values[count] = value;
    count++;
}


void ArrayValue::add(JsonValue* value) {
    arr[count] =value;
    count++;
}

ArrayValue::ArrayValue() : count(0) {
    arr = new JsonValue*[16];

}

void ArrayValue::print(std::ostream& out) {
    for (int i = 0; i < count; i++) {
        arr[i]->print(out);
        out << " ";
    }
    out << "\n";
}

void ObjectValue::print(std::ostream& out) {
    for (int i=0; i<count;i++) {
        out << fieldnames[i] << " ";
        values[i]->print(out);
        out << " ";
    }
    out << "\n";
}