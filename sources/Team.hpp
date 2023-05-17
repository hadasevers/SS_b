#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Point.hpp"


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
            vector<Character*> gerWarrior();
            //void setSize(int num);
            int getSize();
            
        //public:
            Team(Character *Ldr);
            virtual void add(Character *crt);
            virtual void attack(Team *other);
            virtual int stillAlive() const;
            virtual void print() const;
            virtual ~Team();   
            Team(const Team&) = delete;
            Team(Team&&) = delete;
            Team& operator=(const Team&) = delete;     
            Team& operator=(Team&&) = delete;
    };



    class Team2 : public Team
    {
        public:
            Team2(Character *Ldr);
            void add(Character *crt) override;
            void attack(Team *other) override;
            int stillAlive() const override;
            void print() const override;
    };


    class SmartTeam : public Team
    {
        public:
            SmartTeam(Character *Ldr);
            void add(Character *ctr) override;
            void attack(Team *other) override;
            int stillAlive() const override;
            void print() const override;
    };
    
}