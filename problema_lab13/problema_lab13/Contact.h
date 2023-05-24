#pragma once
#include<string>
using namespace std;
class Contact {
  public:
    string name;
    Contact() {  }
    virtual string get_type() const=0;

};