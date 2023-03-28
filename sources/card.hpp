#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;
#pragma once


//using namespace ariel;

namespace ariel{

    class Card
    {
        private:
            int number;  // the card's number
            char type; // 'H' for Hearts, 'D' for Diamonds, 'C' for Clubs, 'S' for Spades.

        public:
            Card(int num, char type); // create a card
            //~Card(); //destructor
            //Card* cardsStack(); // create a packet of cards
            int getNum(); // return the num of the card
            char getType(); // return the type of the card

    };
}