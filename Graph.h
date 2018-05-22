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
    std::map<shared_ptr<Station>,shared_ptr<std::vector<shared_ptr<Destination>>>> map;
    void print(shared_ptr<Station> src) ;

    void print() const;

    void addEdge(shared_ptr<Station> src,shared_ptr<Destination> destination);
};


#endif //HW2_GRAPH_H
