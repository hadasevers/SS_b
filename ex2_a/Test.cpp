#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

#include "doctest.h"

// check if the Players are different
bool samePlayers(Game game)
{
    if (&(game.getP1()[0]) == &(game.getP2()[0])) return true;
    //if ((game.getP1()->getName() == game.getP2()->getName()) && (game.getP1()->getDoWin() == game.getP2()->getDoWin()) && (game.getP1()->getHowCard() == game.getP2()->getHowCard())) return true; // all the details of the players is same, it's probably the same player
    else return false;
}


TEST_CASE("TEST 1 - WITHOUT ERROR")
{
    CHECK_NOTHROW(Player p1("Alice")); //true
    //CHECK_NOTHROW(Player p2()); //false - lack variable to create a player 

    Player p1("Alice");
    Player p2("Bob");
    CHECK_NOTHROW(Game game_1(p1,p2)); // true
    //CHECK_NOTHROW(Game game_2(p2)); // false - error - lack variable to start the game
    //CHECK_NOTHROW(Game game_3()); // false - error - lack variables to start the game

    Game game(p1,p2);
    CHECK_NOTHROW(game.playTurn()); // true
    CHECK_NOTHROW(game.playAll();); // true
}


// check if the Players are different
TEST_CASE("TEST 2 - 2 PLAYERS")
{
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Bob");

    Game game_1(p1,p2);
    Game game_2(p2,p2);
    Game game_3(p2,p3);

    CHECK(samePlayers(game_1) == false); // different Players
    CHECK(samePlayers(game_2) == true); // one Player
    CHECK(samePlayers(game_3) == false); // different Players with same name
}



// Throughout the game the amount of cards left for each player should be the same
TEST_CASE("TEST 3 - SAME AMOUNT OF CARDS")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    CHECK(p1.stacksize() == 26); // the number of cards each player has at the beginning is 26
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);

    game.playTurn();
    CHECK(((p1.stacksize() <= 25) && (p2.stacksize() <= 25) && (p1.stacksize() == p2.stacksize())) == true);

    for(int i=0; i<4; i++){
        game.playTurn();
    }
    CHECK(((p1.stacksize() <= 21) && (p2.stacksize() <= 21) && (p1.stacksize() == p2.stacksize())) == true);

    game.playAll();
    CHECK(((p1.stacksize() == 0) && (p2.stacksize() == 0)) == true);
}



// A normal amounts of total cards
// Throughout the game the amount of total cards should be 52
TEST_CASE("TEST 4 - TOTAL CARDS")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    CHECK(p1.stacksize() + p2.stacksize() == 52); // the number of cards each player has at the beginning is 26

    for(int i=0; i<5; i++){
        game.playTurn();
        CHECK(p1.stacksize() + p2.stacksize() + p1.cardesTaken() + p2.cardesTaken() == 52);
        CHECK(p1.stacksize() + p2.stacksize() < 52);
    }

    game.playAll();
    CHECK(p1.stacksize() + p2.stacksize() == 0);
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
}



// As long as the cards did not run out during the tiebreaker, the amount of cards won by each player is even
TEST_CASE("TEST 5 - EVEN OR ODD")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    while (p1.stacksize() != 0)
    {
        game.playTurn();
        if (p1.stacksize() != 0)
            CHECK(((p1.cardesTaken()%2 == 0) && (p2.cardesTaken()%2 == 0)) == true);
        // else - the game finish, so if the game finish during the "war" because the cards are gone, so  each of the players
        // tookn their cards, they maybe have taken an odd number of cards.
        // if the game finish as usual, the number of cards each took is  still even. 
    }
}


