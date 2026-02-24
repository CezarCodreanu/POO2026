#include <bits/stdc++.h>
#include "NumberList.h"

using namespace std;

//Init, Add, Sort, Printl

int main(){
    NumberList lista;
    lista.Init();

    lista.Add(10);
    lista.Add(3);
    lista.Add(8);
    lista.Add(6);
    lista.Add(5);
    lista.Print();

    lista.Sort();
    lista.Print();

    return 0;
}