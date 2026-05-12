#include <iostream>
#include "Array.h"
using namespace std;

class IntCompare : public Compare {
public:
    int CompareElements(void* e1, void* e2) override {
        int a = *(int*)e1;
        int b = *(int*)e2;
        if (a < b) return -1;
        if (a > b) return  1;
        return 0;
    }
};

int cmpInt(const int& a, const int& b) {
    if (a < b) return -1;
    if (a > b) return  1;
    return 0;
}

int main() {

    Array<int> arr(4);

    arr += 30;
    arr += 10;
    arr += 50;
    arr += 20;
    arr += 40;

    cout << "Marime:" << arr.GetSize() << " si capacitate=" << arr.GetCapacity() << endl;

    cout << "Elemente: ";
    for (auto it = arr.GetBeginIterator(); it != arr.GetEndIterator(); ++it)
        cout << it.GetElement() << " ";
    cout << endl;

    arr.Insert(2, 99);
    cout << "Elem dupa ce am inserat: ";
    for (int i = 0; i < arr.GetSize(); ++i)
        cout << arr[i] << " ";
    cout << endl;

    arr.Delete(2);
    cout << "Elem dupa ce am sters: ";
    for (int i = 0; i < arr.GetSize(); ++i)
        cout << arr[i] << " ";
    cout << endl;

    arr.Sort(cmpInt);
    cout << "Sortare normala: ";
    for (int i = 0; i < arr.GetSize(); ++i)
        cout << arr[i] << " ";
    cout << endl;

    int pos = arr.BinarySearch(30, cmpInt);
    cout << "Dupa cautare binara: " << pos << endl;

    pos = arr.Find(999);
    cout << "Gasit:" << pos << endl;

    IntCompare ic;
    arr.Sort(&ic);
    cout << "Sortare cu comparator: ";
    for (int i = 0; i < arr.GetSize(); ++i)
        cout << arr[i] << " ";
    cout << endl;

    Array<int> extra(2);
    extra += 100;
    extra += 200;
    arr.Insert(1, extra);
    cout << "Dupa Insert array la index 1: ";
    for (int i = 0; i < arr.GetSize(); ++i)
        cout << arr[i] << " ";
    cout << endl;

    Array<int> copy(arr);
    cout << "Copie: ";
    for (int i = 0; i < copy.GetSize(); ++i)
        cout << copy[i] << " ";
    cout << endl;

    cout << "\nPt exceptii" << endl;

    try {
        int x = arr[9999];
    } catch (exception& e) {
        cout << "operator[]: " << e.what() << endl;
    }

    try {
        arr.Insert(-5, 0);
    } catch (exception& e) {
        cout << "Insert cu index negativ: " << e.what() << endl;
    }

    try {
        arr.Delete(500);
    } catch (exception& e) {
        cout << "Delete cu index prea mare: " << e.what() << endl;
    }

    try {
        Array<int> empty;
        empty.Delete(0);
    } catch (exception& e) {
        cout << "Delete pe array gol: " << e.what() << endl;
    }

    try {
        Array<int> bad(-3);
    } catch (exception& e) {
        cout << "capacitate invalida: " << e.what() << endl;
    }

    try {
        auto it = arr.GetEndIterator();
        it.GetElement();
    } catch (exception& e) {
        cout << "GetElement pe end iterator: " << e.what() << endl;
    }

    return 0;
}