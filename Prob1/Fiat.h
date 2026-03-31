#pragma once
#include "Car.h"

class Fiat : public Car {
public:
    int GetFuelCapacity() const override;
    int GetFuelConsumption() const override;
    int GetAverageSpeed(Weather w) const override;
    const char* GetName() const override;
};