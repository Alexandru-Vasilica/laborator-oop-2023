#define _CRT_SECURE_NO_WARNINGS
#include "CommandManager.h"
#include<iostream>
void CommandManager::add(string name, function<void(vector<string>)> fn) {
    commands[name]=fn;
}

void CommandManager::run() {
    string text;
    vector<string> args;

    while (true) {
        printf("\n");

        std::getline(std::cin, text);
        args.clear();
        int pos;
       while ((pos = text.find_first_of(" ")) != string::npos) {
            string word = text.substr(0, pos);
          
            text.erase(0, pos + 1);
            args.push_back(word);
            int pos2 = text.find_first_not_of(" ");
            text.erase(0, pos2);
        }
       if (!text.empty()) {
            args.push_back(text);
       }

        if (args.empty()) {
            continue;
        }

        string command = args[0];
        if (command == "stop") {
            return;
        }
        auto it = commands.find(command);
        if (it == commands.end()) {
            printf("no command with the name: %s\n", command.c_str());
            continue;
        }

        args.erase(args.begin());

        try {
            it->second(args);
        } catch (std::exception& e) {
            fprintf(stderr, "command `%s` failed: %s\n", command.c_str(), e.what());
        }
    }
}
