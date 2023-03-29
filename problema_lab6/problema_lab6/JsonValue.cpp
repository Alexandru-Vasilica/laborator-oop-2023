#define _CRT_SECURE_NO_WARNINGS
#include "JsonValue.h"
#include <cstring>
JsonValue::~JsonValue(){
}
NumberValue::NumberValue(int x): value(x) {
}

void NumberValue::print(std::ostream& out) const {
    out << value;
}

StringValue::StringValue(const char* value) {
    string = new char[256];
    strcpy(string, value);
}

void StringValue::print(std::ostream& out) const {
    out << "\"" << string << "\"";
}

StringValue::~StringValue() {
    delete[] string;
}

BoolValue::BoolValue(bool x) {
    value = x;
}

void BoolValue::print(std::ostream& out) const {
    if (value)
        out << "true";
    else
        out << "false";
}

NullValue::NullValue() {
    value = new char[5];
    value = strcpy(value,"null");
}

void NullValue::print(std::ostream& out) const {
    out << value;
}

NullValue::~NullValue() {
    delete[] value;
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

void ArrayValue::print(std::ostream& out) const {
    out << "[";
    for (int i = 0; i < count; i++) {
        arr[i]->print(out);
        if (i!=count-1)
        out << ", ";
    }
    out << "]";
}

ArrayValue::~ArrayValue() {
    for (int i = 0; i < count; i++)
        delete[] arr[i];
    delete[] arr;
    count = 0;
}

void ObjectValue::print(std::ostream& out) const {
    out << "{";
    for (int i=0; i<count;i++) {
        out << "\""<<fieldnames[i] << "\": ";
        values[i]->print(out);
        if (i != count - 1)
        out << ", ";
    }
    out << "}";
}

ObjectValue::~ObjectValue() {
    for (int i=0;i<count;i++) {
        delete[] fieldnames[i];
        delete[] values[i];
    }
    delete fieldnames;
    delete values;
    count = 0;
}
