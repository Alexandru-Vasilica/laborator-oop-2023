#include "Prieten.h"

Prieten::Prieten(string name, string phone_number, string date_of_birth, string adress) {
    this->name = name;
    this->phone_number = phone_number;
    this->date_of_birth = date_of_birth;
    this->adress = adress;
}

string Prieten::get_type() const {
    return "Prieten";
}
