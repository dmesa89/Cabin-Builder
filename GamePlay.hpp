/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the class declaration for GamePlay.
** It contains private data members and public methods called
** that runs the movement of player and interaction with
** objects, characters and observations.
******************************************************************************/

#ifndef GamePlay_hpp
#define GamePlay_hpp

#include "Character.hpp"
#include "InputValidation.hpp"
#include "Player.hpp"
#include "Bear.hpp"
#include "Bandit.hpp"
#include "Merchant.hpp"
#include "Board.hpp"
#include "Die.hpp"
#include "Space.hpp"
#include <iostream>
#include <random>

using std::cout;
using std::endl;

class GamePlay
{
    private:
        Player* player;
        Space* playerLocation;
        Character* charPlayerLocation;
        Object* objPlayerlocation;
        Observation* obsPlayerLocation;
        Merchant* merchPlayerLocation;
        Board* myBoardPtr;
        bool gameState;
        bool won;
    
    public:
    void runGame();
    void intro();
    void rules();
    void changePlayerName();
    int menu();
    int moveMenu();
    void move(int aMove);
    void interact();
    void interaction(Object* aPlayerLocation);
    void interaction(Character* aPlayerLocation);
    void interaction(Observation* aPlayerLocation);
    void interaction(Merchant* aPlayerLocation);
    void randomSquareSwap(Space* aPlayerLocation);
    void battle();
    void inventory();
    void checkPurse();
    void displayMap();
    

}; 

#endif /* GamePlay_hpp */
