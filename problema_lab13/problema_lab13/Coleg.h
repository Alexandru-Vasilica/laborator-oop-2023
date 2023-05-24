#pragma once
#include <string>
#include "Contact.h"
using namespace std;
class Coleg : public Contact {
  private:
    string phone_number;
    string workplace;
    string adress;

  public:
    Coleg(string name, string phone_number, string workplace, string adress);
    string get_type() const override;
};