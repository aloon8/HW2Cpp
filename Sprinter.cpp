//
// Created by Admin on 19/05/2018.
//

#include "Sprinter.h"

int Sprinter::sprinterTime = 4;

/* Defining the sprinter's routes to be Yellow, and default stop time is 4 minutes */
Sprinter::Sprinter() : Vehicle(Color::Yellow){}

void Sprinter::print() const {
    cout << "Printing Sprinter !!!\n";
}
