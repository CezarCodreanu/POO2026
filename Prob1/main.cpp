#include <iostream>
#include "Math.h"

using namespace std;

int main() {
    cout << Math::Add(5, 5) << endl;
    cout << Math::Add(5, 5, 5) << endl;

    cout << Math::Add(2.5, 3.7) << endl;
    cout << Math::Add(1.2, 2.3, 3.4) << endl;

    cout << Math::Mul(4, 5) << endl;
    cout << Math::Mul(2, 3, 4) << endl;
    cout << Math::Mul(2.5, 2.0) << endl;
    cout << Math::Mul(1.5, 2.0, 3.0) << endl;

    cout << Math::Add(5, 10, 20, 30, 40, 50) << endl;

    char* fullName = Math::Add("C++ ", "Programming");
    if (fullName) {
        cout << fullName << endl;
        //delete[] fullName; //curat memoria
    }

    char* nullTest = Math::Add("Hello", nullptr);
    if (nullTest == nullptr) {
        cout << "este null";
    }

    return 0;
}