#include "Number.h"
#include <bits/stdc++.h>


char Number::digitToChar(int d) {
    if (d < 10) return '0' + d;
    return 'A' + (d - 10);
}

int Number::charToDigit(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return 10 + (c - 'A');
    if (c >= 'a' && c <= 'f') return 10 + (c - 'a');
    return 0;
}

long long Number::toDecimal() const {
    long long result = 0;
    for (int i = 0; i < length; i++) {
        result = result * base + charToDigit(digits[i]);
    }
    return result;
}

void Number::fromDecimal(long long value, int newBase) {
    delete[] digits;
    base = newBase;

    if (value == 0) {
        digits = new char[2];
        digits[0] = '0';
        digits[1] = '\0';
        length = 1;
        return;
    }

    //ordinea inversa
    char temp[128];
    int  idx = 0;
    while (value > 0) {
        temp[idx++] = digitToChar((int)(value % newBase));
        value /= newBase;
    }

    // Inversam
    length = idx;
    digits = new char[length + 1];
    for (int i = 0; i < length; i++)
        digits[i] = temp[length - 1 - i];
    digits[length] = '\0';
}

//constr
Number::Number(const char* value, int b) : base(b) {
    length = (int)strlen(value);
    digits = new char[length + 1];
    for (int i = 0; i < length; i++)
        digits[i] = toupper(value[i]);
    digits[length] = '\0';
}

Number::Number(long long value, int b) : digits(nullptr), length(0), base(b) {
    fromDecimal(value, b);
}

Number::Number(const Number& other) : base(other.base), length(other.length) {
    digits = new char[length + 1];
    strcpy(digits, other.digits);
}

Number::Number(Number&& other) noexcept
    : digits(other.digits), length(other.length), base(other.base) {
    other.digits = nullptr;
    other.length = 0;
}

Number::~Number() {
    delete[] digits;
}

//pt atrb
Number& Number::operator=(const Number& other) {
    if (this == &other) return *this;
    delete[] digits;
    base   = other.base;
    length = other.length;
    digits = new char[length + 1];
    strcpy(digits, other.digits);
    return *this;
}

Number& Number::operator=(Number&& other) noexcept {
    if (this == &other) return *this;
    delete[] digits;
    digits = other.digits;
    length = other.length;
    base = other.base;
    other.digits = nullptr;
    other.length = 0;
    return *this;
}

Number& Number::operator=(long long value) {
    fromDecimal(value, base); //vom pastra baza, schimbam doar val
    return *this;
}

Number& Number::operator=(const char* value) {
    // la fel, string direct
    delete[] digits;
    length = (int)strlen(value);
    digits = new char[length + 1];
    for (int i = 0; i < length; i++)
        digits[i] = toupper(value[i]);
    digits[length] = '\0';
    return *this;
}

void Number::SwitchBase(int newBase) {
    long long val = toDecimal();
    fromDecimal(val, newBase);
}

void Number::Print() const {
    printf("(%s)_%d\n", digits, base);
}

int Number::GetDigitsCount() const { return length; }
int Number::GetBase()        const { return base;   }

//pt index
char Number::operator[](int index) const {
    return digits[index];
}

//compar
bool Number::operator>(const Number& other)  const { return toDecimal() >  other.toDecimal(); }
bool Number::operator<(const Number& other)  const { return toDecimal() <  other.toDecimal(); }
bool Number::operator>=(const Number& other) const { return toDecimal() >= other.toDecimal(); }
bool Number::operator<=(const Number& other) const { return toDecimal() <= other.toDecimal(); }
bool Number::operator==(const Number& other) const { return toDecimal() == other.toDecimal(); }
bool Number::operator!=(const Number& other) const { return toDecimal() != other.toDecimal(); }


Number& Number::operator--() {
    // vom sterge primu digit
    if (length <= 1) {
        fromDecimal(0, base);
        return *this;
    }
    char* newDigits = new char[length]; // length-1 cifre + '\0'
    strcpy(newDigits, digits + 1); // sare peste primul
    delete[] digits;
    digits = newDigits;
    length--;
    return *this;
}

Number Number::operator--(int) {
    // sterge ultimul digit
    Number copy = *this;
    if (length > 1) {
        digits[length - 1] = '\0';
        length--;
    } else {
        fromDecimal(0, base);
    }
    return copy;
}

//pt op +=
Number& Number::operator+=(const Number& other) {
    long long sum = toDecimal() + other.toDecimal();
    int newBase = (base > other.base) ? base : other.base;
    fromDecimal(sum, newBase);
    return *this;
}

//functiile friend 
Number operator+(const Number& a, const Number& b) {
    long long sum = a.toDecimal() + b.toDecimal();
    int newBase = (a.base > b.base) ? a.base : b.base;
    return Number(sum, newBase);
}

Number operator-(const Number& a, const Number& b) {
    long long diff = a.toDecimal() - b.toDecimal();
    int newBase = (a.base > b.base) ? a.base : b.base;
    if (diff < 0) diff = 0;  // numere fara semn
    return Number(diff, newBase);
}