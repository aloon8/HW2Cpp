//
// Created by Admin on 19/05/2018.
//

#include <algorithm>
#include "Input.h"
#include "Bus.h"
#include "Rail.h"
#include "Tram.h"
#include "Sprinter.h"


Input::Input() {

}

void Input::insertToGraph(Graph& graph, const int num_of_arguments, char **strings_of_arguments) {
    int i = 2;
    for( ; i<num_of_arguments && strcmp(strings_of_arguments[i],"-c") && strcmp(strings_of_arguments[i],"-o"); i++){
        insertToGraphOneLine(graph,strings_of_arguments[i]);
    }
    if(i < num_of_arguments) {
        if (strcmp(strings_of_arguments[i], "-c")) {
            i++;
            ConfigureFile(strings_of_arguments[i++]);
        }
    }
    if ( i < num_of_arguments && strcmp(strings_of_arguments[i],"-o"))
        outPutFile =unique_ptr<std::ofstream>(new ofstream(strings_of_arguments[++i]));
    else
        outPutFile = unique_ptr<std::ofstream>( new ofstream("output.dat")); // default

}

int Input::hashing(string& name){
    int cnt = 0;
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);

    for (int i = 0; i < name.size(); ++i)
        cnt += name[i];
    return cnt;
}


void Input::ConfigureFile(const char *filename) {
    ifstream file = ifstream(filename);
    string line,name;
    int time;
    enum { BUS = 330 ,RAIL = 424 , TRAM = 436 , SPRINTER = 887 , STAD = 428 , CENTRAL = 745 , INTERCITY = 987};

    while(getline(file,line)){
        stringstream ss(line);
        ss >> name;
        time = 0;
        switch(hashing(name)){
            case BUS:
                ss >> time;
                if(name != "bus" || time < 0)
                    throw FileInputException(); //
                Bus::busTime = time;
                if(ss.str().empty())
                    break;
                else
                    throw FileInputException(); // more than 2 arguments in line
            case RAIL:
                ss >> time;

                break;
            case TRAM:
                break;
            case SPRINTER:
                break;
            case STAD:
                break;
            case CENTRAL:
                break;
            case INTERCITY:
                break;


        }
    }

}




void Input::insertToGraphOneLine(Graph &graph, const char *fileName) {
    std::ifstream inputFile;
    Vehicle::Color color;
    try {
        color = checkNameOfFile(fileName);
        inputFile.open(fileName);

    }catch (FileNameException& e){
        cout << "Problem with file name\n";
        return;
    }
    if(!inputFile.is_open())
        cout << "File is not open\n";
    string line;
    while(getline(inputFile,line))
        try{
            LineToEdge(graph,line,color);
        }catch(FileInputException& e){
            cout << "the line in the file isn't good" << endl;
        }
}

void Input::LineToEdge(Graph &graph, string &line, Vehicle::Color color) {
    stringstream ss(line);
    string src,dest;
    int weight;
    ss >> src;
    ss >> dest;
    ss >> weight;
    auto station = makeStation(src);
    auto destination = makeDestination(dest,weight,color);
    graph.addEdge(station,destination);
}


shared_ptr<Destination> Input::makeDestination(const string& stationName, int weight, Vehicle::Color color){
    auto station = makeStation(stationName);
    shared_ptr<Vehicle> vehicle;

    switch(color){
        case Vehicle::Blue:             //Blue
            vehicle = shared_ptr<Vehicle>(new Bus());
            break;
        case Vehicle::Red:
            vehicle = shared_ptr<Vehicle>(new Rail());
            break;
        case Vehicle::Green:
            vehicle = shared_ptr<Vehicle>(new Tram());
            break;
        case Vehicle::Yellow:
            vehicle = shared_ptr<Vehicle>(new Sprinter());
            break;
    }
        shared_ptr<Destination> dest(new Destination(station,vehicle,weight));
    return dest; // CHECK THIS if there is casting of shared_ptr on the raw ptr !!!!!!
}

shared_ptr<Station> Input::makeStation(const string& stationName){
    shared_ptr<Station> station(nullptr);
    if(stationName[0] == 'C' && stationName[1] == 'S'){
        station = shared_ptr<Station>(new Central(stationName));
    }
    else if(stationName[0] == 'I' && stationName[1] == 'C'){
        station = shared_ptr<Station>(new Intercity(stationName));
    }
    else{
        station = shared_ptr<Station>(new Stad(stationName));
    }
    return station;
}

// typedef enum  {Blue, Green , Red, Yellow} Color;


Vehicle::Color Input::checkNameOfFile(const char *fileName) {
    string name(fileName);
    if((name.find("sprinter")) == 0 ){//yellow
        return Vehicle::Yellow;
    }
    else if((name.find("tram")) == 0 ){ //green
        return Vehicle::Green;
    }
    else if((name.find("rail")) == 0 ){ // red
        return Vehicle::Red;
    }
    else if((name.find("bus")) == 0 ){ //blue
        return Vehicle::Blue;
    } else throw FileNameException();
}





