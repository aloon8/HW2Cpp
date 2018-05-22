//
// Created by Admin on 19/05/2018.
//

#ifndef HW2_BUS_H
#define HW2_BUS_H


#include "Vehicle.h"

class Bus : public Vehicle {

public:
    Bus();

    void print() const ;

    static int busTime;

};


#endif //HW2_BUS_H
