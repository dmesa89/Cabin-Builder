/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the class declaration for Character
**It is an abstract base class. It contains private data members,
** set and get methods for those members.
** and pure virtual public methods that allow the  derived
**class to attack, defend and its own characteristic.
******************************************************************************/
//include guards
#ifndef Character_hpp
#define Character_hpp

#include <iostream>
#include "Die.hpp"
#include "Space.hpp"
#include <string>

using std::string;

class Character : public Space
{
    //private data members
    protected:
    string name;
    int damage;
    int strengthPoints;
    bool characteristic;
    bool aliveOrDead;
    int coins;
    Die die;
    
public:
    
    //set and get methods
    void setName(string aName);
    string getName();
    
    void setDamage(int aDamage);
    int getDamage();
    
    void setStrengthPoints(int aStrengthPoints);
    int getStrengthPoints();
    
    void setCharacteristic(bool aCharacteristic);
    bool getCharacteristic();
    
    void setAliveOrDead(int aLife);
    bool getAliveOrDead();
    
    void setCoins(int numCoins);
    int getCoins();
    void addCoins(int numCoins);
    void subtractCoins(int numCoins);
    
    void subtractStrengthPoints(int num);
    
    
   
    bool LifeStatus();
    
    //pure virtual methods
    virtual int CharacterTrait() = 0;
    virtual int Attack() = 0;
    virtual ~Character() = 0;
    virtual int randomCoins() = 0;
    
    void setSquare(char theSquare) override; 


    
    
    
    
};

#endif /* Character_hpp */
