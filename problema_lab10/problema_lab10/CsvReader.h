#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class CsvIterator {
    vector<string> column;
    string line;
    ifstream& input;

  public:
    CsvIterator(string text, ifstream& fin);
    bool operator!=(CsvIterator& other);
    CsvIterator& operator++();
    vector<string> operator*();
};
class CsvReader {
    ifstream &input;
  public:
    CsvReader(ifstream& file);
    CsvIterator begin();
    CsvIterator end();
};
