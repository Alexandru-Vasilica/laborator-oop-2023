#include "Prieten.h"

Prieten::Prieten(string name, string phone_number, string date_of_birth, string adress) {
    this->name = name;
    this->phone_number = phone_number;
    this->date_of_birth = date_of_birth;
    this->adress = adress;
}

int Prieten::get_type() const {
    return PRIETEN;
}

string Prieten::get_phone_number() const {
    return phone_number;
}

string Prieten::get_date_of_birth() const {
    return date_of_birth;
}

string Prieten::get_adress() const {
    return adress;
}

void Prieten::print() const {
    cout << "Prieten: " << name << " " << phone_number << " " << date_of_birth << " " << adress << endl;
}
