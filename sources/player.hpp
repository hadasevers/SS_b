#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

#include "card.hpp"
//using namespace ariel;
#pragma once

namespace ariel{

    class Player
    {
        private:
            string name; // name of the player
            Card** stack;// the current stack
            int numOfCards; //the number of the cards in the stack - left
            int cardsLeft; //amount of cards the player lost
            int cardsWon; //the number of the cards the player won
            int doWin; //win rate statistics
            int howCards; //cards won statistics

        public:
            Player(string name);  //create a new player
            //~Player();  //destructor
            string getName();  //return the name of the player
            Card** getStack();  //return the stack
            void setStack(Card** newStack);  //set the stack
            int stacksize();  //return the number of the cards in the stack
            int getCardsLost();  //return the number of the cards the player left
            void setCardsLost(int n);  //set the number of the cards the player left
            int cardesTaken();  //return the number of the cards the player won
            void setCardsTaken(int n);  //set the number of the cards the player won
            int getDoWin();  //return the win rate statistics
            void setDoWin(int n);  //set the win rate statistics
            int getHowCard();  //return the cards won statistics
            void setHowCard(int n);  //set the cards won statistics
    };
}
