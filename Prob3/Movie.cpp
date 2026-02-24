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

int Movie::getYear(){
    return this->year;
}

void Movie::set_score(const double s){
    this->score = s;
}

double Movie::getScore(){
    return this->score;
}

void Movie::set_length(const int m){
    this->min = m;
}

int Movie::getLength(){
    return this->min;
}

int Movie::getRelease(){
    int rel = 2026-this->year;
    return rel;
}

void MovieSeries::init(){
    this->n = 0;
}

void MovieSeries::addMovie(Movie* m){
    this->movies[this->n++] = m;
}

Movie* MovieSeries::getMovie(int i){
    return this->movies[i];
}

void MovieSeries::print(){
    for(int i = 0; i < this->n; i++){
        printf("%s (%d) - scorul: %.1f, lungime: %d minute\n", 
               this->movies[i]->getName(), 
               this->movies[i]->getYear(), 
               this->movies[i]->getScore(), 
               this->movies[i]->getLength());
    }
}





