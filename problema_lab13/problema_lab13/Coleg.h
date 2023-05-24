#pragma once
#include <string>
#include "Contact.h"
#include"Types.h"
#include<iostream>
using namespace std;
class Coleg : public Contact {
  private:
    string phone_number;
    string workplace;
    string adress;

  public:
    Coleg(string name, string phone_number, string workplace, string adress);
    int get_type() const override;
    string get_phone_number() const;
    string get_workplace() const;
    string get_adress() const;
    void print() const override;
};