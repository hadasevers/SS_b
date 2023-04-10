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
            int number;    // the card's number
            string strNum; // the "name" of the number 
            string type;   // Hearts, Diamonds, Clubs, Spades.

        public:
            Card(int num, string type); // create a card
            int getNum();               // return the num of the card
            string getStrNum();         // return the "name" of the num of the card 
            string getType();           // return the type of the card
    };
}