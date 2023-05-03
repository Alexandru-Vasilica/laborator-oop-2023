#pragma once
#include <string>
#include<vector>
using namespace std;
struct Episode {
    string title;
    string date;
    string length;
    string viewersmm;
    string score;
    Episode(vector<string> column);
};