//
// Created by Admin on 19/05/2018.
//

#ifndef HW2_STAD_H
#define HW2_STAD_H


#include "Station.h"



class Stad : public Station{
    //const static int transitTime;

public:
    static int stadTime;

    Stad(const string& stationName, StationType stationType = StationType::Stad);

    void print() const override;

};


#endif //HW2_STAD_H
