#include "Character.hpp"


using namespace std;

#pragma once

namespace ariel
{
    
    class YoungNinja : public Ninja
    {
        public:
            YoungNinja(string myname, Point pnt); // constructor - create a new YoungNinja
            string print() override; // print the YoungNinja's data
    };
}