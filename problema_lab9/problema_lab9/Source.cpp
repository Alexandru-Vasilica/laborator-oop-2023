#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <cstring>
#include <utility>
#include<fstream>

using namespace std;

struct Prio {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.second < b.second)
            return 1;
        else if (a.second == b.second)
            if (a.first > b.first)
                return 1;
        return 0;
    }
};

int main() {
    ifstream fin("Text.txt");
    string s;
    getline(fin, s);
    map<string, int> cuv;
    string sep = " ?!,.";
    priority_queue<pair<string, int>, deque<pair<string, int>>, Prio> sorted;
    int pos=s.find_first_not_of(sep);
    if (pos != string::npos)
        s.erase(0, pos);
    else
        return 0;
    while ((pos = s.find_first_of(sep)) != string::npos) {
        string word = s.substr(0, pos);
        s.erase(0, pos + 1);
        for (int i = 0; i < word.size(); i++)
            if (word[i] >= 'A' && word[i] <= 'Z')
                word[i] = word[i] - 'A' + 'a';
        cuv[word]++;
        int pos2 = s.find_first_not_of(sep);
        s.erase(0, pos2);
    }
    if (!s.empty())
        cuv[s]++;
    map<string, int>::iterator it;
    for (it = cuv.begin(); it != cuv.end(); it++) {
        pair<string, int> p = *it;
        sorted.push(p);
    }
    while (!sorted.empty()) {
        cout << sorted.top().first << "=>" << sorted.top().second << endl;
        sorted.pop();
    }
    return 0;
}