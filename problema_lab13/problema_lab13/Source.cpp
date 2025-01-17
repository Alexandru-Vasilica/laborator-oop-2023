#include<iostream>
#include"Prieten.h"
#include"Coleg.h"
#include"Cunoscut.h"
#include"Agenda.h"
#include"Types.h"
using namespace std;

int main() {
    Agenda contacte;
    Prieten *p1=new Prieten("A", "0122187", "01.02.2003", "Strada C");
    Prieten* p2 = new Prieten("C", "0122187", "02.02.2003", "Strada D");
    Coleg* c1 = new Coleg("B", "0122187", "undeva", "Strada E");
    Cunoscut* c2 = new Cunoscut("D", "01121231");
    contacte.add_contact(p1);
    contacte.add_contact(c1);
    contacte.add_contact(p2);
    contacte.add_contact(c2);

    contacte.find_name("B")->print();
    list<const Prieten*> prieteni = contacte.get_friends();
    cout << endl;
    for (auto it : prieteni)
        it->print();
    cout << endl;
    contacte.delete_contact("A");
    list<const Prieten*> prieteni2 = contacte.get_friends();
    for (auto it : prieteni2)
        it->print();
    return 0;
}