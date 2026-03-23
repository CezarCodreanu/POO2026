#include "Complex.h"
#include <bits/stdc++.h>

// ─── Constructori ────────────────────────────────────────────────────────────

Complex::Complex() : real_data(0), imag_data(0) {}

Complex::Complex(double real, double imag) : real_data(real), imag_data(imag) {}

// ─── Metode ──────────────────────────────────────────────────────────────────

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

// op() - setter pentru real si imag, returneaza referinta (pentru chaining)
Complex& Complex::operator()(double real, double imag) {
    real_data = real;
    imag_data = imag;
    return *this;
}

// ─── op+ (9 variante: complex+complex, complex+real, real+complex) ───────────

Complex operator+(const Complex& l, const Complex& r) {
    return Complex(l.real() + r.real(), l.imag() + r.imag());
}

Complex operator+(const Complex& l, double r) {
    return Complex(l.real() + r, l.imag());
}

Complex operator+(double l, const Complex& r) {
    return Complex(l + r.real(), r.imag());
}

// ─── op- (3 variante binare + 1 unar) ────────────────────────────────────────

Complex operator-(const Complex& l, const Complex& r) {
    return Complex(l.real() - r.real(), l.imag() - r.imag());
}

Complex operator-(const Complex& l, double r) {
    return Complex(l.real() - r, l.imag());
}

Complex operator-(double l, const Complex& r) {
    return Complex(l - r.real(), -r.imag());
}

Complex operator-(const Complex& obj) {           // unar
    return Complex(-obj.real(), -obj.imag());
}

// ─── op* (3 variante) ────────────────────────────────────────────────────────
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

// ─── op== si op!= ────────────────────────────────────────────────────────────

bool operator==(const Complex& l, const Complex& r) {
    return l.real() == r.real() && l.imag() == r.imag();
}

bool operator!=(const Complex& l, const Complex& r) {
    return !(l == r);
}

// ─── op<< ────────────────────────────────────────────────────────────────────
// Format:  5 + 4i  |  -3 - 2i  |  -6  |  5i  |  0

std::ostream& operator<<(std::ostream& out, const Complex& c) {
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
            // scriem + sau - intre parti
            out << (c.imag() > 0 ? " + " : " - ");
            out << std::abs(c.imag()) << "i";
        } else {
            // doar partea imaginara
            out << c.imag() << "i";
        }
    }

    return out;
}

// ─── op++ si op-- ────────────────────────────────────────────────────────────
// Incrementeaza/decrementeaza PARTEA REALA

// prefix ++ : incrementeaza si returneaza referinta la obiectul modificat
Complex& Complex::operator++() {
    real_data++;
    return *this;
}

// postfix ++ : TREBUIE sa foloseasca prefix ++
Complex Complex::operator++(int) {
    Complex copy = *this;   // salvezi valoarea veche
    ++(*this);              // folosesti prefix ++
    return copy;            // returnezi valoarea veche
}

// prefix --
Complex& Complex::operator--() {
    real_data--;
    return *this;
}

// postfix -- : TREBUIE sa foloseasca prefix --
Complex Complex::operator--(int) {
    Complex copy = *this;
    --(*this);              // folosesti prefix --
    return copy;
}