#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <cstdarg>
#include <cstring>
#include <cstdlib>
int Math::Add(int a, int b) {
    return a + b;
}

int Math::Add(int a, int b, int c) {
    return a+b+c;
}

int Math::Add(double a, double b) {
    double sum = a + b;
    return (int)sum;
}

int Math::Add(double a, double b, double c) {
    double sum = a + b + c;
    return (int)sum;
}

int Math::Mul(int a, int b) {
    return a*b;
}

int Math::Mul(int a, int b, int c) {
    return a*b*c;
}

int Math::Mul(double a, double b) {
    int prod = a * b;
    return (int)prod;
}

int Math::Mul(double a, double b, double c) {
    int prod =  a *  b *  c;
    return (int)prod;
}

int Math::Add(int count, ...) {
    int sum = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count;i++) {
        int num = va_arg(args, int);
        sum += num;
    }
    va_end(args);
    return sum;
}

char* Math::Add(const char* a, const char* b) {
    if (a == nullptr or b == nullptr)
        return nullptr;
    char* c = (char*) malloc(sizeof(a) + sizeof(b));
    strcpy(c, a);
    strcat(c,b);
    return c;
}
