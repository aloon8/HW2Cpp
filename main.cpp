
#include "Oranjestad.h"
#include "Input.h"
#include "Stad.h"


int main(int argc, char* argv[]) {
    Oranjestad ob(argc, argv);
    Graph g = ob.getGraph();
    g.shortestPath("CSzuid","TLV", Vehicle::Bus);



    return 0;
}