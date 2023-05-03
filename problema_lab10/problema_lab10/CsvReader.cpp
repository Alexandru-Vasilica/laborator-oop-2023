#include "CsvReader.h"

CsvReader::CsvReader(ifstream& file):input(file){
    
}

CsvIterator CsvReader::begin() {
    string s;
    input.seekg(0, input.beg);
    getline(input, s);
    CsvIterator linie(s,input);
    return linie;
}

CsvIterator CsvReader::end() {
     string s;
    CsvIterator linie(s,input);
    return linie;
}

CsvIterator::CsvIterator(string text, ifstream& fin) : line(text),input(fin) {
   
}

bool CsvIterator::operator!=(CsvIterator& other) {

    return line != other.line;
    
}

CsvIterator& CsvIterator::operator++() {
    getline(input, line);
   
    return (*this);
}

vector<string> CsvIterator::operator*() {
    vector<string> column;
    for (int i = 0; i < 5; i++) {
        if (line[0] == '\"') {
            line = line.erase(0, 1);
            int poz = line.find_first_of("\"");
            column.push_back(line.substr(0, poz));
            line = line.erase(0, poz + 2);
        } else {
            int poz = line.find_first_of(",");
            column.push_back(line.substr(0, poz));
            line = line.erase(0, poz + 1);
        }
    }
        return column;

}
