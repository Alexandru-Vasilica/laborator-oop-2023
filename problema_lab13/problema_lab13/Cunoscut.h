#pragma once
#include<string>
#include "Contact.h"
#include"Types.h"
#include<iostream>
using namespace std;
class Cunoscut : public Contact {
  private:
    string phone_number;

  public:
    Cunoscut(string name, string phone_number);
    int get_type() const override;
    string get_phone_number() const;
    void print() const override;
};