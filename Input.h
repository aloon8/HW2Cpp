//
// Created by Admin on 19/05/2018.
//

#ifndef HW2_INPUT_H
#define HW2_INPUT_H


#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include "Central.h"
#include "Vehicle.h"
#include "Intercity.h"
#include "Stad.h"
#include "Graph.h"

class Input {
public:
    Input();
    Input(const Input& rhs){};
    void insertToGraph(Graph& graph, const int num_of_arguments, char **strings_of_arguments);
    void insertToGraphOneLine(Graph& graph, const char* fileName);
    Vehicle::Color checkNameOfFile(const char* fileName);
    void LineToEdge(Graph& ,string&, Vehicle::Color);
    void ConfigureFile(const char* filename);
    int hashing(string&);
    class FileNameException{};
    class FileInputException{};
private:
    shared_ptr<Station> makeStation(const string &stationName);
    shared_ptr<Destination> makeDestination(const string &stationName, int weight, Vehicle::Color color);

    unique_ptr<std::ofstream> outPutFile;
};


#endif //HW2_INPUT_H
