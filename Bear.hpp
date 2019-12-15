/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the class declaration for Bear
**It contains a base class Character, a default constructor
** and virtual public methods that allow the  derived
**class to attack, defend and its own characteristic.
******************************************************************************/
//include guards
#ifndef Bear_hpp
#define Bear_hpp

#include <iostream>
#include "Character.hpp"

class Bear : public Character
{
    private:
    
    public:
        //default constructor
        Bear();
        
        //virtual methods
        int Attack() override;
        int CharacterTrait() override;
        int randomCoins() override;
    
        //destructor
        ~Bear() override;
        
};

#endif 
