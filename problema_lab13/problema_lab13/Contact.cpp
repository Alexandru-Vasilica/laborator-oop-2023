#include "Contact.h"

int Contact::get_type() const {
    return CONTACT;
}

string Contact::get_name() const {
    return name;
}