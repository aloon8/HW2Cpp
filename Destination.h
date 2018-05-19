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
    Destination(shared_ptr<Station> station, shared_ptr<Vehicle> vehicle, int weight);

    const shared_ptr<Station> &getStation() const;

    void setStation(const shared_ptr<Station> &station);

    const shared_ptr<Vehicle> &getVehicle() const;

    void setVehicle(const shared_ptr<Vehicle> &vehicle);

    int getWeight() const;

    void setWeight(int weight);

private:
    shared_ptr<Station> station;
    shared_ptr<Vehicle> vehicle;
    int weight;
};


#endif //HW2_DESTINATION_H
