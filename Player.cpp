/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the source code for Player
** It contains private data members and public methods called
** that allow the Player to to attack, collect coins, interact with
** objects.
******************************************************************************/

#include "Player.hpp"

/***************************************************************************
**Player::Player()
** This is the default constructor. It initializes all the member
** variables of the base class.
******************************************************************************/
Player::Player()
{
    name = "Player";
    damage = 0;
    strengthPoints = 100;
    characteristic = false;
    aliveOrDead = true;
    coins = 25;
    setSquare('i');
    pelts = 0;
}

/***************************************************************************
** int Player::Attack()
** This is the a method that rolls a 18 sided die to calculate
** total damage from class. It takes in no parameters and returns
** an int that is the damage.
******************************************************************************/
int Player::Attack()
{
    die.setSides(18);
    damage = die.rollingDie();
    
    return damage;

}



/***************************************************************************
**int Player::CharacterTrait()
** This is the a method that sets the character trait of the class
** This method  takes in no parameters and returns an int.
******************************************************************************/
int Player::CharacterTrait()
{
    return 0;;
}


/***************************************************************************
**int Player::randomCoins()
** This method returns an int of random coins.
** It takes no parameters.
******************************************************************************/
int Player::randomCoins()
{
    return 0;
}

/***************************************************************************
**void Player::setPelts(int numPelts)
** This method sets the number of pelts
** It has no return and takes an int as a parameter
******************************************************************************/
void Player::setPelts(int numPelts)
{
    pelts = numPelts;
}

/***************************************************************************
**int Player::getPelts()
** This method returns the number of pelts.
** It takes no parameters
******************************************************************************/
int Player::getPelts()
{
    return pelts;
}

/***************************************************************************
**void Player::addPelts(int numPelts)
** This method adds an int to pelts.
** It takes an int as a parameter and has no return.
******************************************************************************/
void Player::addPelts(int numPelts)
{
    pelts += numPelts;
}

/***************************************************************************
**void Player::addObject(Object* anObject)
** This method adds an object pointer to vector.
** It takes an object pointer as a parameter and has no return.
******************************************************************************/
void Player::addObject(Object* anObject) 
{
    backpack.emplace_back(anObject);
}

/***************************************************************************
**bool Player::removeObject(string anObject)
** This method removes an object pointer to vector.
** It takes an object pointer as a parameter and returns a bool
******************************************************************************/
bool Player::removeObject(string anObject)
{
    bool removed = false;
    for(int i = 0; i < backpack.size(); i++)
    {
        if(backpack[i]->getName() == anObject && removed == false)
        {
            backpack[i]->~Object();
            backpack.erase(backpack.begin()+i);
            removed = true;
        }
    }
    
    return removed;

}

/***************************************************************************
**bvoid Player::showObjects()
** This method shows the objects in the vector.
** It takes no paramters and has no return.
******************************************************************************/
void Player::showObjects()
{
    int size = backpack.size();
    if(size != 0)
    {
        std::cout << "\n\n";
         for(int i = 0; i < size; i++)
         {
             std::cout << "[" << backpack[i]->getName() << "]  ";
         }
         
        std::cout << "\n" <<std::endl;
    }
    else
    {
        std::cout << "Your backpack is empty!" << std::endl;
    }
    
}

/***************************************************************************
**vector<Object*>& Player::getBackpack()
** This method returns the address to the vector backpack.
** It has no parameters.
******************************************************************************/
vector<Object*>& Player::getBackpack()
{
    return backpack;
}

/***************************************************************************
**bool Player::checkifWon()
** This method checks if the necessary objects are in the backpack.
** It has no parameters and returns a bool, false is not in backpack.
******************************************************************************/
bool Player::checkifWon()
{
    bool won = false;
    int axe = 0;
    int hammer = 0;
    int lumber = 0;
    int nails = 0;
    int water = 0;
    int size = backpack.size();
    string item;
    
    if(size > 6)
    {
         for(int i = 0; i < size; i++)
         {
             item = backpack[i]->getName();
             if(item == "Axe")
             { axe++;}
             else if(item == "Hammer")
             { hammer++;}
             else if(item =="Lumber")
             { lumber++;}
             else if(item == "Nails")
             { nails++;}
             else if(item == "Water")
             {water++;}
         }
    }
    
    if(axe > 0 && hammer > 0 && lumber > 1 && nails > 1 && water > 1 )
    {
        won = true;
    }
    
    return won;
    
}

/***************************************************************************
**int Player::getBackpackSize()
** This method returns the address to the vector backpack.
** It has no parameters.
******************************************************************************/
int Player::getBackpackSize()
{
    return backpack.size();
}

Player::~Player()
{
    for (auto i : backpack)
    {
      delete i;
    }
    backpack.clear();
}
