//
// Created by Admin on 19/05/2018.
//

#ifndef HW2_RAIL_H
#define HW2_RAIL_H


#include "Vehicle.h"

class Rail : public Vehicle{
public:
    Rail();

    static int railTime;

    virtual void print() const;

};


#endif //HW2_RAIL_H
