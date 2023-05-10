#pragma once
#include<exception>
struct AllocExcept : std::exception {
    const char* what() const noexcept override {
        return "Didn't specify an argument";
    }
};
