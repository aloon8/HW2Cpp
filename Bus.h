//
// Created by Admin on 19/05/2018.
//

#ifndef HW2_BUS_H
#define HW2_BUS_H


#include "Vehicle.h"

class Bus : public Vehicle {

public:
    explicit Bus(int stopTime = 2);

    void print() const override;

};


#endif //HW2_BUS_H
