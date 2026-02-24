#include <bits/stdc++.h>
#include "Movie.h"

using namespace std;

void Movie::set_name(const char* n){
    strcpy(this->nume, n);
}

char* Movie::getName(){
    return this->nume;
}

void Movie::set_year(const int y){
    this->year = y;
}

int* getYear(){
    return this->year;
}


