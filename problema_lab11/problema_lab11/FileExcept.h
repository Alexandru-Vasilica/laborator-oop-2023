#pragma once
#include<exception>
struct FileExcept : std::exception {
    string err;
    FileExcept(string file,string text) 
        {
        err= text;
        err = err + " ";
        err = err + file;
    
    }
    const char* what() const noexcept override {
       
        return err.c_str();
    }

};