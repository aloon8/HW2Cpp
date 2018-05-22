//
// Created by raviv on 19/05/18.
//

#ifndef HW2_ORANJESTAD_H
#define HW2_ORANJESTAD_H


#include "Graph.h"
#include "Input.h"

class Oranjestad {
public:
    Oranjestad(int num_of_arguments, char **strings_of_arguments);
    void init(int num_of_arguments, char **strings_of_arguments);
    const Graph &getGraph() const;
    const Input & getInput() const;

private:
    Graph graph;
    Input input;
    std::ofstream outPutFile;

};


#endif //HW2_ORANJESTAD_H
