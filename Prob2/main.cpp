#include <bits/stdc++.h>
#include "global.h"

using namespace std;

int main(){
    Student st1, st2;

    st1.setNume("Andrei");
    st1.setMate(9); st1.setEng(10); st1.setIst(8);

    st2.setNume("Bogdan");
    st2.setMate(7); st2.setEng(9); st2.setIst(10);

    cout << "Nume:" << st1.getNume() << ", media: " << st1.getAvg() << endl;
    cout << "Nume:" << st2.getNume() << ", media: " << st2.getAvg() << endl;

    cout << "Comparam numele:" << compNume(st1, st2) << endl;
    cout << "Comparam mediile:" << compAvg(st1, st2) << endl;

    return 0;
}