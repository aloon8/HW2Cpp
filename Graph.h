//
// Created by Admin on 19/05/2018.
//

#ifndef HW2_GRAPH_H
#define HW2_GRAPH_H


#include "Destination.h"
#include <vector>
#include <map>

class Graph {
    std::map<Station,std::vector<Destination>> graph;
};


#endif //HW2_GRAPH_H
