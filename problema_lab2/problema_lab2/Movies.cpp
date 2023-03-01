#define _CRT_SECURE_NO_WARNING
#include "Movies.h"
#include <cstring>

void Movie::set_name(const char* name) {
    strcpy_s(this->name,name);
    
}

void Movie::set_score(double x) {
    if (x >= 1 and x <= 10)
        score = x;
}

void Movie::set_year(int x) {
    release = x;
}

void Movie::set_length(int x) {
    length = x;
}

const char* Movie::get_name() {

    return name;
}

double Movie::get_score() {
    return score;
}

int Movie::get_year() {

    return release;
}

int Movie::get_length() {
    return length;
}
int Movie::get_passed_years() {
    return 2023 - release;
}
