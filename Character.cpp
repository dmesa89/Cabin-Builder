/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the source code for class Character
**It contains set and get methods for the private members.
** and pure virtual public methods that allow the  derived
**class to attack, defend and its own characteristic.
******************************************************************************/

#include "Character.hpp"

/***************************************************************************
** string Character::getName()
** This method returns string name.
** It takes no parameters.
******************************************************************************/
string Character::getName() 
{ return name;}

/***************************************************************************
** void Character::setDamage(int aDamage)
** This method take in an int as a parameter and sets it to damage.
** It has no return.
******************************************************************************/
void Character::setDamage(int aDamage)
{ damage = aDamage;}

/***************************************************************************
** int Character::getDamage()
** This method returns int damage.
** It takes no parameters.
******************************************************************************/
int Character::getDamage()
{return damage;}

/***************************************************************************
** void Character::setStrengthPoints(int aStrengthPoints)
** This method take in an int as a parameter and sets it to strength.
** It has no return.
******************************************************************************/
void Character::setStrengthPoints(int aStrengthPoints)
{ strengthPoints = aStrengthPoints;}

/***************************************************************************
**int Character::getStrengthPoints()
** This method returns int strength points.
** It takes no parameters.
******************************************************************************/
int Character::getStrengthPoints()
{ return strengthPoints;}

/***************************************************************************
** void Character::setCharacteristic(bool aCharacteristic)
** This method take in a bool as a parameter and sets it to
** characteristic. It has no return.
******************************************************************************/
void Character::setCharacteristic(bool aCharacteristic)
{ characteristic = aCharacteristic;}

/***************************************************************************
**bool Character::getCharacteristic()
** This method returns bool characteristic.
** It takes no parameters.
******************************************************************************/
bool Character::getCharacteristic()
{ return characteristic; }

/***************************************************************************
** void Character::setAliveOrDead(int aLife)
** This method take in a bool as a parameter and sets it to
** aliveordead. It has no return.
******************************************************************************/
void Character::setAliveOrDead(int aLife)
{ aliveOrDead = aLife;}

/***************************************************************************
**bool Character::getAliveOrDead()
** This method returns bool alive or dead.
** It takes no parameters.
******************************************************************************/
bool Character::getAliveOrDead()
{ return aliveOrDead; }

/***************************************************************************
**bool Character::LifeStatus()
** This method returns bool to check if alive or dead.
** It takes no parameters.
******************************************************************************/
bool Character::LifeStatus()
{
    if(strengthPoints == 0)
    { aliveOrDead = false;}
    
    return aliveOrDead;

}

Character::~Character(){}

/***************************************************************************
**void Character::setCoins(int numCoins)
** This method sets the coin data member.
** It takes an int numCoins and has no return.
******************************************************************************/
void Character::setCoins(int numCoins)
{
    coins = numCoins;
}

/***************************************************************************
**int Character::getCoins()
** This method returns the coin data member.
** It takes no parameters and returns an int.
******************************************************************************/
int Character::getCoins()
{
    return coins;
}

/***************************************************************************
**void Character::addCoins(int numCoins)
** This method takes an int as a parameter and add it to
** coin data member.
******************************************************************************/
void Character::addCoins(int numCoins)
{
    coins += numCoins;
    
}

/***************************************************************************
**void Character::addCoins(int numCoins)
** This method takes an int as a parameter and subtracts it to
** coin data member.
******************************************************************************/
void Character::subtractCoins(int numCoins)
{
    coins -= numCoins;
    
}

/***************************************************************************
**void Character::setName(string aName)
** This method takes a string as a parameter and sets it to
** name data member.
******************************************************************************/
void Character::setName(string aName)
{
    name = aName;
}

/***************************************************************************
**void Character::setSquare(char theSquare)
** This method takes a char as a parameter and calls
** to change square. It has no return.
******************************************************************************/
void Character::setSquare(char theSquare)
{
    changeSquare(theSquare);
}

/***************************************************************************
**void Character::subtractStrengthPoints(int num)
** This method takes an int as a parameter and subtracts that
** from strengthpoints. It has no return.
******************************************************************************/
void Character::subtractStrengthPoints(int num) 
{
    strengthPoints -= num;
    if(strengthPoints < 1)
    {
        strengthPoints = 0;
        aliveOrDead = false;
    }
}



