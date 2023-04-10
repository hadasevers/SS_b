#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <string>
using namespace std;

#include "card.hpp"
using namespace ariel;


//constructor - create a card
Card::Card(int num, string type)
{
    this->number = num;
    this->type = type;

    // update the "name" of the card's number
    if (num == 1) this->strNum = "Ace";
    else if (((num < 11) and (num > 1)) or (num == 0)) this->strNum = to_string(num);
    else if (num == 11) this->strNum = "Jack";
    else if (num == 12) this->strNum = "Queen";
    else this->strNum = "King";
}

//return the num of the card
int Card::getNum()
{
    return this->number;
}

//return the "name" of the card's number
string Card::getStrNum()
{
    return this->strNum;
}

//return the type of the card
string Card::getType()
{
    return this->type;
}
