//
// Created by Admin on 19/05/2018.
//

#include "Graph.h"




void Graph::addEdge(shared_ptr<Station> src, Destination destination) {
    if(graph.find(src) == graph.end()) {
        graph.emplace(src, std::vector<Destination>());
    }
    auto destinations = graph[src];
    destinations.emplace_back(destination);

}

void Graph::print(shared_ptr<Station> src) {
    if(graph.find(src) == graph.end()) {
        cout << "Source does not exist !!\n";

        return;
    }
    auto destinations = graph[src];
    for (auto dest : destinations) {
        cout << "In loop !!!";
        cout << dest.getStation()->getStationName() << '\t' << dest.getWeight() << endl;
    }

}

