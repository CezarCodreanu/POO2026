#pragma once
#include "Weather.h"

class Car {
    public:
        virtual ~Car() {};

        virtual int GetFuelConsumption() const = 0;
        virtual int GetFuelCapacity() const = 0;
        virtual int GetAverageSpeed(Weather w) const = 0;
        virtual const char* GetName() const = 0;
};