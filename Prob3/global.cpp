#include <bits/stdc++.h>
#include "global.h"

using namespace std;

int movie_compare_name(Movie& m1, Movie& m2){
    int ok = strcmp(m1.getName(), m2.getName());
    if(ok == 0) return 0;
    else if(ok == 1) return 1;
    else return -1;
}

int movie_compare_year(Movie& m1, Movie& m2){
    if(m1.getYear() == m2.getYear()) return 0;
    return (m1.getYear() > m2.getYear()) ? 1 : -1;
}

int movie_compare_score(Movie& m1, Movie& m2){
    if(m1.getScore() == m2.getScore()) return 0;
    return (m1.getScore() > m2.getScore()) ? 1 : -1;
}

int movie_compare_length(Movie& m1, Movie& m2){
    if(m1.getLength() == m2.getLength()) return 0;
    return (m1.getLength() > m2.getLength()) ? 1 : -1;
}

int movie_compare_passed_years(Movie& m1, Movie& m2){
    if(m1.getRelease() == m2.getRelease()) return 0;
    return (m1.getRelease() > m2.getRelease()) ? 1 : -1;
}

void MovieSeries::sortByRelease(){
    for(int i = 0; i < this->n-1; i++){
        for(int j = 0; j < this->n-i-1; j++){
            if(movie_compare_passed_years(*this->movies[j], *this->movies[j+1]) == 1){
                swap(this->movies[j], this->movies[j+1]);
            }
        }
    }
}