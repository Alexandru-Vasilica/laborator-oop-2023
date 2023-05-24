#pragma once
#include<string>
#include"Types.h"
using namespace std;
class Contact {
  protected:
    string name;

  public:
    Contact() {  }
    virtual int get_type() const;
    virtual string get_name() const;
    virtual void print() const = 0;
};