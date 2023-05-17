#pragma once
#include<exception>
struct EmptyQueueExcept : std::exception {
    const char* what() const noexcept override {
        return "Can't perform operation: the queue is empty!";
    }
};