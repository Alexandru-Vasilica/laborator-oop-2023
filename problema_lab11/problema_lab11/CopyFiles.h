#pragma once
#include<fstream>
#include<stdio.h>
struct CopyFiles {
    FILE *fin, *fout;
    CopyFiles(string in, string out) {
        fin = fopen(in.c_str(), "rb+");
        if (fin != NULL)
            fout = fopen(out.c_str(), "wb+");
        else
            fout = NULL;
    }
    ~CopyFiles() {
        if (fin!=NULL)
        fclose(fin);
        if (fout!=NULL)
        fclose(fout);
    }
    
};