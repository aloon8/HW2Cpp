//
// Created by Admin on 19/05/2018.
//

#ifndef HW2_CENTRAL_H
#define HW2_CENTRAL_H


#include "Station.h"

class Central : public Station{
public:
    Central(StationType stationType, const string& stationName, int transitTime = 5);

    void print() const override;
};


#endif //HW2_CENTRAL_H
