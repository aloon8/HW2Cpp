//
// Created by Admin on 19/05/2018.
//

#include "Graph.h"

void Graph::addEdge(shared_ptr<Station> src, const Destination& destination) {
    if(graph.find(src) == graph.end()) {
        shared_ptr<vector<Destination>> vect(new vector<Destination>);
        graph.emplace(src, vect);
    }
    auto destinations = graph[src];
    destinations->push_back(destination);

}

void Graph::print(shared_ptr<Station> src) {
    if(graph.find(src) == graph.end()) {
        return;
    }
    auto destinations = graph[src];
    auto begin = destinations->begin();
    auto  end = destinations->end();
    while(begin != end) {
        cout << (*begin).getStation()->getStationName() << '\t' << (*begin).getWeight() << endl;
        begin++;
    }
}


