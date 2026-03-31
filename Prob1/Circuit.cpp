#include "Circuit.h"
#include <stdio.h>

Circuit::Circuit() {
    this->carCount = 0;
    this->finishedCount = 0;
    this->notFinishedCount = 0;
}

Circuit::~Circuit() {
    for (int i = 0; i < carCount; i++) {
        delete cars[i];
    }
}

void Circuit::SetLength(int value) {
    this->length = value;
}

void Circuit::SetWeather(Weather w) {
    this->w = w;
}

void Circuit::AddCar(Car* model) {
    if (carCount < 100) {
        cars[carCount++] = model;
    }
}

void Circuit::Race() {
    finishedCount = 0;
    notFinishedCount = 0;

    for (int i = 0; i < carCount; i++) {
        Car* currentCar = cars[i];
        
        float fuelNeeded = (this->length / 100.0f) * currentCar->GetFuelConsumption();
        
        if (currentCar->GetFuelCapacity() >= fuelNeeded) {
            finishedCars[finishedCount++] = currentCar;
        } else {
            notFinishedCars[notFinishedCount++] = currentCar;
        }
    }

    // timp = distanta / viteza
    for (int i = 0; i < finishedCount - 1; i++) {
        for (int j = 0; j < finishedCount - i - 1; j++) {
            
            float timeA = (float)length / finishedCars[j]->GetAverageSpeed(this->w);
            float timeB = (float)length / finishedCars[j+1]->GetAverageSpeed(this->w);
            
            if (timeA > timeB) {
                Car* temp = finishedCars[j];
                finishedCars[j] = finishedCars[j+1];
                finishedCars[j+1] = temp;
            }
        }
    }
}

void Circuit::ShowFinalRanks() {
    printf("Scor final: \n");
    if (finishedCount == 0) {
        printf("Nu a terminat nimeni!\n");
        return;
    }

    for (int i = 0; i < finishedCount; i++) {
        float time = (float)length / finishedCars[i]->GetAverageSpeed(this->w);
        printf("%d. %s - Timp: %.2f ore\n", i + 1, finishedCars[i]->GetName(), time);
    }
    printf("\n");
}

void Circuit::ShowWhoDidNotFinish() {
    printf("Nu au terminat: \n");
    if (notFinishedCount == 0) {
        printf("Toti au terminat cursa!\n");
        return;
    }

    for (int i = 0; i < notFinishedCount; i++) {
        printf("- %s (Ramas fara combustibil)\n", notFinishedCars[i]->GetName());
    }
    printf("\n");
}