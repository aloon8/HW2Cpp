//
// Created by raviv on 19/05/18.
//

#include "Oranjestad.h"

Oranjestad::Oranjestad(int num_of_arguments, char **strings_of_arguments) {
    init(num_of_arguments,strings_of_arguments);
}

void Oranjestad::init(int num_of_arguments, char **strings_of_arguments) {
    input.insertToGraph(graph,num_of_arguments,strings_of_arguments);
}

const Graph& Oranjestad::getGraph() const {
    return graph;
}

const Input& Oranjestad::getInput() const {
    return input;
}
