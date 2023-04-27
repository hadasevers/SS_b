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
    this->turnMemory = {}; // empty vctor
    this->countTurns = 0;
    this->drawTurns = 0;
    this->divide();        // in order to start, must divide the catds
}


// divide the cards to the players
void Game::divide()
{
    int startstack [4][13] = {0};  // memset the stack
    int c1 = 0, c2 = 0;            // count the cards the players were get
    vector<Card> s1, s2;           // the stack for every player
    int Pos1 = 0, Pos2 = 0;        // "pos1" - the card's type,  "pos2" - the card's number
    string type = "";              // string for the type

    // divide all the cards
    while ((c1 < 26) and (c2 < 26))
    {
        srand((unsigned) time(NULL));
        Pos1 = rand()%(4);
        Pos2 = rand()%(13);
        if (startstack[Pos1][Pos2] == 1)  // checking if this card has already been divided to any player
        {
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
        // set the type according to the "pos1"
        if (Pos1 == 0) type = "Hearts";
        else if (Pos1 == 1) type = "Diamonds";
        else if (Pos1 == 2) type = "Clubs";
        else type = "Spades";

        Card cr(Pos2, type);         // creat a card according to the data
        s1.push_back(cr);            // divide the card to player number 1
        c1 += 1;                     // the number of cards that player number 1 received increases
        startstack[Pos1][Pos2] = 1;  // marking that this card was divided
        


        // same thing - now for player number 2
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

    // update the stack of the players
    this->p1.setStack(s1);
    this->p2.setStack(s2);
}


void Game::playTurn()
{ 
    // checking if the cards finished or the player 1 is same to player 2
    if ((&(this->p1) == &(this->p2)) or ( this->p1.stacksize() == 0))
    {
        throw "exception";
    }
    
    else
    {        
        int turn = 1;       // count how times the player get cards - to know how many card the winner in this turn wiil be take 
        Card p1_card = this->p1.getCard();  // get card
        Card p2_card = this->p2.getCard();

        // the number of player 1 is bigger, or the number is 1 and the number of player 2 is 2
        if (((p1_card.getNum() > p2_card.getNum()) and (p1_card.getNum() != 2)) or ((p1_card.getNum() == 1) and (p2_card.getNum() == 2)))
        {
            this->p1.addDoWin();     // update player 1 win in this time
            this->p1.addMoreTaken(2);// update the card's number he take
            this->p2.setCardsLost(1);// update the card's number that player 2 lost
            this->countTurns += 1;   // update the turn's number in the play
            // update the turn stats
            this->turnMemory.push_back(this->p1.getName() + " played " + p1_card.getStrNum() + " of " + p1_card.getType() + " " + this->p2.getName() + " played " + p2_card.getStrNum() + " of " + p2_card.getType() + ". " + p1.getName() + " wins.");
        }

        // the number of player 2 is bigger, or the number is 1 and the number of player 1 is 2
        else if (p1_card.getNum() != p2_card.getNum())
        {   
            this->p2.addDoWin();
            this->p2.addMoreTaken(2);
            this->p1.setCardsLost(1);
            this->countTurns += 1;
            this->turnMemory.push_back(this->p1.getName() + " played " + p1_card.getStrNum() + " of " + p1_card.getType() + " " + this->p2.getName() + " played " + p2_card.getStrNum() + " of " + p2_card.getType() + ". " + p2.getName() + " wins.");
        }

        // the numbers of player 1 and 2 is aqual
        else
        {
            int fin = 0;               // flag if the card finish
            string this_turn = "";     // string for update the turn stats
            while ((this->p1.stacksize() > 0) and (fin != 1))   
            {
                this->drawTurns += 1;  // another draw a card
                if (this_turn != "") this_turn += " "; // If this is not the first draw - connect the stats
                this_turn += this->p1.getName() + " played " + p1_card.getStrNum() + " of " + p1_card.getType() + " " + this->p2.getName() + " played " + p2_card.getStrNum() + " of " + p2_card.getType() + ". Draw.";
                this->p1.getCard();    // get a card before the "war"
                this->p2.getCard();
                turn += 1;             // another time - draw a card

                if (this->p1.stacksize() > 0)
                {
                    p1_card = this->p1.getCard(); // get a card to the "war"
                    p2_card = this->p2.getCard();
                    turn += 1;                    // another time - draw a card
                    //this->playTurn();
                    if (this->p1.stacksize() > 0)
                    {
                        // check who is the winner - like before
                        if (((p1_card.getNum() > p2_card.getNum()) and (p1_card.getNum() != 2)) or ((p1_card.getNum() == 1) and (p2_card.getNum() == 2)))
                        {
                            this->p1.addDoWin();
                            this->p1.addMoreTaken(2*turn);
                            this->p2.setCardsLost(1);
                            this->countTurns += 1;
                            this_turn = this_turn + " " + this->p1.getName() + " played " + p1_card.getStrNum() + " of " + p1_card.getType() + " " + this->p2.getName() + " played " + p2_card.getStrNum() + " of " + p2_card.getType() + ". " + p1.getName() + " wins.";
                            fin = 1;    // update that there is a winner - and this turn finish
                            break;
                        }
                        else if (p1_card.getNum() != p2_card.getNum())
                        {
                            this->p2.addDoWin();
                            this->p2.addMoreTaken(2*turn);
                            this->p1.setCardsLost(1);
                            this->countTurns += 1;
                            this_turn = this_turn + " " + this->p1.getName() + " played " + p1_card.getStrNum() + " of " + p1_card.getType() + " " + this->p2.getName() + " played " + p2_card.getStrNum() + " of " + p2_card.getType() + ". " + p2.getName() + " wins.";
                            fin = 1;
                            break;
                        }
                        else continue;  // if there is another draw - continue to another turn
                    }
                }
            }

            // the turn stopped because the card finished, without a winner
            if (fin == 0)
            {
                this->p1.addMoreTaken(turn); // update the card's number the players take - divided equally between them
                this->p2.addMoreTaken(turn);
                this->countTurns += 1;       // update the turn's number
                this->drawTurns += 1;        // update the draw turn's number
                //if (this_turn != "") this_turn += " "; // If this is not the first draw - connect the stats
                //this_turn += this->p1.getName() + " played " + p1_card.getStrNum() + " of " + p1_card.getType() + " " + this->p2.getName() + " played " + p2_card.getStrNum() + " of " + p2_card.getType() + ". Draw.";
                this_turn = this_turn + " the card finished, this turn finish without winner.";  // add to the stat
            }

            this->turnMemory.push_back(this_turn); // update the stat
            
        }
        
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
    cout << endl << "the winner is: " << winner << endl << endl;
}


// prints all the turns played one line per turn
void Game::printLog()
{
    for_each(this->turnMemory.begin(), this->turnMemory.end(), [](const auto& elem)
    {
        cout << elem << endl;  // printing one by one element
                               // separated with space
    });
}


// for each player prints basic statistics: win rate, cards won, draw rate and amount of draws that happand.
void Game::printStats()
{
    cout << endl << "--- statistics: ---" << endl;

    // How many turns each player won out of all the turns in the game
    cout << "win rate:    " << this->p1.getName() << " : "  << this->p1.getDoWin() << "/" << this->countTurns << "   " << this->p2.getName()
         << " : "  << this->p2.getDoWin() << "/" << this->countTurns << endl;

    // How many cards each player take from all the cards in the game
    cout << "cards won:   " << this->p1.getName() << " : "  << this->p1.cardesTaken() << "/52" << "   " << this->p2.getName()
         << " : "  << this->p2.cardesTaken() << "/52" << endl;
         
    // How many draw turn was happend from all the draw cards in the game
    cout << "draw rate:   "  << this->drawTurns << "/" << this->countTurns + this->drawTurns  << endl; 

    // How many draw turn was happend
    cout << "amount draw: "  << this->drawTurns << endl; 
}