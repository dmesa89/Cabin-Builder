/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the class source code for Bear
** It contains a default constructor, destructor, and virtual
** methods, that allow the class to attack, defend and
** set characteristic.
******************************************************************************/

#include "Bear.hpp"


/***************************************************************************
**Bear::Bear()
** This is the default constructor. It initializes all the member
** variables of the base class.
******************************************************************************/
Bear::Bear()
{
    name = "Bear";
    damage = 0;
    strengthPoints = 10;
    characteristic = true;
    aliveOrDead = true;
    coins = randomCoins();
    setSquare('C');
}

/***************************************************************************
** int Bear::Attack()
** This is the a method that rolls a 12 sided die  to calculate
** total damage from class. It takes in no parameters and returns
** an int that is the damage.
******************************************************************************/
int Bear::Attack()
{
    die.setSides(12);
    damage = die.rollingDie();
    
    return damage;

}

/***************************************************************************
** int Bear::CharacterTrait()
** This is the a method that sets the character trait of the class
** This method  takes in no parameters and has no return.
******************************************************************************/
int Bear::CharacterTrait()
{
    return 2;
}

Bear::~Bear()
{}

/***************************************************************************
**int Bear::randomCoins()
** This method returns a random int of coins. It takes no
** parameters
******************************************************************************/
int Bear::randomCoins()
{
    die.setSides(10); 
    return die.rollingDie();
}
