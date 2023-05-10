#define _CRT_SECURE_NO_WARNINGS
#include"CommandManager.h"
#include<fstream>
#include<stdio.h>
#include"FileExcept.h"
#include"CopyFiles.h"
#include"AllocExcept.h"
int main() {
    CommandManager manager;

    auto ping = [](vector<string> args) { printf("pong!\n"); };
    manager.add("ping", ping);

    auto count = [](vector<string> args) { int nr = 0;
        for (auto s : args)
            nr++;
        printf("counted %d args\n", nr);
    };
    manager.add("count", count);

    auto times = [count=0](vector<string> args) mutable { 
       count++;
        printf("times called %d times\n", count);
    };
    manager.add("times", times);

    auto copy = [](vector<string> args) { 
      
   
            if (args.size()<1)
                throw FileExcept("input file", "didn't specify");
            if (args.size() < 2)
                throw FileExcept("output file", "didn't specify");
            CopyFiles f(args[0], args[1]);
            if (f.fin == NULL) {
                throw FileExcept(args[0], "couldn't open");
            }
            if (f.fout == NULL) {
                throw FileExcept(args[1], "couldn't open");
            }
                
            char c;
            while (!feof(f.fin)) {
                int count=fread(&c, 1, 1, f.fin);
                
                if (count)
                fwrite(&c, 1, 1, f.fout);
            }
            printf("Copy finished successfully!\n");
      
    };
     manager.add("copy", copy);
    auto alloc = [](vector<string> args) { 
        if (args.empty())
            throw AllocExcept{};
        int size=stoi(args[0]);
        new int[size][200000000]; // works for size<=75 and size>=0
         printf("Memory allocated successfully!\n");
    };
     manager.add("alloc", alloc);

    manager.run();

    printf("goodbye.\n");
}