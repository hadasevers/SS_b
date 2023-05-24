#include <iostream>
#include <string>
#include "Character.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"

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
double Character::distance(Character *other)
{
    if(other)
    {
        double result = this->getLocation().distance(other->getLocation());
        return result;
    }
    else return 0;
}

// sub numHit when happened hit
void Character::hit(int hits)
{
    if (hits < 0) throw invalid_argument("negative number");

    else if (this->numHit >= hits)
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
string Character::print()
{
    return "Character";
}
*/


//=========== Cowboy implemence ===========//

// constructor - create a new Cowboy
Cowboy::Cowboy(string myname, Point pnt) : Character(myname, pnt, 110), bullet(6) {}

// print the Cowboy's data
string Cowboy::print()
{
    string result = "";
    if (this->getHit() > 0)
    {
        result = "C " + this->getName() + " " + to_string(this->getHit()) +\
                 " (" + to_string(this->getLocation().getx()) + "," + to_string(this->getLocation().gety()) + ")";
    }

    else
    {
        result = "C (" + this->getName() + ") " +\
                 " (" + to_string(this->getLocation().getx()) + "," + to_string(this->getLocation().gety()) + ")";
    }

    return result;
}

// shoots the enemy
void Cowboy::shoot(Character *other)
{
    if (other != nullptr)
    {
        if (other->isAlive() == false || this->isAlive() == false) throw runtime_error("Dead characters or dead enemy");

        else if (other == this) throw runtime_error("No self harm");

        // this cowboy didn't die and he had bullets left
        else if (this->getBullet() > 0 && this->getHit() > 0)
        {
            this->bullet -= 1;
            other->hit(10);
        }
    }
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
    if(this->isAlive() == true)
        this->bullet = 6;
    else throw runtime_error("the Cowboy died");
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
    if(other != nullptr)
    {
        Point movePoint = Point::moveTowards(this->getLocation(), other->getLocation(), this->speed);
        this->setLocation(movePoint);
    }
    
    //cout << "move Ninja" << endl;
}

// hit enemy
void Ninja::slash(Character *other)
{
    if (other != nullptr)
    {
        if (other->isAlive() == false || this->isAlive() == false) throw runtime_error("Dead characters or dead enemy");

        else if (other == this) throw runtime_error("No self harm");

        else if (this->getHit() > 0 && this->distance(other) <= 1)
        {
            other->hit(40);
        }
    }
    //cout << "slash Ninja" << endl;
}

int Ninja::getSpeed() const
{
    return this->speed;
}




//====== YoungNinja implemence ======//

// constructor - create a new YoungNinja
YoungNinja::YoungNinja(string myname, Point pnt) : Ninja(myname, pnt, 100, 14) {}

// print the YoungNinja's data
string YoungNinja::print()
{
    string result = "";
    if (this->getHit() > 0)
    {
        result = "N " + this->getName() + " " + to_string(this->getHit()) +\
                 " (" + to_string(this->getLocation().getx()) + "," + to_string(this->getLocation().gety()) + ")";
    }

    else
    {
        result = "N (" + this->getName() + ") " +\
                 " (" + to_string(this->getLocation().getx()) + "," + to_string(this->getLocation().gety()) + ")";
    }

    return result;
}



//====== TrainedNinja implemence ======//

// constructor - create a new TrainedNinja
TrainedNinja::TrainedNinja(string myname, Point pnt) : Ninja(myname, pnt, 120, 12) {}

// print the TrainedNinja's data
string TrainedNinja::print()
{
    string result = "";
    if (this->getHit() > 0)
    {
        result = "N " + this->getName() + " " + to_string(this->getHit()) +\
                 " (" + to_string(this->getLocation().getx()) + "," + to_string(this->getLocation().gety()) + ")";
    }

    else
    {
        result = "N (" + this->getName() + ") " +\
                 " (" + to_string(this->getLocation().getx()) + "," + to_string(this->getLocation().gety()) + ")";
    }

    return result;
}



//====== OldNinja implemence ======//

// constructor - create a new OldNinja
OldNinja::OldNinja(string myname, Point pnt) : Ninja(myname, pnt, 150, 8) {}

// print the OldNinja's data
string OldNinja::print()
{
    string result = "";
    if (this->getHit() > 0)
    {
        result = "N " + this->getName() + " " + to_string(this->getHit()) +\
                 " (" + to_string(this->getLocation().getx()) + "," + to_string(this->getLocation().gety()) + ")";
    }

    else
    {
        result = "N (" + this->getName() + ") " +\
                 " (" + to_string(this->getLocation().getx()) + "," + to_string(this->getLocation().gety()) + ")";
    }

    return result;
}