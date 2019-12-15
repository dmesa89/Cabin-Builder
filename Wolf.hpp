/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the class declaration for Wolf
**It contains a base class Character, a default constructor
** and virtual public methods that allow the  derived
**class to attack, defend and its own characteristic.
******************************************************************************/
//include guards
#ifndef Wolf_hpp
#define Wolf_hpp

#include <iostream>
#include "Character.hpp"

class Wolf : public Character
{
    private:
        
    
    public:
        //default constructor
        Wolf();
    
        //virtual methods
        int Attack() override;
        int CharacterTrait() override;
        int randomCoins() override;
    
        //destructor
        ~Wolf() override;

    
    
    
};

#endif 
