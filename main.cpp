
#include "Oranjestad.h"
#include "Input.h"
#include "Stad.h"



int main(int argc, char* argv[]) {
    Oranjestad ob(argc, argv);
    ob.getGraph().print();

    return 0;
}