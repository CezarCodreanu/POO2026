#include "Map.h"

int main() {
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";
    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    cout << "Nr elemente: " << m.Count() << endl;

    const char* val;
    if (m.Get(20, val))
        cout << "Cheia are valoarea: " << val << endl;
    if (!m.Get(99, val))
        cout << "Cheia nu exista" << endl;


    Map<int, const char*> m2;
    m2[10] = "ceva";
    m2[20] = "altceva";

    if (m2.Includes(m))
        cout << "da";
    else cout << "nu apartine";
    return 0;
}