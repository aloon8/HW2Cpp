#include <iostream>
#include "Oranjestad.h"

int main() {
    Oranjestad oran{"alon"};
    std::cout << oran.graph.size();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}