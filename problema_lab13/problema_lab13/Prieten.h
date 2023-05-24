#pragma once
#include <string>
#include "Contact.h"
#include<iostream>
#include"Types.h"
using namespace std;
class Prieten : public Contact {
  private:
    string phone_number;
    string date_of_birth;
    string adress;
  public:
    Prieten(string name, string phone_number,string date_of_birth,string adress);
    int get_type() const override;
    string get_phone_number() const;
    string get_date_of_birth() const;
    string get_adress() const;
    void print() const override;
};