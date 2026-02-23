#include <bits/stdc++.h>
#include "Student.h" 

void Student::setNume(const char* n){
    strcpy(this->nume, n);
}

char* Student::getNume(){
    return this->nume;
}

void Student::setMate(float nota){
    if(nota >= 1 && nota <= 10) 
        nMate = nota;
}

float Student::getMate(){
    return nMate;
}

void Student::setEng(float nota){
    if(nota >= 1 && nota <= 10) 
        nEng = nota;
}

float Student::getEng(){
    return nEng;
}

void Student::setIst(float nota){
    if(nota >= 1 && nota <= 10) 
        nIst = nota;
}

float Student::getIst(){
    return nIst;
}

float Student::getAvg(){
    return (nMate + nEng + nIst) / 3.0;
}



