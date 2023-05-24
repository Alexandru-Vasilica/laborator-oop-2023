#include "Coleg.h"

Coleg::Coleg(string name, string phone_number, string workplace, string adress) {
    this->name = name;
    this->phone_number = phone_number;
    this->workplace = workplace;
    this->adress = adress;
}

string Coleg::get_type() const {
    return "Coleg";
}
