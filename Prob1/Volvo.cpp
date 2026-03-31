#include "Volvo.h"

int Volvo::GetFuelCapacity() const { 
    return 60; 
}
int Volvo::GetFuelConsumption() const { 
    return 6; 
} 

int Volvo::GetAverageSpeed(Weather w) const {
    if (w == Weather::Sunny) return 120;
    if (w == Weather::Rain) return 90;
    if (w == Weather::Snow) return 60;
    return 0;
}

const char* Volvo::GetName() const { 
    return "Volvo"; 
}