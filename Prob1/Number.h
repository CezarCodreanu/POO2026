#pragma once
#include <cstring>
#include <cstdio>
#include <cctype>

class Number {
private:
    char* digits;
    int length;
    int base;

    long long toDecimal() const;
    void fromDecimal(long long value, int newBase);
    static char digitToChar(int d);
    static int  charToDigit(char c);

public:
    // constr
    Number(const char* value, int base);
    Number(long long value, int base = 10); // pt n4=12345 si n1=255
    Number(const Number& other); // copy
    Number(Number&& other) noexcept; // move
    ~Number(); //deconstr

    // pt atribuire
    Number& operator=(const Number& other);
    Number& operator=(Number&& other) noexcept;
    Number& operator=(long long value); // n1 = 255
    Number& operator=(const char* value); // n4 = "13579"

    // metode
    void SwitchBase(int newBase);
    void Print() const;
    int  GetDigitsCount() const;
    int  GetBase() const;

    // pt index
    char operator[](int index) const;

    // pt comparatie
    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;
    bool operator!=(const Number& other) const;

    //pt operatori
    Number& operator--(); //prefix,sterge primul digit
    Number  operator--(int); //postfix, sterge ultimul digit

    // pt op +=
    Number& operator+=(const Number& other);

    //friend pt adunare/scadere
    friend Number operator+(const Number& a, const Number& b);
    friend Number operator-(const Number& a, const Number& b);
};