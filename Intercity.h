//
// Created by Admin on 18/05/2018.
//

#ifndef HW2_INTERCITY_H
#define HW2_INTERCITY_H

#include <iostream>
#include "Station.h"

using namespace std;

class Intercity: public Station {
public:
    Intercity(StationType stationType, const string& stationName, int transitTime = 15);

    void print() const override;

};


#endif //HW2_INTERCITY_H
