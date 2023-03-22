#include "complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}



bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag) {
    real_data = real;
    imag_data = imag;
    return *this;
}

Complex& Complex::operator++() {
    real_data+=1;
    return *this;
}

Complex Complex::operator++(int) {
    Complex result = *this;
    ++(*this);
    return result;
}

Complex& Complex::operator--() {
    real_data -= 1;
    return *this;
}

Complex Complex::operator--(int) {
    Complex result = *this;
    --(*this);
    return result;
}

Complex operator+(const Complex& l, const Complex& r) {
   
    double real_part = l.real() + r.real();
    double imag_part = l.imag() + r.imag();
    Complex result(real_part,imag_part);
    return result;
}

Complex operator+(const Complex& l, double r) {

    Complex result(r,0);
    result = l + result;
    return result;
}

Complex operator+(double l, const Complex& r) {
    Complex result(l, 0);
    result = r + result;
    return result;
}

Complex operator-(const Complex& l, const Complex& r) {
    double real_part = l.real() - r.real();
    double imag_part = l.imag() - r.imag();
    Complex result(real_part, imag_part);
    return result;
}

Complex operator-(const Complex& l, double r) {
    Complex result(r, 0);
    result = l - result;
    return result;
}

Complex operator-(double l, const Complex& r) {
    Complex result(l, 0);
    result = result-r;
    return result;
}

Complex operator*(const Complex& l, const Complex& r) {
    double real_part = (l.real() * r.real()) - (l.imag()*r.imag());
    double imag_part = l.real()*r.imag()+l.imag()*r.real();
    Complex result(real_part, imag_part);
    return result;
}

Complex operator*(const Complex& l, double r) {
    Complex result(r, 0);
    result = l * result;
    return result;
}

Complex operator*(double l, const Complex& r) {
    Complex result(l, 0);
    result = r * result;
    return result;
}

Complex operator-(const Complex& obj) {
    double real_part = obj.real()*(-1);
    double imag_part = obj.imag() * (-1);
    Complex result(real_part, imag_part);
    return result;
}

bool operator==(const Complex& l, const Complex& r) {
    return ((l.real() == r.real()) and (l.imag() == r.imag()));
}

bool operator!=(const Complex& l, const Complex& r) {
    return !(l == r);
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    if (complex.real() != 0) {
        out << complex.real() << " ";
        if (complex.imag() > 0)
            out << "+"
                << " ";
    }
    if (complex.imag() != 0)
        out << complex.imag() << "i";
    return out;
}

