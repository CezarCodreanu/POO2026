#pragma once
#include "Car.h"

class Circuit {
    private:
        int length;
        Weather w;
        Car* cars[100];
        int carCount;

        Car* finishedCars[100];
        Car* notFinishedCars[100];
        int finishedCount = 0;
        int notFinishedCount = 0;
        
    public:
        Circuit();
        ~Circuit();

        void SetLength(int value);
        void SetWeather(Weather w);
        void AddCar(Car* model);
        void Race();
        void ShowFinalRanks();
        void ShowWhoDidNotFinish();
};