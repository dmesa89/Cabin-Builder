/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the class source code for  Wolf
** It contains a default constructor, destructor, and virtual
** methods, that allow the class to attack, defend and
** set characteristic.
******************************************************************************/

#include "Wolf.hpp"

/***************************************************************************
**Wolf::Wolf()
** This is the default constructor. It initializes all the member
** variables of the base class.
******************************************************************************/
Wolf::Wolf()
{
    name = "Wolf";
    damage = 0;
    strengthPoints = 5;
    characteristic = true;
    aliveOrDead = true;
    coins = randomCoins();
    setSquare('C');
}

/***************************************************************************
** int Wolf::Attack()
** This is the a method that rolls a 5 sided die once to calculate
** total damage from class. It takes in no parameters and returns
** an int that is the damage.
******************************************************************************/
int Wolf::Attack()
{
    die.setSides(5);
    damage = die.rollingDie();
    
    return damage;

}


/***************************************************************************
** int Wolf::CharacterTrait()
** This is a method that returns the character trait of the class
** This method  takes in no parameters and returns the trait.
******************************************************************************/
int Wolf::CharacterTrait()
{
    return 1;
}

Wolf::~Wolf()
{}

/***************************************************************************
**int Wolf::randomCoins()
** This method rolls a die to return random coins.
** It takes no parameters and returns an int.
******************************************************************************/
int Wolf::randomCoins()
{
    die.setSides(5);
    return die.rollingDie();
}
