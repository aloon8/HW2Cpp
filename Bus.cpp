//
// Created by Admin on 19/05/2018.
//

#include "Bus.h"

int Bus::busTime = 2;//default stop time is 2 minutes


Bus::Bus() : Vehicle(VehicleType::Bus) {} // inheriting from Vehicle


void Bus::print() const {
    std::cout << "Printing bus\n";
}

Vehicle::VehicleType Bus::getVehicleType() { // returns bus type
    return VehicleType::Bus;
}

