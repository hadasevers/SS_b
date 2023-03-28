#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

#include "player.hpp"
#include "card.hpp"
using namespace ariel;

// create a new player
Player::Player(string name)
{

    //this->name = new char[len(name)+1];
    this->name = name;
    this->stack = {};//new Card*[26]; // empty stack
    this->numOfCards = 26;
    this->cardsLeft = 0;
    this->cardsWon = 0;
    this->doWin = 0;
    this->howCards = 0;
}

// destructor
//Player::~Player() = default;

// return the name of the player
string Player::getName()
{
    return "Hadas";
}

// return the stack
Card** Player::getStack()
{
    return this->stack;
}

//set the stack
void Player::setStack(Card** newStack)
{
    //delete[] this->stack;
    this->stack = newStack;
}

//return the number of the cards in the stack - left
int Player::stacksize()
{
    return 0;
}

//return the amount of cards the player lost
int Player::getCardsLost()
{
    return 0;
}

//set the number of the cards the player left
void Player::setCardsLost(int num)
{
    this->cardsLeft = num;
}

//return the number of the cards the player won
int Player::cardesTaken()
{
    return 0;
}

//set the number of the cards the player won
void Player::setCardsTaken(int num)
{
    this->cardsWon = num;
}

//return the win rate statistics
int Player::getDoWin()
{
    return 0;
}

//set the win rate statistics
void Player::setDoWin(int num)
{
    this->doWin = 0;
}

//return the cards won statistics
int Player::getHowCard()
{
    return 0;
}

//set the cards won statistics
void Player::setHowCard(int num)
{
    this->howCards = 0;
}