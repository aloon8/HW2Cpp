//
// Created by Admin on 19/05/2018.
//

#ifndef HW2_TRAM_H
#define HW2_TRAM_H


#include "Vehicle.h"



/*Derived class of Vehicle, is a vehicle in the public transport */
class Tram : public Vehicle{

public:

    Tram();

    static int tramTime;

    void print() const ;

    virtual VehicleType getVehicleType();

private:


};


#endif //HW2_TRAM_H
