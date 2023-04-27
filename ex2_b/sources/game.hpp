#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

#include "player.hpp"
//using namespace ariel;
#pragma once

namespace ariel{

    class Game
    {
        public:
            Player &p1;          // player number 1
            Player &p2;          // player number 2
            vector<string> turnMemory; // vector to save the turn's stats
            int countTurns;      // count the turn's number
            int drawTurns;       // count the  draw turn's number

            Game(Player& pl1, Player& pl2);
            void divide();       // divide the cards between the two players
            void playTurn();     // play a one turn
            void printLastTurn();// print the last turn stats.
            void playAll();      //play the game untill the end
            void printWiner();   // prints the name of the winning player
            void printLog();     // prints all the turns played one line per turn
            void printStats();   // for each player prints basic statistics: win rate, cards won, draw rate and amount of draws that happand.
    };
    
}