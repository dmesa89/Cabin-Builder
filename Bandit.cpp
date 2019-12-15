/***************************************************************************
** Project Name: Final Project
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the class source code for Bandit
** It contains a default constructor, destructor, and virtual
** methods, that allow the class to attack, defend and
** set characteristic.
******************************************************************************/

#include "Bandit.hpp"
using std::cout;
using std::endl;


/***************************************************************************
** Bandit::Bandit()
** This is the default constructor. It initializes all the member
** variables of the base class.
******************************************************************************/
Bandit::Bandit()
{
    name = "Bandit";
    damage = 0;
    strengthPoints = 8;
    characteristic = false;
    aliveOrDead = true;
    setSquare('C');
}

/***************************************************************************
** int Bandit::Attack()
** This is a method that rolls a 10 sided die to calculate
** total damage from class. It takes in no parameters and returns
** an int that is the damage.
******************************************************************************/
int Bandit::Attack()
{
    die.setSides(10);
    damage = die.rollingDie();
    
    return damage;

}


/***************************************************************************
** int Bandit::CharacterTrait()
** This is the a method that sets the character trait of the class
** takes in no parameters and returns an int that is the character
** trait.
******************************************************************************/
int Bandit::CharacterTrait()
{
    die.setSides(3);
    return die.rollingDie();
}

Bandit::~Bandit()
{}

/***************************************************************************
**int Bandit::randomCoins()
** This method returns an int that is the random amount of
** coins. It takes no parameters. 
******************************************************************************/
int Bandit::randomCoins()
{
    die.setSides(10);
    return die.rollingDie();
}
