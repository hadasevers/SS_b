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
        int numHit;
        string name;
        bool into;

    public:
        void setName(string newName); 
        void setLocation(Point &newPoint);
        void setHit(int newHit);
       
    //public:
        Character(string myname, Point pnt, int numH); // constructor - create a new Character
        bool isAlive() const;      // check if exist more numHit
        double distance(Character *other) const; // calculate the distance between the two characters
        void hit(int hits);  // sub numHit when happened hit
        string getName() const; 
        Point& getLocation();
        int getHit() const;
        virtual string print() const = 0;// print the character's data
        bool getInto();
        void setInto();
        virtual ~Character() = default;

        Character(const Character&) = delete;
        Character(Character&&) = delete;
        Character& operator=(const Character&) = delete;
        Character& operator=(Character&&) = delete;
    };


    class Cowboy: public Character
    {
        private:
            int bullet;

        //protected:
         //   void setBullet(int num)

        public:
            Cowboy(string myname, Point pnt); // constructor - create a new Cowboy
            string print() const override; // print the Cowboy's data
            void shoot(Character *other);   // shoots the enemy
            bool hasboolets() const;    // check if there are bullets left in the gun
            void reload();        // loads the gun with six new bullets
            int getBullet() const;
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


    class YoungNinja : public Ninja
    {
        public:
            YoungNinja(string myname, Point pnt); // constructor - create a new YoungNinja
            string print() const override; // print the YoungNinja's data
    };
    

    class TrainedNinja : public Ninja
    {
        public:
            TrainedNinja(string myname, Point pnt); // constructor - create a new TrainedNinja
            string print() const override; // print the TrainedNinja's data
    };


    class OldNinja : public Ninja
    {
        public:
            OldNinja(string myname, Point pnt); // constructor - create a new OldNinja
            string print() const override; // print the OldNinja's data
    };
}
