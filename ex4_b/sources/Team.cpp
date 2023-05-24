#include <stdexcept>
#include <typeinfo>

# include "Character.hpp"
# include "Team.hpp"

using namespace std;
using namespace ariel;


//====== Team implemence ======//

Team::Team(Character *Ldr) : leader(Ldr)
{
    this->warrior.push_back(Ldr);
    this->size = 1;
    if(Ldr->getInto() == true) throw runtime_error("Appointing the same captain to different teams");
    else Ldr->setInto();
}

Team::~Team()
{
    while (!this->warrior.empty())
    {
        delete(this->warrior.back());
        this->warrior.pop_back();
    } 
}

void Team::add(Character *crt)
{
    if ((size >= 10) || (crt->getInto() == true)) throw runtime_error("runtime_error");
    else 
    {
        this->warrior.push_back(crt);
        crt->setInto();
        this->size++;
    }

}

void Team::attack(Team *other)
{
    if (other == nullptr) 
        throw invalid_argument("nullptr");

    else if (other->stillAlive() == 0)
        throw runtime_error("dead team");

    else if (other->stillAlive() > 0 && this->stillAlive() > 0)
    {
        // if the leader died, choose new leader
        if (this->getLeader()->isAlive() == false)
        {
            this->setLeader(&this->closeCharacter(this));
        }

        Character *victim = &this->closeCharacter(other);
        
        // cowboy attack
        for (auto& it : this->warrior)
        {
            if (victim == nullptr)
                break;

            if (victim->isAlive() == false)
                victim = &this->closeCharacter(other);
            
            Cowboy* cowboy = dynamic_cast<Cowboy*>(it);

            if (cowboy)
            {
                if (cowboy->isAlive() == true)
                {
                    if(cowboy->hasboolets())
                        cowboy->shoot(victim);
                    else cowboy->reload(); 
                }
            }
        }

        // ninja attack
        for (auto& it : this->warrior)
        {
            if (victim == nullptr)
                break;

            if (victim->isAlive() == false)
                victim = &this->closeCharacter(other);

            if (victim == nullptr)
                break;

            Ninja* ninja = dynamic_cast<Ninja*>(it);

            if (ninja)
            {
                if (ninja->isAlive() == true)
                {
                    if(ninja->distance(victim) <= 1)
                        ninja->slash(victim);
                    else ninja->move(victim);
                }
            }
        }
    }
}


int Team::stillAlive()
{
    int count = 0;

    for (auto& it : this->warrior)
    {
        Cowboy* cowboy = dynamic_cast<Cowboy*>(it);

        if (cowboy)
        {
            if (cowboy->isAlive() == true)
                count++;
        }
    }

    for (auto& it : this->warrior)
    {
        Ninja* ninja = dynamic_cast<Ninja*>(it);
        if (ninja)
        {
            if (ninja->isAlive() == true)
                count++;
        }
    }

    return count;
}


void Team::print()
{
    cout << "The warrior:" << endl;

    for (auto& it : this->warrior)
    {
        Cowboy* cowboy = dynamic_cast<Cowboy*>(it);

        if (cowboy)
        {
            cout << "   " << cowboy->print() << endl;
        }
    }

    for (auto& it : this->warrior)
    {
        Ninja* ninja = dynamic_cast<Ninja*>(it);

        if (ninja)
        {
            cout << "   " << ninja->print() << endl;
        }
    }
}

void Team::setLeader(Character *newLd)
{
    if(newLd != nullptr)
    {
        if (newLd->isAlive() == false) throw runtime_error("deid Character");
        this->leader = newLd;
    }
}

Character* Team::getLeader()
{
    return this->leader;
}

vector<Character*>& Team::getWarrior()
{
    return this->warrior;
}

void Team::setSize(int num)
{
    this->size = num;
}

int Team::getSize()
{
    return this->size;
}

Character& Team::closeCharacter(Team *attacked)
{
    Character *close = nullptr;
    double dist = 10000000;
    
    for (auto& it : attacked->getWarrior())
    {
       // Cowboy* cowboy = dynamic_cast<Cowboy*>(it);

        //if (cowboy)
        //{
            if(it->isAlive()==true && it->distance(this->getLeader()) < dist)
            {
                dist = it->distance(this->getLeader());
                close = it;
            }
        //}
    }

    // for (auto& it : attacked->getWarrior())
    // {
    //     Ninja* ninja = dynamic_cast<Ninja*>(it);

    //     if (ninja)
    //     {
    //         if(it->isAlive()==true && it->distance(this->getLeader()) < dist)
    //         {
    //             dist = it->distance(this->getLeader());
    //             close = it;
    //         }
    //     }
    // }

    // for (auto& it : this->getWarrior())
    // {
    //     if(it->isAlive()==true && it->distance(this->getLeader()) < dist)
    //     {
    //         dist = it->distance(this->getLeader());
    //         close = it;
    //     }
    // }

    return *close;
}







//====== Team2 implemence ======//


Team2::Team2(Character *Ldr): Team(Ldr){}

void Team2::add(Character *crt) 
{
    if ((this->getSize() >= 10) || (crt->getInto() == true)) throw runtime_error("runtime_error");
    else 
    {
        this->getWarrior().push_back(crt);
        crt->setInto();
        this->setSize(this->getSize()+1);
    }
}

void Team2::attack(Team *other)
{
    if (other == nullptr)
        throw invalid_argument("nullptr");

    else if (other->stillAlive() == 0)
        throw runtime_error("dead team");

    else if (other->stillAlive() > 0 && this->stillAlive() > 0)
    {
        // if the leader died, choose new leader
        if (this->getLeader()->isAlive() == false)
        {
            this->setLeader(&this->closeCharacter(this));
        }

        Character *victim = &this->closeCharacter(other);

        // cowboy attack
        for (auto& it : this->getWarrior())
        {
            if (victim == nullptr)
                break;

            if (victim->isAlive() == false)
                victim = &this->closeCharacter(other);

            Cowboy* cowboy = dynamic_cast<Cowboy*>(it);

            if (cowboy)
            {
                if (cowboy->isAlive() == true)
                {
                    if(cowboy->hasboolets())
                        cowboy->shoot(victim);
                    else cowboy->reload(); 
                }
            }

            else
            {
                Ninja* ninja = dynamic_cast<Ninja*>(it);

                if (ninja)
                {
                    if (ninja->isAlive() == true)
                    {
                        if(ninja->distance(victim) <= 1)
                           ninja->slash(victim);
                        else ninja->move(victim);
                    }
                }
            } 
        }
    }
}

int Team2::stillAlive()
{
    int count = 0;

    for (auto& it : this->getWarrior())
    {
        if (it->isAlive() == true)
                count++;
    }

    return count;
}

void Team2::print()
{
    cout << "The warrior:" << endl;
    for (auto& it : this->getWarrior())
    {
        cout << "   " << it->print() << endl;
    }
}



//====== SmartTeam implemence ======//


SmartTeam::SmartTeam(Character *Ldr) : Team(Ldr) {}

void SmartTeam::add(Character *crt) 
{
    if ((this->getSize() >= 10) || (crt->getInto() == true)) throw runtime_error("runtime_error");
    else 
    {
        this->getWarrior().push_back(crt);
        crt->setInto();
        this->setSize(this->getSize()+1);
    }
}

void SmartTeam::attack(Team *other)
{
    if (other == nullptr)
        throw invalid_argument("nullptr");

    else if (other->stillAlive() == 0)
        throw runtime_error("dead team");

    else if (other->stillAlive() > 0 && this->stillAlive() > 0)
    {
        // if the leader died, choose new leader
        if (this->getLeader()->isAlive() == false)
        {
            this->setLeader(&this->closeCharacter(this));
        }

        Character *victim = &this->closestToNinja(other);

        // cowboy attack
        for (auto& it : this->getWarrior())
        {
            if (victim == nullptr)
                break;

            if (victim->isAlive() == false)
                victim = &this->closestToNinja(other);

            Cowboy* cowboy = dynamic_cast<Cowboy*>(it);

            if (cowboy)
            {
                if (cowboy->isAlive() == true)
                {
                    if(cowboy->hasboolets())
                        cowboy->shoot(victim);
                    else cowboy->reload(); 
                }
            }

            else
            {
                Ninja* ninja = dynamic_cast<Ninja*>(it);

                if (ninja)
                {
                    if (ninja->isAlive() == true)
                    {
                        if(ninja->distance(victim) <= 1)
                           ninja->slash(victim);
                        else ninja->move(victim);
                    }
                }
            } 
        }
    }
}

int SmartTeam::stillAlive()
{
    int count = 0;
    
    for (auto& it : this->getWarrior())
    {
        Character* character = dynamic_cast<Character*>(it);

        if (character)
        {
            if (character->isAlive() == true)
                count++;
        }
    }
    return count;
}

void SmartTeam::print()
{
    cout << "The warrior:" << endl;
    for (auto& it : this->getWarrior())
    {
        cout << "   " << it->print() << endl;
    }
}

// return the victim how close to biggest num of ninja
Character& SmartTeam::closestToNinja(Team *attacked)
{
    Character *close = nullptr;
    int ninjas = 10;

    for (auto& att : attacked->getWarrior())
    {
        if(att->isAlive()==true)
        {
            int count = 0;

            for(auto& crt : this->getWarrior())
            {
                Ninja* ninja = dynamic_cast<Ninja*>(crt);
                if(ninja && ninja->isAlive() == true && att->distance(ninja) <= 1)
                    count++;
            }

            if(count < ninjas)
            {
                ninjas = count;
                close = att;
            }                
        }
    }

    return *close;
}
