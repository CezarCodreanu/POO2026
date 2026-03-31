#include "RangeRover.h"

int RangeRover::GetFuelCapacity() const { 
    return 100; 
}
int RangeRover::GetFuelConsumption() const { 
    return 14; 
} 

int RangeRover::GetAverageSpeed(Weather w) const {
    if (w == Weather::Sunny) return 130;
    if (w == Weather::Rain) return 110;
    if (w == Weather::Snow) return 90; 
    return 0;
}

const char* RangeRover::GetName() const { 
    return "Range Rover"; 
}