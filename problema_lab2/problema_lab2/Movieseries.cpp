#include "Movieseries.h"
#include <stdio.h>
void MovieSeries::init() {
    count = 0;
}

void MovieSeries::add(Movie* m) {
    if (count < 16) {
        movies[count] = m;
        count++;
    }
}

void MovieSeries::print() {
    for (int i = 0; i < count; i++)
        printf(
              "%s score:%f release:%d length:%d years passed:%d \n",
              movies[i]->get_name(),
              movies[i]->get_score(),
              movies[i]->get_year(),
              movies[i]->get_length(),
              movies[i]->get_passed_years());
}

void MovieSeries::sort() {
    for (int i = 0; i < count; i++)
        for (int j = i + 1; j < count; j++)
            if (movies[i]->get_passed_years() < movies[j]->get_passed_years()) {
                Movie* aux;
                aux = movies[i];
                movies[i] = movies[j];
                movies[j] = aux;
            }
}

