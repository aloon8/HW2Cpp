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

    Vehicle::VehicleType checkNameOfFile(const char* fileName);

    void LineToEdge(Graph& ,string&, Vehicle::VehicleType);

    void ConfigureFile(const char* filename);

    int hashing(string&);

    ofstream& getOutPutFile() const {
        return *outPutFile;
    }
    /*  Exceptions classes*/

    class CommandNotFoundException{};

    class NumberOfArgumentsException{};

    class FileNameException{};

    class FileInputException : public exception{};

    class NodeDoesNotExistException : public exception{
        string name;
    public:
        NodeDoesNotExistException(const string& name){this->name = name; }
        virtual const char* what(){return "does not exist in the current network";}
        const string& getName()const{ return name;}
    };

private:
    unique_ptr<std::ofstream> outPutFile;

};


#endif //HW2_INPUT_H
