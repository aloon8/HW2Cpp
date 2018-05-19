//
// Created by Admin on 19/05/2018.
//

#include "Bus.h"

/* Defining the bus's routes to be Blue, and default stop time is 2 minutes */
Bus::Bus(int stopTime) : Vehicle(stopTime, Color::Blue) {}


void Bus::print() const {
    std::cout << "Printing bus\n";
}

