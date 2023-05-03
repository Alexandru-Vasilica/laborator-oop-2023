#include "Episode.h"
#include<iostream>
using namespace std;
Episode::Episode(vector<string> column) {
    title = column[0];
    date = column[1];
    length = column[2];
    viewersmm = column[3];
    score = column[4];
}