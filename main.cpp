#include <iostream>
#include "Destination.h"
#include "Central.h"
#include "Bus.h"
#include "Intercity.h"
#include "Stad.h"
#include "Graph.h"
#include "Tram.h"

int main() {

    Graph graph;
    shared_ptr<Station> station1(new Central(Station::Central,"Herzliya"));
    shared_ptr<Station> station2(new Stad(Station::Central,"Ra'anana"));
    shared_ptr<Station> station3(new Intercity(Station::Central,"Ramat Hasharon"));

    shared_ptr<Vehicle> vehicle1(new Tram());
    shared_ptr<Vehicle> vehicle2(new Bus());

    Destination d1(station2,vehicle1,30);
    Destination d2(station3,vehicle2,50);

    graph.addEdge(station1,d2);
    graph.addEdge(station1,d1);

    graph.print(station1);

    return 0;
}