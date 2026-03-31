#include "Fiat.h"

int Fiat::GetFuelCapacity() const { 
    return 40; 
} 
int Fiat::GetFuelConsumption() const { 
    return 4; 
}

int Fiat::GetAverageSpeed(Weather w) const {
    if (w == Weather::Sunny) return 100;
    if (w == Weather::Rain) return 80;
    if (w == Weather::Snow) return 50;
    return 0;
}

const char* Fiat::GetName() const { 
    return "Fiat"; 
}