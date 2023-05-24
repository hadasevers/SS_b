#include "Character.hpp"


using namespace std;

#pragma once

namespace ariel
{
    
    class Cowboy: public Character
    {
        private:
            int bullet; // bullets number

        //protected:
         //   void setBullet(int num)

        public:
            Cowboy(string myname, Point pnt); // constructor - create a new Cowboy
            string print() override; // print the Cowboy's data
            void shoot(Character *other);   // shoots the enemy
            bool hasboolets() const;    // check if there are bullets left in the gun
            void reload();        // loads the gun with six new bullets
            int getBullet() const;
    };

}