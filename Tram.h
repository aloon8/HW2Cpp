//
// Created by Admin on 19/05/2018.
//

#ifndef HW2_TRAM_H
#define HW2_TRAM_H


#include "Vehicle.h"

class Tram : public Vehicle{

public:

    Tram();

    static int tramTime;

    void print() const override;

private:


};


#endif //HW2_TRAM_H
