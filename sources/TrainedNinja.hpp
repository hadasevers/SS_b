#include "Character.hpp"


using namespace std;

#pragma once

namespace ariel
{
    
    class TrainedNinja : public Ninja
    {
        public:
            TrainedNinja(string myname, Point pnt); // constructor - create a new TrainedNinja
            string print() override; // print the TrainedNinja's data
    };
}