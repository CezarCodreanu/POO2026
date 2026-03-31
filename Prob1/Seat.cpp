#include "Seat.h"

int Seat::GetFuelCapacity() const { 
    return 50; 
}
int Seat::GetFuelConsumption() const { 
    return 5; 
} 

int Seat::GetAverageSpeed(Weather w) const {
    if (w == Weather::Sunny) return 110;
    if (w == Weather::Rain) return 90;
    if (w == Weather::Snow) return 60;
    return 0;
}

const char* Seat::GetName() const { 
    return "Seat"; 
}