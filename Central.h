//
// Created by Admin on 19/05/2018.
//

#ifndef HW2_CENTRAL_H
#define HW2_CENTRAL_H


#include "Station.h"

class Central : public Station{
public:
    Central(const string& stationName,StationType stationType = StationType::Central);

    static int centralTime;

    void print() const ;
};


#endif //HW2_CENTRAL_H
