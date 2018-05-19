//
// Created by Admin on 19/05/2018.
//

#ifndef HW2_STAD_H
#define HW2_STAD_H


#include "Station.h"

class Stad : public Station{
public:

    Stad(StationType stationType, const string& stationName, int transitTime = 10);

    void print() const override;

};


#endif //HW2_STAD_H
