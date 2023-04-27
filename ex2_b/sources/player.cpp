#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

#include "player.hpp"
#include "card.hpp"
using namespace ariel;

// create a new player
Player::Player(string name)
{
    this->name = name;
    this->stack = {}; // empty stack
    this->cardsLost = 0;
    this->cardsWon = 0;
    this->doWin = 0;
}


// return the name of the player
string Player::getName()
{
    return this->name;
}

// update the cards stack in the beginning of the play 
void Player::setStack(vector<Card> stc)
{
    this->stack = stc;
}


//return the number of the cards in the stack - left
int Player::stacksize()
{
    return this->stack.size();
}


//return the amount of cards the player lost
int Player::getCardsLost()
{
    return this->cardsLost;
}


//set the number of the cards the player left
void Player::setCardsLost(int num)
{
    this->cardsLost = this->cardsLost + num;
}


//return the number of the cards the player won
int Player::cardesTaken()
{
    return this->cardsWon;
}


//set the number of the cards the player won
void Player::addMoreTaken(int num)
{
    this->cardsWon = this->cardsWon + num;
} 


//return the win rate statistics
int Player::getDoWin()
{
    return this->doWin;
}


//set the win rate statistics
void Player::addDoWin()
{
    this->doWin += 1;
}


// return the current card
Card Player::getCard()
{
    Card now = this->stack.back();
    this->stack.pop_back();
    return now;
}




