//
// Created by Admin on 19/05/2018.
//

#include "Bus.h"

int Bus::busTime = 2;

/* Defining the bus's routes to be Blue, and default stop time is 2 minutes */
Bus::Bus() : Vehicle(Color::Blue) {}


void Bus::print() const {
    std::cout << "Printing bus\n";
}

