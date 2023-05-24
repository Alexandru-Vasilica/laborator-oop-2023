#pragma once
#include"Prieten.h"
#include"Coleg.h"
#include"Cunoscut.h"
#include<vector>
#include<list>
using namespace std;
class Agenda {
  private:
    vector<Contact*> Contacte;

  public:
    Contact* find_name(string name);
    list<const Prieten*> get_friends();
    void delete_contact(string name);
    void add_contact(Contact* c);
};