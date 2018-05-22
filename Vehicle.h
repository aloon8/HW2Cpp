//
// Created by Admin on 19/05/2018.
//

#include <iostream>

#ifndef HW2_VEHICLE_H
#define HW2_VEHICLE_H


using namespace std;



class Vehicle {
public:
    typedef enum  {Blue, Green , Red, Yellow} Color;

    Vehicle(Color color);

    virtual void print() const = 0;


protected:
    Color color;
};


#endif //HW2_VEHICLE_H
