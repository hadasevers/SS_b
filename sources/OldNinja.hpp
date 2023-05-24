#include "Character.hpp"


using namespace std;

#pragma once

namespace ariel
{
    
    class OldNinja : public Ninja
    {
        public:
            OldNinja(string myname, Point pnt); // constructor - create a new OldNinja
            string print() override; // print the OldNinja's data
    };
}