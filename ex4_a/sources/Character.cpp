#include <iostream>
#include <string>
#include "Character.hpp"

using namespace std;
using namespace ariel;


//====== Character implemence ======//

// constructor - create a new Character
Character::Character(string myname, Point pnt, int numH) : name(myname), pos(pnt), numHit(numH), into(false) {}

// setters //
void Character::setName(string newName)
{
    this->name = newName;
}

void Character::setLocation(Point &newPoint)
{
    this->pos = newPoint;
}

void Character::setHit(int newHit)
{
    this->numHit = newHit;
}

// check if exist more numHit
bool Character::isAlive() const
{
   if (this->numHit > 0) return true;
   else return false;
}

// calculate the distance between the two characters
double Character::distance(Character *other) const
{
    return 0.0;
}

// sub numHit when happened hit
void Character::hit(int hits)
{
    if (this->numHit >= hits)
        this->numHit -= hits;
    else this->numHit = 0;
}

string Character::getName() const
{
    return this->name;
}

Point& Character::getLocation()
{
    return this->pos;
} 

int Character::getHit() const
{
    return this->numHit;
}

void Character::setInto()
{
    this->into = true;
}

bool Character::getInto()
{
    return this->into;
}

/*
string Character::print() const
{
    return "Character";
}
*/


//=========== Cowboy implemence ===========//

// constructor - create a new Cowboy
Cowboy::Cowboy(string myname, Point pnt) : Character(myname, pnt, 110), bullet(6) {}

// print the Cowboy's data
string Cowboy::print() const
{
    return "cowboy";
}

// shoots the enemy
void Cowboy::shoot(Character *other)
{
    cout << "shoot" << endl;
}

// check if there are bullets left in the gun
bool Cowboy::hasboolets() const
{
    if (this->bullet > 0)
        return true;
    else return false;
}

// loads the gun with six new bullets
void Cowboy::reload()
{
    this->bullet = 6;
}

int Cowboy::getBullet() const
{
    return this->bullet;
}



//====== Ninja implemence ======//

// constructor - create a new Ninja
Ninja::Ninja(string myname, Point pnt, int numH, int myspeed): Character(myname, pnt, numH), speed(myspeed) {}

/*
// print the Ninja's data
virtual string Ninja::print()
{
    return "Ninja";
}
*/

// move towards the enemy
void Ninja::move(Character *other)
{
    cout << "move Ninja" << endl;
}

// hit enemy
void Ninja::slash(Character *other)
{
    cout << "slash Ninja" << endl;
}

int Ninja::getSpeed() const
{
    return this->speed;
}




//====== YoungNinja implemence ======//

// constructor - create a new YoungNinja
YoungNinja::YoungNinja(string myname, Point pnt) : Ninja(myname, pnt, 100, 14) {}

// print the YoungNinja's data
string YoungNinja::print() const
{
    return "YoungNinja";
}



//====== TrainedNinja implemence ======//

// constructor - create a new TrainedNinja
TrainedNinja::TrainedNinja(string myname, Point pnt) : Ninja(myname, pnt, 120, 12) {}

// print the TrainedNinja's data
string TrainedNinja::print() const
{
    return "TrainedNinja";
}



//====== OldNinja implemence ======//

// constructor - create a new OldNinja
OldNinja::OldNinja(string myname, Point pnt) : Ninja(myname, pnt, 150, 8) {}

// print the OldNinja's data
string OldNinja::print() const
{
    return "OldNinja";
}