#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
using namespace ariel;


//constructor - create a game
Game::Game(Player& pl1, Player& pl2) : p1(pl1), p2(pl2)
{
    //this->p1 = p1;
    //this->p2 = p2;
    this->turnMemory = {}; // new string[26];
    this->countTurns = 0;
    this->drawTurns = 0;
    this->divide();
}


//destructor
//Game::~Game() = default;


// divide the cards to the players
void Game::divide()
{
    int startstack [4][13] = {0};
    int c1 = 0, c2 = 0;
    vector<Card> s1, s2;
    int Pos1 = 0, Pos2 = 0;
    string type = "Hearts";

    while ((c1 < 26) and (c2 < 26))
    {
        Pos1 = rand()%(4);
        Pos2 = rand()%(13);
        if (startstack[Pos1][Pos2] == 1){
            while (startstack[Pos1][Pos2] == 1)
            {
                if (Pos2 == 12){
                    Pos2 = -1;
                    if (Pos1 == 3) Pos1 = -1;
                    Pos1 += 1;
                } 
                Pos2 +=1;
            }
        }
        if (Pos1 == 0) type = "Hearts";
        else if (Pos1 == 1) type = "Diamonds";
        else if (Pos1 == 2) type = "Clubs";
        else type = "Spades";

        Card cr(Pos2, type);
        s1.push_back(cr);
        c1 += 1;
        startstack[Pos1][Pos2] = 1;

        
        //if (c1 >= c2)
        //{
        //    s1.push_back(cr);
        //    c1 += 1;
        //}

        //else
        //{
        //    s2.push_back(cr);
        //    c2 += 1;
        //}

        //startstack[Pos1][Pos2] = 1;
        

        Pos1 = rand()%(4);
        Pos2 = rand()%(13);
        if (startstack[Pos1][Pos2] == 1){
            while (startstack[Pos1][Pos2] == 1)
            {
                if (Pos2 == 12){
                    Pos2 = -1;
                    if (Pos1 == 3) Pos1 = -1;
                    Pos1 += 1;
                } 
                Pos2 +=1;
            }
        }
        if (Pos1 == 0) type = "Hearts";
        else if (Pos1 == 1) type = "Diamonds";
        else if (Pos1 == 2) type = "Clubs";
        else type = "Spades";

        Card cr2(Pos2, type);
        s2.push_back(cr2);
        c2 += 1;
        startstack[Pos1][Pos2] = 1;
    }

    this->p1.setstacksize();   //?????????
    this->p2.setstacksize();    //??????????
}


void Game::playTurn()
{ 
    //  addressof(p1) == addressof(p2)
    if ( &p1 == &p2)
    {
        throw "exception";
    }

    else
    {
        int finInDraw = 0;
        int turn = 1;
        string this_turn = "";
        Player *pwin = nullptr;
        Player *psoc = nullptr;
        Card p1_card = this->p1.getCard();
        Card p2_card = this->p2.getCard();

        if (this->p1.stacksize() > 0)
        {
            if (((p1_card.getNum() > p2_card.getNum()) and (p1_card.getNum() != 2)) or ((p1_card.getNum() == 1) and (p2_card.getNum() == 2)))
            {
                pwin = &this->p1;
                psoc = &this->p2;
                //break;
            }
            else if (p1_card.getNum() != p2_card.getNum())
            {
                pwin = &this->p2;
                psoc = &this->p1;
                //break;
            }
            else
            {
                this->drawTurns += 1;
                while (this->p1.stacksize() > 0)
                {
                    this->p1.getCard();
                    this->p2.getCard();
                    turn += 1;
                    if (this_turn != "") this_turn += " ";
                    this_turn += this->p1.getName() + " played " + p1_card.getStrNum() + " of " + p1_card.getType() + " " + this->p2.getName() + " played " + p2_card.getStrNum() + " of " + p2_card.getType() + ". " + " Draw."; 
                    if (this->p1.stacksize() > 0)
                    {
                        p1_card = this->p1.getCard();
                        p2_card = this->p2.getCard();
                        turn += 1;
                        if (((p1_card.getNum() > p2_card.getNum()) and (p1_card.getNum() != 2)) or ((p1_card.getNum() == 1) and (p2_card.getNum() == 2)))
                        {
                            pwin = &this->p1;
                            psoc = &this->p2;
                            break;
                        }
                        else if (p1_card.getNum() != p2_card.getNum())
                        {
                            pwin = &this->p2;
                            psoc = &this->p1;
                            break;
                        }
                        else
                        {
                            this->drawTurns += 1;
                            continue;
                        }
                    }
                    else
                    {
                        finInDraw = 1;
                        break;
                    } 
                }
                
            }  
        }

        if (finInDraw == 0)
        {
            if (this_turn != "") this_turn += " ";
            this_turn += this->p1.getName() + " played " + p1_card.getStrNum() + " of " + p1_card.getType() + " " + this->p2.getName() + " played " + p2_card.getStrNum() + " of " + p2_card.getType() + ". " + pwin->getName() + " wins.";
            pwin->addDoWin();
            pwin->addMoreTaken(2*turn);
            psoc->setCardsLost(turn);
            //this->countTurns += 1;
            //this->turnMemory.push_back(this_turn);
        }

        else
        {
            this->p1.addMoreTaken(turn);
            this->p2.addMoreTaken(turn);
            this->drawTurns += 1;
            //this->countTurns += 1;
            //this->turnMemory.push_back(this_turn);
        }

        this->countTurns += 1;
        this->turnMemory.push_back(this_turn);
    }

}


// print the last turn stats.
void Game::printLastTurn()
{
    cout << this->turnMemory.back() << endl;
}


//playes the game untill the end
void Game::playAll()
{
    while (this->p1.stacksize() > 0)
    {
        //this->countTurns += 1;
        this->playTurn();
    }
}


// prints the name of the winning player
void Game::printWiner()
{
    string winner = "";
    if (this->p1.cardesTaken() > this->p2.cardesTaken()) winner = this->p1.getName();
    else if (this->p1.cardesTaken() < this->p2.cardesTaken()) winner = this->p2.getName();
    else winner = "Draw";
    cout << "the winner is: " << winner << endl;
}


// prints all the turns played one line per turn
void Game::printLog()
{ //?? its good??
    for_each(this->turnMemory.begin(),
             this->turnMemory.end(),
             [](const auto& elem) {
 
                 // printing one by one element
                 // separated with space
                 cout << elem << endl;
             });
}


// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
void Game::printStats()
{
    cout << "statistics:" << endl;
    cout << " win rate:   " << this->p1.getName() << " : "  << this->p1.getDoWin() << "/" << this->countTurns << "   " << this->p2.getName()
         << " : "  << this->p2.getDoWin() << "/" << this->countTurns << endl;
    //cout << this->p2.getName() << " win rate: " << this->p2.getDoWin() << "/" << this->countTurns << endl;
    cout << " cards won:   " << this->p1.getName() << " : "  << this->p1.cardesTaken() << "/52" << "   " << this->p2.getName()
         << " : "  << this->p2.cardesTaken() << "/52" << endl;
    cout << "amount draw"  << endl; 
}































