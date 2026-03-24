#include "Complex.h"
#include <bits/stdc++.h>

using namespace std;

//constr
Complex::Complex() : real_data(0), imag_data(0) {}

Complex::Complex(double real, double imag) : real_data(real), imag_data(imag) {}

//met
bool Complex::is_real() const {
    return imag_data == 0;
}

double Complex::real() const { return real_data; }
double Complex::imag() const { return imag_data; }

double Complex::abs() const {
    return sqrt(real_data * real_data + imag_data * imag_data);
}

Complex Complex::conjugate() const {
    return Complex(real_data, -imag_data);
}

// setam real si img, returnand referinta
Complex& Complex::operator()(double real, double imag) {
    real_data = real;
    imag_data = imag;
    return *this;
}

//mai multe variante pt op +
Complex operator+(const Complex& l, const Complex& r) {
    return Complex(l.real() + r.real(), l.imag() + r.imag());
}

Complex operator+(const Complex& l, double r) {
    return Complex(l.real() + r, l.imag());
}

Complex operator+(double l, const Complex& r) {
    return Complex(l + r.real(), r.imag());
}

//la fel si pt op -
Complex operator-(const Complex& l, const Complex& r) {
    return Complex(l.real() - r.real(), l.imag() - r.imag());
}

Complex operator-(const Complex& l, double r) {
    return Complex(l.real() - r, l.imag());
}

Complex operator-(double l, const Complex& r) {
    return Complex(l - r.real(), -r.imag());
}

Complex operator-(const Complex& obj) { // unar
    return Complex(-obj.real(), -obj.imag());
}

// (a+bi)(c+di) = ac-bd + (ad+bc)i
Complex operator*(const Complex& l, const Complex& r) {
    return Complex(
        l.real() * r.real() - l.imag() * r.imag(),
        l.real() * r.imag() + l.imag() * r.real()
    );
}

Complex operator*(const Complex& l, double r) {
    return Complex(l.real() * r, l.imag() * r);
}

Complex operator*(double l, const Complex& r) {
    return Complex(l * r.real(), l * r.imag());
}

//pt op == si !=
bool operator==(const Complex& l, const Complex& r) {
    return l.real() == r.real() && l.imag() == r.imag();
}

bool operator!=(const Complex& l, const Complex& r) {
    return !(l == r);
}

//pt op <<
ostream& operator<<(ostream& out, const Complex& c) {
    bool hasReal = c.real() != 0;
    bool hasImag = c.imag() != 0;

    if (!hasReal && !hasImag) {
        out << 0;
        return out;
    }

    if (hasReal) {
        out << c.real();
    }

    if (hasImag) {
        if (hasReal) {
            // + sau - intre parti
            out << (c.imag() > 0 ? " + " : " - ");
            out << abs(c.imag()) << "i";
        } else {
            // pt imaginara
            out << c.imag() << "i";
        }
    }

    return out;
}

//pt partea reala de ++/--
Complex& Complex::operator++() {
    real_data++;
    return *this; //returnam ref la obiectul modif
}

Complex Complex::operator++(int) {
    Complex copy = *this; //val veche
    ++(*this);              
    return copy; // returnam val veche
}

Complex& Complex::operator--() {
    real_data--;
    return *this; // la fel pt partea reala la --
}

Complex Complex::operator--(int) {
    Complex copy = *this;
    --(*this);             
    return copy; //la fel, copiem val veche
}