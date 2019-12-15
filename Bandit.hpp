/***************************************************************************
** Project Name: Final Project
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the class declaration for Bandit
**It contains a base class Character, a default constructor
** and virtual public methods that allow the  derived
**class to attack, defend and its own characteristic.
******************************************************************************/

//include guards
#ifndef Bandit_hpp
#define Bandit_hpp

#include <iostream>
#include "Character.hpp"

class Bandit : public Character
{
    private:
    
    
    public:
        //default constructor
        Bandit();
        
        //virtual methods
        int Attack() override; 
        int CharacterTrait() override;
        int randomCoins() override;
        
    
        //destructor
        ~Bandit() override;

};

#endif 
