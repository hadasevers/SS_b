#include <stdexcept>

# include "Character.hpp"
# include "Team.hpp"

using namespace std;
using namespace ariel;


//====== Team implemence ======//

Team::Team(Character *Ldr) : leader(Ldr)
{
    this->warrior.push_back(Ldr);
    this->size = 1;
    Ldr->setInto();
}

Team::~Team()
{
    /*
    for (Character* war : warrior) {
            delete war;
        }
        */
    
    while (!this->warrior.empty())
    {
        delete(this->warrior.back());
        this->warrior.pop_back();
    }
    
}

void Team::add(Character *crt)
{
    if ((size >= 10) || (crt->getInto() == true)) throw __EXCEPTIONS;
    else 
    {
        this->warrior.push_back(crt);
        crt->setInto();
    }

}

void Team::attack(Team *other)
{
    cout << "Team attack" << endl;
}

int Team::stillAlive() const
{
    return 0;
}

void Team::print() const
{
    cout << "Team print" << endl;
}

void Team::setLeader(Character *newLd)
{
    this->leader = newLd;
}

Character* Team::getLeader()
{
    return this->leader;
}

vector<Character*> Team::gerWarrior()
{
    return this->warrior;
}

//void Team::setSize(int num)
//{
//    this->size = num;
//}

int Team::getSize()
{
    return this->size;
}




//====== Team2 implemence ======//


Team2::Team2(Character *Ldr): Team(Ldr) {}

void Team2::add(Character *crt) 
{
    cout << "add Team2" << endl;
}

void Team2::attack(Team *other)
{
    cout << "attack Team2" << endl;
}

int Team2::stillAlive() const
{
    return 0;
}

void Team2::print() const
{
    cout << "print Team2" << endl;
}



//====== SmartTeam implemence ======//


SmartTeam::SmartTeam(Character *Ldr) : Team(Ldr) {}

void SmartTeam::add(Character *crt) 
{
    cout << "add SmartTeam" << endl;
}

void SmartTeam::attack(Team *other)
{
    cout << "attack SmartTeam" << endl;
}

int SmartTeam::stillAlive() const
{
    return 0;
}

void SmartTeam::print() const
{
    cout << "print SmartTeam" << endl;
}
