#include "Cunoscut.h"

Cunoscut::Cunoscut(string name, string phone_number) {
    this->name = name;
    this->phone_number = phone_number;
}

int Cunoscut::get_type() const {
    return CUNOSCUT;
}

string Cunoscut::get_phone_number() const {
    return phone_number;
}

void Cunoscut::print() const {
    cout << "Cunoscut: " << name << " " << phone_number << endl;
}
