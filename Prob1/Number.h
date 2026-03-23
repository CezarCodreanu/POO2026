#pragma once
#include <cstring>
#include <cstdio>
#include <cctype>

class Number {
private:
    char* digits;
    int   length;
    int   base;

    long long   toDecimal() const;
    void        fromDecimal(long long value, int newBase);
    static char digitToChar(int d);
    static int  charToDigit(char c);

public:
    // Constructori
    Number(const char* value, int base);
    Number(long long value, int base = 10);   // pentru n4=12345 si n1=255
    Number(const Number& other);              // copy
    Number(Number&& other) noexcept;          // move
    ~Number();

    // Operatori de atribuire
    Number& operator=(const Number& other);
    Number& operator=(Number&& other) noexcept;
    Number& operator=(long long value);       // n1 = 255
    Number& operator=(const char* value);     // n4 = "13579"

    // Metode
    void SwitchBase(int newBase);
    void Print() const;
    int  GetDigitsCount() const;
    int  GetBase() const;

    // Operator index
    char operator[](int index) const;

    // Operatori de comparatie
    bool operator>(const Number& other)  const;
    bool operator<(const Number& other)  const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;
    bool operator!=(const Number& other) const;

    // Operator --
    Number& operator--();         // prefix  (sterge primul digit)
    Number  operator--(int);      // postfix (sterge ultimul digit)

    // Operator +=
    Number& operator+=(const Number& other);

    // Friend: adunare si scadere
    friend Number operator+(const Number& a, const Number& b);
    friend Number operator-(const Number& a, const Number& b);
};