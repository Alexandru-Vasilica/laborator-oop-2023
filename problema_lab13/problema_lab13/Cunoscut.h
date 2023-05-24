#pragma once
#include<string>
#include "Contact.h"
using namespace std;
class Cunoscut : public Contact {
  private:
    string phone_number;

  public:
    Cunoscut(string name, string phone_number);
    string get_type() const override;
};