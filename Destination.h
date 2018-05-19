//
// Created by Admin on 19/05/2018.
//

#ifndef HW2_DESTINATION_H
#define HW2_DESTINATION_H


#include "Station.h"
#include "Vehicle.h"
#include <memory>


class Destination {
public:
    shared_ptr<Station> station;
    Vehicle vehicle;
    int weight;
};


#endif //HW2_DESTINATION_H
