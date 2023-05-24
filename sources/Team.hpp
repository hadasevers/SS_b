#include <iostream>
#include <vector>
#include "Character.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"
//#include "Team2.hpp"


using namespace std;

#pragma once

namespace ariel
{
    class Team
    {
        private:
            vector<Character*> warrior;
            Character *leader;
            int size;

        public:
            void setLeader(Character *newLd);
            Character* getLeader();
            vector<Character*>& getWarrior();
            void setSize(int num);
            int getSize();
            
        //public:
            Team(Character *Ldr);
            virtual void add(Character *crt);
            virtual void attack(Team *other);
            virtual int stillAlive();
            virtual void print();
            virtual ~Team();   
            Team(const Team&) = delete;
            Team(Team&&) = delete;
            Team& operator=(const Team&) = delete;     
            Team& operator=(Team&&) = delete;
            Character& closeCharacter(Team *attacked);
    };

    class Team2 : public Team
    {
        public:
            Team2(Character *Ldr);
            void add(Character *crt) override;
            void attack(Team *other) override;
            int stillAlive() override;
            void print() override;
    };

    class SmartTeam : public Team
    {
        public:
            SmartTeam(Character *Ldr);
            void add(Character *ctr) override;
            void attack(Team *other) override;
            int stillAlive() override;
            void print() override;
            Character& closestToNinja(Team *attacked); // return the victim how close to biggest num of ninja
    };
    
}