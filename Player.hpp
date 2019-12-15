/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the class declaration for Player
** It contains private data members and public methods called
** that allow the Player to to attack, collect coins, interact with
** objects.
******************************************************************************/
#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include "Character.hpp"
#include <vector>
#include "Object.hpp"
using std::vector;

class Player : public Character
{
    private:
        vector <Object*> backpack;
        Space* location;
        int pelts;
        
    
    public:
        //default constructor
        Player();
    
        void setPelts(int numPelts);
        int getPelts();
        void addPelts(int numPelts);
        int getBackpackSize();
        void addObject(Object* anObject);
        bool removeObject(string anObject);
        void showObjects();
        bool checkifWon();
        vector<Object*>& getBackpack();

        
    
        
        //virtual methods
        int Attack() override;
        int CharacterTrait() override;
        int randomCoins() override;
        
    
        //destructor
        ~Player() override;
};

#endif

