#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

#include "player.hpp"
//using namespace ariel;
#pragma once

namespace ariel{

    class Game
    {
        private:
            Player* p1; // player number 1
            Player* p2; // player number 2
            string* turnMemory; // array to save the turn's stats

            
        public:
            Game(Player pl1, Player pl2);
            //~Game();
            Player* getP1();
            Player* getP2();
            void playTurn();
            void printLastTurn(); // print the last turn stats.
            void playAll(); //playes the game untill the end
            void printWiner(); // prints the name of the winning player
            void printLog(); // prints all the turns played one line per turn
            void printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
    };
    
}