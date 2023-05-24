#include "Coleg.h"

Coleg::Coleg(string name, string phone_number, string workplace, string adress) {
    this->name = name;
    this->phone_number = phone_number;
    this->workplace = workplace;
    this->adress = adress;
}

int Coleg::get_type() const {
    return COLEG;
}

string Coleg::get_phone_number() const {
    return phone_number;
}

string Coleg::get_workplace() const {
    return workplace;
}

string Coleg::get_adress() const {
    return adress;
}

void Coleg::print() const {
    cout << "Coleg: " << name << " " << phone_number << " " << workplace << " " << adress << endl;
}
