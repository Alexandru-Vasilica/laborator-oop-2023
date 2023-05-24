#include "Agenda.h"

Contact* Agenda::find_name(string name) {
    for (auto it : Contacte)
        if (it->name == name)
            return it;
    return nullptr;
}

 list<const Prieten*> Agenda::get_friends() {
    list<const Prieten*> friends;
    for (auto it : Contacte)
        if (it->get_type() == "Prieten")
            friends.push_back(reinterpret_cast<const Prieten*>(it));
    return friends;
}

void Agenda::delete_contact(string name) {
    for (int i = 0; i < Contacte.size(); i++)
        if (Contacte[i]->name == name) {
            Contacte.erase(Contacte.begin() + i);
            return;
        }
}

void Agenda::add_contact(Contact* c) {
    Contacte.push_back(c);
}
