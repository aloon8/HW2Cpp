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

    Vehicle(int stopTime, Color color);

    virtual void print() const = 0;


protected:
    int stopTime;
    Color color;
};


#endif //HW2_VEHICLE_H
