#pragma once
#include <ostream>

class Complex {
private:
    double real_data;
    double imag_data;
public:
    Complex();
    Complex(double real, double imag);
    bool    is_real()    const;
    double  real()       const;
    double  imag()       const;
    double  abs()        const;
    Complex conjugate()  const;
    Complex& operator()(double real, double imag);

    // ++ si -- (modifica partea reala)
    Complex& operator++();       // prefix
    Complex  operator++(int);    // postfix
    Complex& operator--();       // prefix
    Complex  operator--(int);    // postfix
};

// op+ (3 variante)
Complex operator+(const Complex& l, const Complex& r);
Complex operator+(const Complex& l, double r);
Complex operator+(double l,         const Complex& r);

// op- (3 variante binare + 1 unar)
Complex operator-(const Complex& l, const Complex& r);
Complex operator-(const Complex& l, double r);
Complex operator-(double l,         const Complex& r);
Complex operator-(const Complex& obj);

// op* (3 variante)
Complex operator*(const Complex& l, const Complex& r);
Complex operator*(const Complex& l, double r);
Complex operator*(double l,         const Complex& r);

// comparatie
bool operator==(const Complex& l, const Complex& r);
bool operator!=(const Complex& l, const Complex& r);

// stream
std::ostream& operator<<(std::ostream& out, const Complex& c);