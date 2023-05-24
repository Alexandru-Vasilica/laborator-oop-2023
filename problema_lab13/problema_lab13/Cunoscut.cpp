#include "Cunoscut.h"

Cunoscut::Cunoscut(string name, string phone_number) {
    this->name = name;
    this->phone_number = phone_number;
}

string Cunoscut::get_type() const {
    return "Cunoscut";
}
