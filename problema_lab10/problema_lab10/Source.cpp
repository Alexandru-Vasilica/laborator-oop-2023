#include<iostream>
#include<fstream>
#include"CsvReader.h"
#include<vector>
#include"Episode.h"
#include<queue>
#include<utility>
#include<map>
class Prio_score {
  public:
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        
        if (a.second < b.second)
            return 1;
        else if (a.second == b.second)
            if (a.first > b.first)
                return 1;
        return 0;
    }
};
class Prio_length {
  public:
    bool operator()(const pair<string, string>& a, const pair<string, string>& b) const {
       
        int poz = a.second.find(':');
        int length1 = 60*stoi(a.second.substr(0, poz)) + stoi(a.second.substr(poz + 1, a.second.size() - 1));
         poz = b.second.find(':');
        int length2 = 60*stoi(b.second.substr(0, poz)) + stoi(b.second.substr(poz + 1, b.second.size() - 1));
        if (length1 < length2)
            return 1;
        else if (a.second == b.second)
            if (a.first > b.first)
                return 1;
        return 0;
    }
};
int main() {
    std::ifstream input_file("episodes.csv");
    if (!input_file.is_open()) {
        printf("File couldn't be opened\n");
        return 1;
    }
    CsvReader reader(input_file);

    std::vector<Episode> episodes;
    for (std::vector<std::string> columns : reader) {
        Episode to_add(columns);
        episodes.push_back(to_add);
    }

    printf("number of episodes: %zu\n\n", episodes.size());

    std::ofstream output_file("output.txt");
    for (auto& [title, date, length, viewersmm, score] : episodes) {
        output_file << title << "          " << date << "          " << length << "          " << viewersmm << "          " << score << endl;
    }
    priority_queue < pair<string, int>, vector<pair<string, int>>, Prio_score> topscore;
    priority_queue<pair<string,string>, vector<pair<string, string>>, Prio_length> toplength;
    map<string, int> years;
    for (auto& [title, date, length, viewersmm, score] : episodes) {
        int scorenum = stoi(score);
        pair<string, int> pairscore = { title, scorenum };
        pair<string, string> pairlength = { title, length };
        string year = date.substr(0, date.find_first_of("-"));
        years[year]++;
        toplength.push(pairlength);
        topscore.push(pairscore);
    }
    int max = 0;
    string max_year;
    for (auto it:years) {
        if (it.second>max) {
            max_year = it.first;
            max = it.second;
        }
    }
    int i = 1;
    cout << "The most appreciated episodes:" << endl;
    while (!topscore.empty() && i<=10) {
        auto entry = topscore.top();
        cout << i << ". " << entry.second << " -> "<< entry.first << " " << endl;
        topscore.pop();
        i++;
    }
    cout << endl;
    i = 1;
    cout << "The longest episodes:" << endl;
    while (!toplength.empty() && i<=10) {
        auto entry = toplength.top();
        cout << i << ". " << entry.second << " -> " << entry.first << " " << endl;
        toplength.pop();
        i++;
    }
    cout << endl;
    cout << "The year " << max_year << " has the most episodes: "<<max<< endl;
}