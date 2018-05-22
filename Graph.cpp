//
// Created by Admin on 19/05/2018.
//

#include "Graph.h"

void Graph::addEdge(shared_ptr<Station> src, shared_ptr<Destination> destination) {
    if(map.find(src) == map.end()) {
        auto vect(new vector<shared_ptr<Destination>>);
        map.emplace(src, vect);
    }
    auto destinations = map.at(src);
    destinations->emplace_back(destination);

}


void Graph::print() const{
    for(auto src : map){
        for(auto it = src.second->begin() ; it != src.second->end(); it++ ){
            cout << "Source : " <<src.first->getStationName() << "  Destination : " << (*it)->getStation()->getStationName()
                                                                                    << "  " << " weight : " <<  (*it)->getWeight() << endl;
        }
    }
}

void Graph::print(shared_ptr<Station> src) {
    if(map.find(src) == map.end()) {
        return;
    }

}


