//
// Created by Admin on 19/05/2018.
//

#ifndef HW2_SPRINTER_H
#define HW2_SPRINTER_H


#include "Vehicle.h"

class Sprinter : public Vehicle{

public:
    explicit Sprinter(int stopTime = 4);

    virtual void print() const;
};


#endif //HW2_SPRINTER_H
