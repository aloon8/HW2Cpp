//
// Created by Admin on 19/05/2018.
//

#ifndef HW2_SPRINTER_H
#define HW2_SPRINTER_H


#include "Vehicle.h"

class Sprinter : public Vehicle{

public:
    Sprinter();

    virtual void print() const;

    static int sprinterTime;
};


#endif //HW2_SPRINTER_H
