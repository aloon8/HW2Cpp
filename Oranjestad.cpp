//
// Created by raviv on 19/05/18.
//

#include "Oranjestad.h"

Oranjestad::Oranjestad(int num_of_arguments, char **strings_of_arguments) { //C'tor
    init(num_of_arguments,strings_of_arguments);
}

void Oranjestad::init(int num_of_arguments, char **strings_of_arguments) { // initializes all the Vertices and Edges in the graph
    input.insertToGraph(graph,num_of_arguments,strings_of_arguments);
}


/* prints all the nodes in the graph that can reach the given source node (represented by a string) */
void Oranjestad::inbound(const string &sourceNode) {
    Graph G = graph.reversedGraph();
    G.outbound(sourceNode);
}



/**  Getters & Setters  **/

const Graph& Oranjestad::getGraph() const {
    return graph;
}

const Input& Oranjestad::getInput() const {
    return input;
}
