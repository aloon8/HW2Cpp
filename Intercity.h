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
    Intercity(const string& stationType, int transitTime, const string& stationName);

private:
string name;
};


#endif //HW2_INTERCITY_H
