#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
using namespace ariel;



//constructor - create a game
Game::Game(Player p1, Player p2)
{
    this->p1 = &p1;
    this->p2 = &p2;
    this->turnMemory = {}; // new string[26];
}


//destructor
//Game::~Game() = default;

Player* Game::getP1()
{
    return this->p1;
}


Player* Game::getP2()
{
    return this->p2;
}


void Game::playTurn()
{
    this->p1->setDoWin(1);
    this->p2->setDoWin(1);
}


// print the last turn stats.
void Game::printLastTurn()
{}


//playes the game untill the end
void Game::playAll()
{
    for(int i=0; i<10; i++)
    {
        this->playTurn();
    }
}


// prints the name of the winning player
void Game::printWiner()
{}


// prints all the turns played one line per turn
void Game::printLog()
{}


// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
void Game::printStats()
{}