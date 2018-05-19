
//
// Created by Admin on 18/05/2018.
//

#include "Station.h"

Station::Station(Station::StationType stationType, const string &stationName, int transitTime) :
stationType(stationType), stationName(stationName), transitTime(transitTime){}

Station::StationType Station::getStationType() const {
    return stationType;
}

const string &Station::getStationName() const {
    return stationName;
}


int Station::getTransitTime() const {
    return transitTime;
}
