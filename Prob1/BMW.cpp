#include "BMW.h"

const char* BMW::GetName() const {
    return "BMW";
}

int BMW::GetFuelCapacity() const {
    return 45;
}

int BMW::GetFuelConsumption() const {
    return 10;
}

int BMW::GetAverageSpeed(Weather w) const {
    if (w == Weather::Sunny) return 160;
    if (w == Weather::Rain) return 120;
    if (w == Weather::Snow) return 70;
    return 0;
}