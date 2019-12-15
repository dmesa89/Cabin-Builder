/***************************************************************************
** Project Name: Final Project
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the function declaration for Merchant
** It contains a default constructor, destructor, and virtual
** methods, that allow the class to interact with Player object.
******************************************************************************/
//include guards
#ifndef Merchant_hpp
#define Merchant_hpp

#include <iostream>
#include "Character.hpp"
#include "Water.hpp"
#include "Axe.hpp"
#include "Lumber.hpp"
#include "Nails.hpp"
#include "Hammer.hpp"
#include "InputValidation.hpp"
#include "Player.hpp"

using std::cout;
using std::endl;

class Merchant : public Space
{
private:
    Object* objectPointer;
    int strength;
    string name;
    Player* player;
    
    
public:
    //default constructor
    Merchant();
    void interact(Player* aPlayer);
    int intro();
    int buyIntro();
    int sellIntro();
    void sellStrengthPoints();
    void sellObject(int anObject);
    
    void buyObject(int anObject);
    void sellPelt();

    
    ~Merchant();
    void setSquare(char theSquare) override;
    
};

#endif 
