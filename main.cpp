#include <iostream>
#include <vector>
#include "Destination.h"
#include "Station.h"
#include "Central.h"
#include "Bus.h"
#include "Intercity.h"
#include "Stad.h"

int main() {


    std::vector<shared_ptr<Station>> vec;

    for (int i = 0; i < 1; ++i) {
        vec.emplace_back(std::move(new Intercity(Station::StationType::InterCity,"Metula")));
        vec.emplace_back(new Central(Station::StationType::Central, "Kiryat Shmona"));
        vec.emplace_back(new Stad(Station::StationType::Stad, "Kfar Yuval"));
    }

    auto begin = vec.begin();
    auto end = vec.end();
    while(begin != end) {
        cout << (*begin)->getStationType() << endl;
        begin++;
    }

    return 0;
}