
//
// Created by Admin on 18/05/2018.
//

#include "Station.h"

Station::Station(Station::StationType stationType, const string &stationName) :stationType(stationType), stationName(stationName){}

Station::StationType Station::getStationType() const {
    return stationType;
}

const string &Station::getStationName() const {
    return stationName;
}

