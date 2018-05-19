//
// Created by Admin on 19/05/2018.
//

#ifndef HW2_GRAPH_H
#define HW2_GRAPH_H


#include "Destination.h"
#include <vector>
#include <map>

class Graph {


public:
    std::map<shared_ptr<Station>,shared_ptr<std::vector<Destination>>> graph;
    void print(shared_ptr<Station> src) ;

    void addEdge(shared_ptr<Station> src, const Destination& destination);
};


#endif //HW2_GRAPH_H
