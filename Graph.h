//
// Created by Admin on 19/05/2018.
//

#ifndef HW2_GRAPH_H
#define HW2_GRAPH_H


#include "Destination.h"
#include <vector>
#include <map>
#include <set>
#include "Central.h"
#include "Intercity.h"
#include "Stad.h"

class Graph {


public:
    /** Data Members **/

    /* this map holds a string that represents a source Node (Station) and a vector of Destinations for that node */
    std::map< string ,shared_ptr<std::vector<shared_ptr<Destination>>>> StationsMap;

    /* this is a set of vertices -> every Vertex has to be unique */
    std::set<shared_ptr<Station>> Vertices;


    /** Functions **/

    shared_ptr<Station> makeStation(const string& stationName); // with a given string returns an allocated Station

    //with a given string,weight and Vehicle returns an allocated Destination
    shared_ptr<Destination> makeDestination(weak_ptr<Station> destination, int weight, Vehicle::VehicleType,string);

    void print() const; // prints all the Edges in the Graph

    void outbound(const string& sourceNode); // returns all the Vertices a given Station can reach in the graph

    void DFS(weak_ptr<Station> source, Vehicle::VehicleType vehicleType,bool* printed, const string&); // Depth First Search Algorithm

    std::set<shared_ptr<Station>>::iterator findVertex(const string& lookingFor); // returns an iterator to a Vertex in the Vertices set

    //adds an edge to the graph by a given source and destination strings, vehicle type and weight
    void addEdge(const string& sourceString, const string& destinationString , Vehicle::VehicleType vehicleType, const int weight );

    void returnVertexToStandard(); // a function that is runned after DFS,Dijkstra and re-initializes specific data members to standard

    Graph reversedGraph(); // returns a reversed graph
};


#endif //HW2_GRAPH_H
