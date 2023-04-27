#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

#include "card.hpp"
#pragma once

namespace ariel{

    class Player
    {
        private:
            string name;        // name of the player
            vector<Card> stack; // the current stack
            int cardsLost;      // amount of cards the player lost
            int cardsWon;       // the number of the cards the player won
            int doWin;          // win rate statistics

        public:
            Player(string name);// create a new player
            string getName();   // return the name of the player
            int stacksize();    // return the number of the cards in the stack
            int getCardsLost(); // return the number of the cards the player left
            void setCardsLost(int n);  // set the number of the cards the player left
            int cardesTaken();  // return the number of the cards the player won
            void addMoreTaken(int n);  // set the number of the cards the player won
            int getDoWin();     // return the win rate statistics
            void addDoWin();    // add the win rate statistics
            Card getCard();     // return current card
            void setStack(vector<Card> stc); // update the cards stack in the beginning of the play 
    };
}
