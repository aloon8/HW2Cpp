//
// Created by Admin on 19/05/2018.
//

#include "Graph.h"
#include "Bus.h"
#include "Rail.h"
#include "Tram.h"
#include "Sprinter.h"
#include "Input.h"


/* This function returns a new allocated Station */
shared_ptr<Station> Graph::makeStation(const string& stationName){
    shared_ptr<Station> station(nullptr); // declared one time

    if(stationName[0] == 'C' && stationName[1] == 'S'){ //by input Central stations have to start with CS
        station = shared_ptr<Station>(new Central(stationName));
    }
    else if(stationName[0] == 'I' && stationName[1] == 'C'){ //by input Intercity stations have to start with IC
        station = shared_ptr<Station>(new Intercity(stationName));
    }
    else
        station = shared_ptr<Station>(new Stad(stationName)); // else it's a Stad Station

    return station;
}


/* This function adds a new edge to the graph*/
void Graph::addEdge(const string &sourceString, const string &destinationString, Vehicle::VehicleType vehicleType, const int weight) {

    shared_ptr<Station> sourceStation(nullptr), destinationStation(nullptr); // declared one time


    auto sourceIterator = findVertex(sourceString);
    if(sourceIterator == Vertices.end()){ // the vertex does not exist in the set
        sourceStation = makeStation(sourceString); // creating a new Station
        Vertices.emplace(sourceStation); // entering it into the set
        shared_ptr<std::vector<shared_ptr<Destination>>> vec1(new vector<shared_ptr<Destination>>); // creating the value of the map
        StationsMap.emplace(sourceString,vec1); // entering a new (key,value) to the map
    }else
        sourceStation = (*sourceIterator);// the vertex does exist and sourceIterator is pointing at it

    /* Same thing as above only here the Vertex is the destination */
    auto destinationIterator = findVertex(destinationString);
    if(destinationIterator == Vertices.end()){
        destinationStation = makeStation(destinationString);
        Vertices.emplace(destinationStation);
        shared_ptr<std::vector<shared_ptr<Destination>>> vec(new vector<shared_ptr<Destination>>);
        StationsMap.emplace(destinationString,vec);
    }else
        destinationStation = (*destinationIterator);



    auto sourceVector = StationsMap.at(sourceString); // getting the value in the map of the source (getting the vector)
    auto beginSourceVector = sourceVector->begin();//beginning of vector
    auto endSourceVector = sourceVector->end(); // end of vector
    while(beginSourceVector != endSourceVector){
        if((*beginSourceVector)->getStationName() == destinationString && (*beginSourceVector)->getVehicle()->getVehicleType() == vehicleType)
        { // there is already an edge that exists between these two vertices
            if((*beginSourceVector)->getWeight() > weight) // if the current weight is bigger we replace it, else we return
                (*beginSourceVector)->setWeight(weight);
            return;
        }
        beginSourceVector++; // iterating over the map
    }
    shared_ptr<Destination> destination = makeDestination(destinationStation,weight,vehicleType,destinationString); // creating a new destination
    sourceVector->emplace_back(destination); // entering the new destination into the Source's Vector
}



/* returns an iterator to a specific vertex in the Set, if it doesn't exist the function returns iterator to the end */
std::set<shared_ptr<Station>>::iterator Graph::findVertex(const string &lookingFor) {
    auto beg = Vertices.begin();
    auto end = Vertices.end();

    while(beg != end) {
        if((*beg)->getStationName() == lookingFor) // the search is by comparing the strings
            return beg;
        beg++;
    }
    return beg;
}



/* This function creates a new Destination */
shared_ptr<Destination> Graph::makeDestination(weak_ptr<Station> destination, int weight, Vehicle::VehicleType vehicleType, string name){
    shared_ptr<Vehicle> vehicle; // one time declaration

    switch(vehicleType){ // switching by the vehicle type enum
        case Vehicle::VehicleType::Bus:
            vehicle = shared_ptr<Vehicle>(new Bus());
            break;
        case Vehicle::VehicleType::Rail:
            vehicle = shared_ptr<Vehicle>(new Rail());
            break;
        case Vehicle::VehicleType::Tram:
            vehicle = shared_ptr<Vehicle>(new Tram());
            break;
        case Vehicle::VehicleType::Sprinter:
            vehicle = shared_ptr<Vehicle>(new Sprinter());
            break;
    }
    shared_ptr<Destination> dest(new Destination(destination,vehicle,weight,name)); // allocating a new share_ptr of Destination
    return dest;
}



/* this function prints all the edges in the graph */
void Graph::print(ofstream& of) const {
    for(auto src = StationsMap.begin() ; src != StationsMap.end(); src++){
        auto vectorBegin = src->second->begin();
        auto vectorEnd = src->second->end();
        while(vectorBegin != vectorEnd){
            of << "Source : " << src->first << "    " << "Destination : " << (*vectorBegin)->getStationName() <<
                 "    " << "Weight : " << (*vectorBegin)->getWeight() << "    ";
            if((*vectorBegin)->getVehicle()->getVehicleType() == Vehicle::VehicleType::Tram) of << "Tram\n";
            else if((*vectorBegin)->getVehicle()->getVehicleType() == Vehicle::VehicleType::Rail) of << "Rail\n";
            else if((*vectorBegin)->getVehicle()->getVehicleType() == Vehicle::VehicleType::Bus) of << "Bus\n";
            else of <<"Sprinter\n";
            vectorBegin++;
        }
    }

}

/* This function prints all the stations that the source node can reach by all the transport vehicles */
void Graph::outbound(const string &sourceNode) {
    auto sourceIter = findVertex(sourceNode);
    if(sourceIter == Vertices.end()){ // the node does not exist
        throw Input::NodeDoesNotExistException(sourceNode);
    }


    bool printed = false; // a boolean flag to know if the last run of DFS printed to output
    cout << "bus : ";
    DFS((*sourceIter),Vehicle::Bus,&printed, sourceNode);
    if(printed)
        cout << endl;
    else
        cout << "no outbound travel\n";


    returnVertexToStandard(); // before running another DFS on a different Vehicle, returning the fields to standard
    printed = false;
    cout << "rail : ";
    DFS((*sourceIter),Vehicle::Rail,&printed,sourceNode);
    if(printed)
        cout << endl;
    else
        cout << "no outbound travel\n";

    /* Same as above only different vehicles */

    returnVertexToStandard();
    printed = false;
    cout << "sprinter :";
    DFS((*sourceIter),Vehicle::Sprinter,&printed,sourceNode);
    if(printed)
        cout << endl;
    else
        cout << "no outbound travel\n";

    returnVertexToStandard();
    printed = false;
    cout <<"tram : ";
    DFS((*sourceIter),Vehicle::Tram,&printed,sourceNode);
    if(printed)
        cout << endl;
    else
        cout << "no outbound travel\n";

    returnVertexToStandard(); // returns all the vertices data members to be as before the DFS
}

void Graph::DFS(weak_ptr<Station> source, Vehicle::VehicleType vehicleType, bool* printed, const string& sourceName) {
    if(source.lock()->visited) // the algorithm already visited this node so we don't need to enter
        return;
    source.lock()->visited = true; // changing the visited data to true - cause we are visiting now in the node

    string strNode = source.lock()->getStationName();
    if(strNode != sourceName) { // printing only the stations we can get to and not the Source station
        *printed = true;
        cout << strNode << " ";
    }
    auto vector = StationsMap.at(source.lock()->getStationName()); // all the neighbours of the specific node we are in
    auto beg = vector->begin();
    auto end = vector->end();
    while(beg != end){ // running on all the neighbours recursively and visiting their neighbours ........
        if((!(*beg)->getStation().lock()->visited) && (*beg)->getVehicle()->getVehicleType() == vehicleType){ // have to be on the specific Vehicle Type
            DFS((*beg)->getStation(),vehicleType,printed,sourceName);
        }
        beg++;
    }

}




/* this function returns the boolean data member "visited" to false for DFS, and the distance to Infinity for Dijkstra*/
void Graph::returnVertexToStandard() {
    auto beg = Vertices.begin();
    auto end = Vertices.end();

    while(beg != end){
        (*beg)->visited = false;
        (*beg)->setDistance(std::numeric_limits<int>::max());
        beg++;
    }

}

/* This function returns a reversed graph, every direction of an edge is now reversed to a new graph
 *  the regular graph isn't changed. */
Graph Graph::reversedGraph() {
   Graph graph;

    auto VerticesBegin = Vertices.begin();
    auto VerticesEnd = Vertices.end();
    /* First, copying all the Vertices to graph's Vertices set for the new graph*/
    while(VerticesBegin != VerticesEnd){
        graph.Vertices.emplace((*VerticesBegin)); // entering all the existing vertices
        shared_ptr<std::vector<shared_ptr<Destination>>> vec(new vector<shared_ptr<Destination>>);
        graph.StationsMap.emplace((*VerticesBegin)->getStationName(),vec);
        VerticesBegin++;
    }


    /* now we want to take every edge in the graph and reverse it */

    auto mapBegin = StationsMap.begin();
    auto mapEnd = StationsMap.end();

    while(mapBegin != mapEnd) { // running on all the map
        /* getting the vector (value) of the current key in the loop */
        auto beginVector = mapBegin->second->begin();
        auto endVector = mapBegin->second->end();
        while(beginVector != endVector) {
            /*in this for loop, we run on all the vector and for this graph -> the source is : (*mapBegin); the destination is : (*beginVector);
             * so for the new graph we reverse the source and destination, with using the addEdge() method of the graph
             * */
            graph.addEdge((*beginVector)->getStationName(),(*mapBegin).first,(*beginVector)->getVehicle()->getVehicleType(),(*beginVector)->getWeight());
            beginVector++;
        }
        mapBegin++;
    }

return graph;
}


int Graph::shortestPath(const string& src, const string& dest, Vehicle::VehicleType veh) {

    PriorityQueue pq;/* a minimum heap with priority of distance*/
    int stopTime = 0;

    auto sourceIterator = findVertex(src);
    if(sourceIterator == Vertices.end()){
        throw Input::NodeDoesNotExistException(src);
    }
    auto desIterator = findVertex(dest);
    if(desIterator == Vertices.end()){
        throw Input::NodeDoesNotExistException(dest);
    }
    pq.push(*sourceIterator);/*push the first vertex it will the src vertex*/
    (*sourceIterator)->setDistance(0);

    while (!pq.empty()) {
        Station &minPriority = pq.top();
        minPriority.visited = true;
        pq.pop();


        auto vect = StationsMap.at(minPriority.getStationName());
        /*the variable it run about all the neighbors of the vertex minPriority*/
        for (auto it = vect->begin(); it != vect->end(); ++it) {
            int weight = (*it)->getWeight();

            /*  If there is shorted path to it through minPriority.*/
            if ((*it)->getStation().lock()->getDistance() > minPriority.getDistance() + weight + stopTime
                && !(*it)->getStation().lock()->visited && (*it)->getVehicle()->getVehicleType() == veh){
                /* Updating distance of it */
                stopTime = (*it)->getVehicle()->getStopTime();
                (*it)->getStation().lock()->setDistance(minPriority.getDistance() + weight + stopTime);
                auto sta = (*it)->getStation();
                pq.push(sta);
            }
        }
    }
    /*now the field distance handle the destination between src to dest*/
    int distance = (*desIterator)->getDistance();

    if(distance == std::numeric_limits<int>::max()) {
        cout << "route unavailable" << endl;
    }
    else
        cout << distance-stopTime << endl;
    returnVertexToStandard();
}

void Graph::FindAllPaths(weak_ptr<Destination> source, weak_ptr<Destination> destination,
                         std::vector<weak_ptr<Destination>> &path) {

    source.lock()->visitedForMulti = true;
    path.emplace_back(source);
    if(*(source.lock()) == destination){
        Routes.emplace_back(path);
    } else {
        auto tmpDestinationVectorOfCurrentSource = StationsMap.at(source.lock()->getStationName());
        auto begin = tmpDestinationVectorOfCurrentSource->begin();
        auto end = tmpDestinationVectorOfCurrentSource->end();
        while(begin != end){
            if(!(*begin)->visitedForMulti)
                FindAllPaths((*begin), destination,path);
            begin++;
        }
    }

    path.pop_back();
    source.lock()->visitedForMulti = false;
}

int Graph::calculateCostOfGivenPath(std::vector<weak_ptr<Destination>>& path) {
    auto first = path.begin();
    auto second = ++first;
    auto end = path.end();
    int sum = 0;
    first--;bool flag = false;

    while(second != end){
        sum += (*second).lock()->getWeight();
        if(flag) {
            if ((*first).lock()->getVehicle()->getVehicleType() != (*second).lock()->getVehicle()->getVehicleType()) {
                sum += (*first).lock()->getStation().lock()->getTransitTime();
            }
        }
        flag = true;
        first++;second++;
    }
    return sum;
}

void Graph::multiShortestPath(const string &srcString, const string &destString) {
    int result(0), min = std::numeric_limits<int>::max(); // initializing min to infinity
    auto srcStation = findVertex(srcString);
    if(srcStation == Vertices.end()){
        throw Input::NodeDoesNotExistException(srcString);
    }
    auto destStation = findVertex(destString);
    if(destStation == Vertices.end() ) {
        throw Input::NodeDoesNotExistException(destString);
    }
    weak_ptr<Station> tmp1(*srcStation);
    weak_ptr<Station> tmp2(*destStation);
    shared_ptr<Vehicle> tmpVehicle(new Bus());
    shared_ptr<Destination> srcDestination(new Destination(tmp1, tmpVehicle,0,srcString));
    shared_ptr<Destination> destDestination(new Destination(tmp2, tmpVehicle ,0,destString));
    auto vec (new std::vector<weak_ptr<Destination>>);
    FindAllPaths(srcDestination,destDestination, *vec);
    auto beg = Routes.begin();
    auto end = Routes.end();
    while(beg != end ) {
        result = calculateCostOfGivenPath((*beg));
        if (result < min) min = result;
        beg++;
    }
    cout <<"The minimum time between " << srcString << "to" << destString << "is: " << min << endl;
}

bool Graph::checkValidArgumentsForUni(const string &src, const string &dest) {
    auto sourceIterator = findVertex(src);
    if(sourceIterator == Vertices.end()){
        throw Input::NodeDoesNotExistException(src);
    }
    auto desIterator = findVertex(dest);
    if(desIterator == Vertices.end()){
        throw Input::NodeDoesNotExistException(dest);
    }
    return true;
}

