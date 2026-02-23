#include <bits/stdc++.h>
#include "global.h"

using namespace std;

int compNume(Student& st1, Student& st2){
    int ok = strcmp(st1.getNume(), st2.getNume());
    if(ok == 0) return 0;
    else if(ok == 1) return 1;
    else return -1;
}

int compMate(Student& st1, Student& st2){
    if(st1.getMate() == st2.getMate()) return 0;
    return (st1.getMate() > st1.getMate()) ? 1 : -1;
}

int compEng(Student& st1, Student& st2){
    if(st1.getEng() == st2.getEng()) return 0;
    return (st1.getEng() > st1.getEng()) ? 1 : -1;
}

int compIst(Student& st1, Student& st2){
    if(st1.getIst() == st2.getIst()) return 0;
    return (st1.getIst() > st1.getIst()) ? 1 : -1;
}

float compAvg(Student& st1, Student& st2){
    float a = st1.getAvg(), b = st2.getAvg();
    if(a == b)
        return 0;
    return (a > b) ? 1 : -1;
}

