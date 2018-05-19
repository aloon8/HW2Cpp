//
// Created by Admin on 19/05/2018.
//

#include "Destination.h"


Destination::Destination(shared_ptr<Station> station, shared_ptr<Vehicle> vehicle, int weight) :
        station(station), vehicle(vehicle), weight(weight) {}


const shared_ptr<Station> &Destination::getStation() const {
    return station;
}

void Destination::setStation(const shared_ptr<Station> &station) {
    Destination::station = station;
}

const shared_ptr<Vehicle> &Destination::getVehicle() const {
    return vehicle;
}

void Destination::setVehicle(const shared_ptr<Vehicle> &vehicle) {
    Destination::vehicle = vehicle;
}

int Destination::getWeight() const {
    return weight;
}

void Destination::setWeight(int weight) {
    Destination::weight = weight;
}

