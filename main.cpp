
#include "Oranjestad.h"
#include "Input.h"
#include "Stad.h"


int main(int argc, char* argv[]) {
    Oranjestad ob(argc, argv);
    Graph g = ob.getGraph();
    g.print();
    g.outbound("A");
    cout << endl << endl << endl << endl;
    Graph g2 = g.reversedGraph();
    g2.outbound("A");

    return 0;
}