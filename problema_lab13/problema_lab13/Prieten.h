#pragma once
#include <string>
#include "Contact.h"
using namespace std;
class Prieten : public Contact {
  private:
    string phone_number;
    string date_of_birth;
    string adress;
  public:
    Prieten(string name, string phone_number,string date_of_birth,string adress);
    string get_type() const override;
};