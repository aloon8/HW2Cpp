
//
// Created by Admin on 18/05/2018.
//

#ifndef HW2_STATION_H
#define HW2_STATION_H

struct Destinations {
    Station station;
    Color color;
    int weight;
};


#include <iostream>
using namespace std;
typedef enum StationType { InterCity , Stad , Central};

class Station {
public:
    Station(const string& stationType, int transitTime);

protected:
    StationType stationType;
    int transitTime;
};


#endif //HW2_STATION_H
