#include <string>
#include "Point.hpp"

using namespace std;

#pragma once

namespace ariel
{
    class Character
    {
    private:
        Point pos;
        int numHit; // hit points
        string name;
        bool into;  // belongs to a group

    public:
        void setName(string newName); 
        void setLocation(Point &newPoint);
        void setHit(int newHit);
       
    //public:
        Character(string myname, Point pnt, int numH); // constructor - create a new Character
        bool isAlive() const;      // check if exist more numHit
        double distance(Character *other); // calculate the distance between the two characters
        void hit(int hits);  // sub numHit when happened hit
        string getName() const; 
        Point& getLocation();
        int getHit() const;
        virtual string print() = 0;// print the character's data
        bool getInto();
        void setInto();
        virtual ~Character() = default;

        Character(const Character&) = delete;
        Character(Character&&) = delete;
        Character& operator=(const Character&) = delete;
        Character& operator=(Character&&) = delete;
    };

    class Ninja : public Character
    {
        private:
            int speed;

        //protected:
         //   void setSpeed(int num);

        public:
            Ninja(string myname, Point pnt, int numH, int myspeed); // constructor - create a new Ninja
            //string print() const = 0 ; // print the Ninja's data
            void move(Character *other); // move towards the enemy
            void slash(Character *other); // hit enemy
            int getSpeed() const;
    };
}
