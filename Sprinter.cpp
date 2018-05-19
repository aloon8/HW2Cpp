//
// Created by Admin on 19/05/2018.
//

#include "Sprinter.h"


/* Defining the sprinter's routes to be Yellow, and default stop time is 4 minutes */
Sprinter::Sprinter(int stopTime) : Vehicle(stopTime,Color::Yellow){}

void Sprinter::print() const {
    cout << "Printing Sprinter !!!\n";
}
