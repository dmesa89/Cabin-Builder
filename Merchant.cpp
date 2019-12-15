/***************************************************************************
** Project Name: Final Project
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the class source code for Merchant
** It contains a default constructor, destructor, and virtual
** methods, that allow the class to interact with Player object.
******************************************************************************/
#include "Merchant.hpp"
using std::cout;
using std::endl;

/***************************************************************************
**Merchant::Merchant()
** This is the default constructor. It initializes all the member
** variables of the base class.
******************************************************************************/
Merchant::Merchant()
{
    name = "Merchant";
    strength = 100;
    setSquare('H');
}

/***************************************************************************
** void Merchant::sellStrengthPoints()
** This is a method that sells a Playerobject strenth points.
** It takes no parameters and has no return.
******************************************************************************/
void Merchant::sellStrengthPoints()
{
    cout << "How many coins will you give? [1-5]: ";
    int option = inputValidation();
    while(option <1 || option > 5)
    {
        cout << "Please enter a valid amount of coins [1-5]: ";
        option = inputValidation();
    }
    
    int currentCoins = player->getCoins();
    if( currentCoins >= option)
    {
        player->subtractCoins(option);
        int currentStrength = player->getStrengthPoints();
        int added = currentStrength + (option *5);
        player->setStrengthPoints(added);
        cout << "I have added " <<added << "SP to your strength." <<endl;
        cout <<"You look healthier!" <<endl;
        
    }
    else
    {
        cout << "You dont have enough coins! Don't try and trick me!" <<endl;
    }
}

/***************************************************************************
** void Merchant::interact(Player* aPlayer)
** This is that interacts with a Player Object. It runs the function
** calls for merchant.
** total damage from class. It takes in a Player pointer and has
** no return.
******************************************************************************/
void Merchant::interact(Player* aPlayer)
{
    player = aPlayer;
    
    int option = 0;
    while(option != 5)
    {
        option = intro();
        int choice;
        if(option == 1)
        {
            choice = buyIntro();
            if(choice < 6)
            {
                if(player->getBackpackSize() < 16)
                {buyObject(choice);}
                else
                {cout << "\n\nYour backpack is full! Sell me some items first!" <<endl;}
            }
            else if(choice == 6)
            {
                sellStrengthPoints();
            }
            else
            {
                option = 3;
            }
            
        }
        else if(option == 2)
        {
            choice = sellIntro();
            if(choice < 6)
            {
                sellObject(choice);
                
            }
            else if(choice == 6)
            {
                sellPelt();
            }
            else
            {
                option = 5;
            }
        }
        else if(option == 3)
        {
            player->showObjects();
        }
        else if(option ==4)
        {
            cout << "\n\nCoins: " <<player->getCoins() <<endl;
            cout << "Pelts: " <<player->getPelts();
        }
        
    }

    
    cout << "Goodbye!";
}

/***************************************************************************
** int Merchant::intro()
** This is a method that introduces the merchant.
** It takes no parameters and returns an int.
******************************************************************************/
int Merchant::intro()
{
    int option;
    cout << "\n\nHello! I'm a Merchant!" <<endl;
    cout << "Would you like to: " << endl;
    cout << "1: Buy " << endl;
    cout << "2: Sell" <<endl;
    cout << "3: Check Backpack" <<endl;
    cout << "4: Check Coin Purse" <<endl;
    cout << "5: Leave" <<endl;
    cout << "Please enter an option choice: ";
    option = inputValidation();
    while(option < 1 || option > 5)
    {
        cout << "Please choose a valid option:" <<endl;
        option = inputValidation();
    }
    
    return option;
}

/***************************************************************************
** int Merchant::buyIntro()
** This is a method that introduces the buying menu.
** It takes no parameters and returns an int.
******************************************************************************/
int Merchant::buyIntro()
{
    int option;
        cout << "\n\nWhat would you like to buy?" <<endl;
        cout << "1: Water (5C)" << endl;
        cout << "2: Axe (10C)" << endl;
        cout << "3: Hammer (10C)"<<endl;
        cout << "4: Nails (2C)" <<endl;
        cout << "5: Lumber (2C)" <<endl;
        cout << "6: StrengthPoints (1C/5SP)" <<endl;
        cout << "7: Back to Menu " <<endl;
        cout << "Please enter an option choice: ";
        option = inputValidation();
        while(option < 1 || option > 7)
        {
            cout << "Please choose a valid option:" <<endl;
            option = inputValidation();
        }
    
    return option;
}

/***************************************************************************
** void Merchant::buyObject(int anObject)
** This is a method that creates a new object and pushes
** it onto the player objects vector.
** It takes an int as a parameter and has no return.
******************************************************************************/
void Merchant::buyObject(int anObject)
{
    
    switch (anObject)
    {
        case 1: objectPointer = new Water;
            break;
        case 2: objectPointer = new Axe;
            break;
        case 3: objectPointer = new Hammer;
            break;
        case 4: objectPointer = new Nails;
            break;
        default: objectPointer = new Lumber;
            break;
            
    }
    
    int price;
    switch (anObject)
    {
        case 1: price = 5;
            break;
        case 2: price = 10;
            break;
        case 3: price = 10;
            break;
        case 4: price = 2;
            break;
        case 5: price = 2;
            break;
    }
    
    int currentCoins = player->getCoins();
    if(price <= currentCoins)
    {
        player->subtractCoins(price);
        player->addObject(objectPointer);
        cout << "I have added a " <<objectPointer->getName() <<" to your bag!"<<endl;
        cout << "I have deducted " <<price <<" coins from your purse." <<endl;
    }
    else
    {
        cout << "You don't have enough coins! Don't try and trick me!" <<endl;
    }
    
}

/***************************************************************************
** int Merchant::sellIntro()
** This is a method that displays the sell menu.
** It takes no parameter and returns an int.
******************************************************************************/
int Merchant::sellIntro()
{
    int option;
    
    cout << "What would you like to sell?" <<endl;
    cout << "1: Water (3C)" << endl;
    cout << "2: Axe (5C)" << endl;
    cout << "3: Hammer (5C)"<<endl;
    cout << "4: Nails (1C)" <<endl;
    cout << "5: Lumber (1C)" <<endl;
    cout << "6: Pelts (1C)" <<endl;
    cout << "7: Back to Menu" <<endl;
    cout << "Please enter an option choice: ";
    option = inputValidation();
    while(option < 1 || option > 7)
    {
        cout << "Please choose a valid option:" <<endl;
        option = inputValidation();
    }
    
    return option;
}

/***************************************************************************
** void Merchant::sellObject(int anObject)
** This is a method deletes an object from players vector.
** It takes an int as a parameter and has no return.
******************************************************************************/
void Merchant::sellObject(int anObject)
{
    string name;
    switch (anObject)
    {
        case 1: name = "Water";
            break;
        case 2: name = "Axe";
            break;
        case 3: name = "Hammer";
            break;
        case 4: name = "Nails";
            break;
        default: name = "Lumber";
            break;
            
    }
    
    int price;
    switch (anObject)
    {
        case 1: price = 3;
            break;
        case 2: price = 5;
            break;
        case 3: price = 5;
            break;
        case 4: price = 1;
            break;
        default: price = 1;
            break;
    }
    
    bool removed = player->removeObject(name);
    if(removed)
    {
        player->addCoins(price);
        cout << "You just earned " <<price <<" for your " <<name <<endl;
    }
    else
    {
        cout << "You don't have that Object! Don't try and trick me!" <<endl;
    }
    
}
    
/***************************************************************************
** void Merchant::sellPelt()
** This is a method that removes the pelts from player object
** and adds coins to player object.
** It takes no parameter and has no return.
******************************************************************************/
void Merchant::sellPelt()
{
    int numPelts = player->getPelts();
    player->setPelts(0);
    player->addCoins(numPelts);
    cout << "I just bought your " <<numPelts <<" pelts for " <<numPelts << " coins." <<endl;
    
}


Merchant::~Merchant()
{}

/***************************************************************************
**void Merchant::setSquare(char theSquare)
** This method sets the square of the Merchant.
** It takes a char as a parameter and has no return.
******************************************************************************/
void Merchant::setSquare(char theSquare)
{
    changeSquare(theSquare); 
}
