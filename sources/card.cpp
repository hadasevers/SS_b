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
Card::Card(int num, char type)
{
    this->number = num;
    this->type = type;
}

//destructor
//Card::~Card() = default;

//return stack of card
/*
Card* Card::cardsStack()
{
    return nullptr_t;
}
*/

//return the num of the card
int Card::getNum()
{
    return 1;
}

//return the type of the card
char Card::getType()
{
    return 'H';
}