//
// Created by Admin on 19/05/2018.
//

#include "Tram.h"


int Tram::tramTime = 3;//default stop time is 3 minutes


Tram::Tram() : Vehicle(Vehicle::VehicleType::Tram) {}

void Tram::print() const {

}

Vehicle::VehicleType Tram::getVehicleType() { // returns a representation of itself in the enum
    return VehicleType::Tram;
}
