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
    string line,name,intString;
    int time;
    enum { BUS = 330 ,RAIL = 424 , TRAM = 436 , SPRINTER = 887 , STAD = 428 , CENTRAL = 745 , INTERCITY = 987};

    while(getline(file,line)){
        stringstream ss(line);
        name = "";
        ss >> name;
        time = 0;
        intString = "";

        switch( hashing(name) ) {


            case BUS:
                ss >> intString;
                if(isdigit(atoi(intString.c_str()))) // checking that input is numbers
                    time = atoi(intString.c_str());
                else
                    throw FileInputException(); // second place is not a number
                if(name != "bus" || time < 0)
                    throw FileInputException(); //
                Bus::busTime = time;
                if(ss.str().empty()) // checks number of arguments
                    break;
                else
                    throw FileInputException(); // more than 2 arguments in line


            case RAIL:
                ss >> intString;
                if(isdigit(atoi(intString.c_str()))) // checking that input is numbers
                    time = atoi(intString.c_str());
                else
                    throw FileInputException(); // second place is not a number
                if(name != "rail" || time < 0)
                    throw FileInputException(); //
                Rail::railTime = time;
                if(ss.str().empty()) // checks number of arguments
                    break;
                else
                    throw FileInputException(); // more than 2 arguments in line


            case TRAM:
                ss >> intString;
                if(isdigit(atoi(intString.c_str()))) // checking that input is numbers
                    time = atoi(intString.c_str());
                else
                    throw FileInputException(); // second place is not a number
                if(name != "tram" || time < 0)
                    throw FileInputException(); //
                Tram::tramTime = time;
                if(ss.str().empty()) // checks number of arguments
                    break;
                else
                    throw FileInputException(); // more than 2 arguments in line


            case SPRINTER:
                ss >> intString;
                if(isdigit(atoi(intString.c_str()))) // checking that input is numbers
                    time = atoi(intString.c_str());
                else
                    throw FileInputException(); // second place is not a number
                if(name != "sprinter" || time < 0)
                    throw FileInputException(); //
                Sprinter::sprinterTime = time;
                if(ss.str().empty()) // checks number of arguments
                    break;
                else
                    throw FileInputException(); // more than 2 arguments in line


            case STAD:
                ss >> intString;
                if(isdigit(atoi(intString.c_str()))) // checking that input is numbers
                    time = atoi(intString.c_str());
                else
                    throw FileInputException(); // second place is not a number
                if(name != "stad" || time < 0)
                    throw FileInputException(); //
                Stad::stadTime = time;
                if(ss.str().empty()) // checks number of arguments
                    break;
                else
                    throw FileInputException(); // more than 2 arguments in line


            case CENTRAL:
                ss >> intString;
                if(isdigit(atoi(intString.c_str()))) // checking that input is numbers
                    time = atoi(intString.c_str());
                else
                    throw FileInputException(); // second place is not a number
                if(name != "central" || time < 0)
                    throw FileInputException(); //
                Central::centralTime = time;
                if(ss.str().empty()) // checks number of arguments
                    break;
                else
                    throw FileInputException(); // more than 2 arguments in line


            case INTERCITY:
                ss >> intString;
                if(isdigit(atoi(intString.c_str()))) // checking that input is numbers
                    time = atoi(intString.c_str());
                else
                    throw FileInputException(); // second place is not a number
                if(name != "intercity" || time < 0)
                    throw FileInputException(); //
                Intercity::interCityTime = time;
                if(ss.str().empty()) // checks number of arguments
                    break;
                else
                    throw FileInputException(); // more than 2 arguments in line
        }//switch
    } // while

}




void Input::insertToGraphOneLine(Graph &graph, const char *fileName) {
    std::ifstream inputFile;
    Vehicle::VehicleType vehicleType;
    try {
        vehicleType = checkNameOfFile(fileName);
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
            LineToEdge(graph,line,vehicleType);
        }catch(FileInputException& e){
            cout << "the line in the file isn't good" << endl;
        }
}

void Input::LineToEdge(Graph &graph, string &line, Vehicle::VehicleType vehicleType) {
    stringstream ss(line);
    string src,dest;
    int weight;
    ss >> src;
    ss >> dest;
    ss >> weight;
    graph.addEdge(src,dest,vehicleType,weight);
}




Vehicle::VehicleType Input::checkNameOfFile(const char *fileName) {
    string name(fileName);
    if((name.find("sprinter")) == 0 ){
        return Vehicle::VehicleType::Sprinter;
    }
    else if((name.find("tram")) == 0 ){
        return Vehicle::VehicleType::Tram;
    }
    else if((name.find("rail")) == 0 ){
        return Vehicle::VehicleType::Rail;
    }
    else if((name.find("bus")) == 0 ){
        return Vehicle::VehicleType::Bus;
    } else throw FileNameException();
}



