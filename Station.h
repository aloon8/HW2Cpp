
//
// Created by Admin on 18/05/2018.
//

#ifndef HW2_STATION_H
#define HW2_STATION_H



#include <iostream>
using  namespace std;


class Station {
public:
    typedef enum  { InterCity , Stad , Central} StationType;

    Station(StationType stationType,const string& stationName);

    virtual void print() const = 0; // Abstract Class

    StationType getStationType() const;

    const string &getStationName() const;


protected:
    StationType stationType;

    string stationName;
};


#endif //HW2_STATION_H
