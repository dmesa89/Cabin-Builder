/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the source code for class GamePlay.
**it contains methods that run the game, interact with Space
** objects, Player object and Board object.
******************************************************************************/
#include "GamePlay.hpp"

/***************************************************************************
**void GamePlay::runGame()
** This method runs the game for for player to navigate
** through the spaces and collect objects to build a cabin.
 It takes in no parameters and has no return.
******************************************************************************/
void GamePlay::runGame()
{
    srand(time(0));
    gameState = true;
    won = false;
    
    //create board
    Board myBoard(10,10);
    myBoardPtr = &myBoard;
    
    //create player
    player = new Player;
    
    //randomize player location
    playerLocation = myBoard.getRandomLocation();
    
    //introduce game
    intro();
    
    char enter;
    cout << "Please press enter to continue: " ;
    enter = inputValidationEnter();
    cout << "\n" <<endl;
    
    //rules of game
    rules();
    
    //change player name
    changePlayerName();


    //display map to begin
    displayMap();
    
    int option = 0;
    //menu
    while(option != 6 && gameState == true)
    {
        option = menu();
        
        if(option == 1)
        {
            int moveChoice = moveMenu();
            if (moveChoice != 5)
            {
                move(moveChoice);
                player->subtractStrengthPoints(1);
                if(player->getAliveOrDead() == false)
                {
                    gameState = false;
                    cout << "\nYou have died! Sorry, you've lost!" <<endl;
                }
                else if(won == false)
                { displayMap(); }
                
            }
        }
        else if(option == 2)
        {
            inventory();
        }
        else if(option == 3)
        {
            checkPurse();
        }
        else if(option == 4)
        {
            displayMap();
        }
        else if(option == 5)
        {
            rules();
        }
        
    }
    
    cout << "Goodbye!" <<endl;
    
    delete player;
    
    
}

/***************************************************************************
**void GamePlay::intro()
** This method introduces the user to the game.
** It takes no parameters and has no return.
******************************************************************************/
void GamePlay::intro()
{
    cout << "Welcome to Cabin Builder!" << endl;
    cout << "You have just moved to the Pacific NorthWest ";
    cout << "but cannot afford Portland housing prices!" << endl;
    cout << "You decide to move to the wilderness and build a cabin." <<endl;
    cout << "In order to build a house you need a few items!" <<endl;
    cout << "Watch out though, there are wild animals and bandits that can attack!" << endl;
    cout << "Good luck on your quest!\n" <<endl;
}

/***************************************************************************
**void GamePlay::rules()
** This method introduces the user to the rules.
** It takes no parameters and has no return.
******************************************************************************/
void GamePlay::rules() 
{
    cout << "***RULES***" <<endl;
    cout << "1.As you travel through the forest, the map will display three locations." <<endl;
    cout << "  Player: i    Merchant Cart: M    Land Plot: P    Trees: Y" << endl;
    cout << "2.You can move up, right, left, or down." << endl;
    cout << "3.As you walk, you may encounter wilds animals, bandits, merchants, or objects. " <<endl;
    cout << "4.Bears, wolves, and bandits will attack. Bears and wolves drop pelts and bandits drop coins." <<endl;
    cout << "4.You will lose a strength point after each move, due to exhaustion." <<endl;
    cout << "5.In order to build on your plot of land, you will need 1 axe, 1 hammer, 2 lumber, ";
    cout << "2 nails, and 2 waters" <<endl;
    cout << "  You can collect these on your walk, or purchase them from the merchant for coins." <<endl;
    cout << "6.If you succumb to death by wild animals, bandits or exhaustion, you lose the game." <<endl;
    cout << "7.If you build your plot of land, you will have won and be able to live out your" ;
    cout << "  days in the lovely PNW!" <<endl;
    cout << "\nGood luck!" <<endl;

}

/***************************************************************************
**void GamePlay::changePlayerName()
** This method changes the Player objects name.
** It takes no parameters and has no return.
******************************************************************************/
void GamePlay::changePlayerName()
{
    string aName;
    cout << "\n\nPlease enter your character's name: ";
    aName = inputValidationString();
    player->setName(aName);
}

/***************************************************************************
**int GamePlay::menu()
** This method displays the menu.
** It takes no parameters and returns an int.
******************************************************************************/
int GamePlay::menu()
{
    int option;
    
    //character options
    cout << "\n\n*" <<player->getName() <<" Health: ";
    cout <<player->getStrengthPoints() <<"*" <<endl;
    cout <<"Below is a list to choose from." <<endl;
    cout <<"1: Move" <<endl;
    cout <<"2: Check Backpack" <<endl;
    cout <<"3: Check Coin Purse" <<endl;
    cout <<"4: Display Map" <<endl;
    cout <<"5: Rules" <<endl;
    cout <<"6: Quit" <<endl;
    cout << "Please enter an option choice for player:  ";
    option = inputValidation();
    while(option < 1 || option > 6)
    {
        cout << "Please enter a valid option: ";
        option = inputValidation();
    }
    
    return option;
}

/***************************************************************************
** int GamePlay::moveMenu()
** This method displays the menu for player to move.
** It takes no parameters and returns an int.
******************************************************************************/
int GamePlay::moveMenu()
{
    int option;
        cout <<"\n\nBelow is a list of moves to choose from." <<endl;
        cout <<"1: Up" <<endl;
        cout <<"2: Right" <<endl;
        cout <<"3: Left" <<endl;
        cout <<"4: Down" <<endl;
        cout <<"5: Back to Menu" <<endl;
        cout << "Please enter an option choice for player One:  ";
    option = inputValidation();
    while(option < 1 || option > 5)
    {
        cout << "Please enter a valid option: ";
        option = inputValidation();
    }
    
    return option;

}

/***************************************************************************
** void GamePlay::move(int aMove)
** This method moves the location of the player based on
** on move choice.
** It takes an int as a parameter and has no return.
******************************************************************************/
void GamePlay::move(int aMove)
{
    switch(aMove)
    {
        case 1: playerLocation = playerLocation->getTop();
            break;
        case 2: playerLocation = playerLocation->getRight();
            break;
        case 3: playerLocation = playerLocation->getLeft();
            break;
        default: playerLocation = playerLocation->getBottom();
            break;
    }
    
    interact();
}

/***************************************************************************
** void GamePlay::interact()
** This method allows the Player object to interact with the
** space that is its location.
** It takes no parameters and has no return.
******************************************************************************/
void GamePlay::interact()
{
    //upcast the pointers based on char type
    char whatType = playerLocation->getSquare();
    if(whatType == 'C')
    {
        charPlayerLocation = dynamic_cast<Character*>(playerLocation);
        interaction(charPlayerLocation);
    }
    else if (whatType == 'O')
    {
        obsPlayerLocation = dynamic_cast<Observation*>(playerLocation);
        interaction(obsPlayerLocation);
    }
    else if(whatType == 'J')
    {
        objPlayerlocation = dynamic_cast<Object*>(playerLocation);
        interaction(objPlayerlocation);
    }
    else if(whatType == 'H' || whatType == 'M')
    {
        merchPlayerLocation = dynamic_cast<Merchant*>(playerLocation);
        interaction(merchPlayerLocation);
    }
    else if(whatType == 'P')
    {
        won = player->checkifWon();
        if(won == true)
        {
            gameState = false;
            cout << "\n\nCongratulations, you've built a beautiful cabin!" <<endl;
        }
        else
        {
            cout << "\n\nThis is your plot of land." <<endl;
            cout << "You don't have the required materials yet! Keep searching!" <<endl;
        }
    }
}

/***************************************************************************
** void GamePlay::interaction(Object* aPlayerLocation)
** This method allows the Player object to interact with the
** Object object in the Space
** It takes an Object pointer as a parameter and has no return.
******************************************************************************/
void GamePlay::interaction(Object* aPlayerLocation)
{
    cout << "\n\nYou found a " << aPlayerLocation->getName() << "!" <<endl;
    if(player->getBackpackSize() < 16)
    {aPlayerLocation->addObject(player->getBackpack());}
    else
    {
        cout << "Your backpack is full. ";
        cout<< "You need to sell some items to the merchant!" <<endl;
    }
    randomSquareSwap(aPlayerLocation);
}

/***************************************************************************
** void GamePlay::interaction(Object* aPlayerLocation)
** This method allows the Player object to interact with the
** Character object in the Space
** It takes an Object pointer as a parameter and has no return.
******************************************************************************/
void GamePlay::interaction(Character* aPlayerLocation)
{
    
    bool keepPlaying = true;
    while(keepPlaying)
    {
        int initialStrength = aPlayerLocation->getStrengthPoints();
         string name = aPlayerLocation->getName();
         int damage = aPlayerLocation->Attack();
         cout << "\nA " << name << " is attacking!" <<endl;
         player->subtractStrengthPoints(damage);
         cout <<name <<" caused " <<damage << " damage!" <<endl;
         cout <<player->getName() <<" has " <<player->getStrengthPoints() << " SP remaining." <<endl;
        if(player->getAliveOrDead() == false)
        {
            keepPlaying = false;
            player->setAliveOrDead(false);
        }
        else
        {
            damage = player->Attack();
            cout <<player->getName() <<" caused " <<damage <<" damage!" <<endl;
            aPlayerLocation->subtractStrengthPoints(damage);
            cout<<name <<" has " <<aPlayerLocation->getStrengthPoints() << " SP remaining." <<endl;
        }
        if(aPlayerLocation->getAliveOrDead() == false)
        {
            keepPlaying = false;
            aPlayerLocation->setStrengthPoints(initialStrength);
            randomSquareSwap(aPlayerLocation);
            //add pelts based on character trait
            if(aPlayerLocation->getCharacteristic())
            {
                player->addPelts(aPlayerLocation->CharacterTrait());
                cout << "\n " <<aPlayerLocation->CharacterTrait();
                cout << " pelts have been added to your purse." <<endl;
                int coins = aPlayerLocation->randomCoins();
                player->addCoins(coins);
                cout << "\n " <<coins;
                cout << " coins have been added to your purse." <<endl;
            }
            //else it is a bandit and drops random coins
            else
            {
                int coins =aPlayerLocation->randomCoins();
                player->addCoins(coins);
                cout << "\n " <<coins;
                cout << " coins have been added to your purse." <<endl;
            }
            
        }
        
    }
 
    
}

/***************************************************************************
** void GamePlay::interaction(Object* aPlayerLocation)
** This method allows the Player object to interact with the
** Observation object in the Space
** It takes an Object pointer as a parameter and has no return.
******************************************************************************/
void GamePlay::interaction(Observation* aPlayerLocation)
{
    cout << "\n\n" <<aPlayerLocation->getObservation();
    randomSquareSwap(aPlayerLocation);
}
void GamePlay::interaction(Merchant* aPlayerLocation) 
{
    cout << "\n\n";
    aPlayerLocation->interact(player);
    
    //do not swap if permanent merchant
    if(aPlayerLocation->getSquare() == 'H')
    { randomSquareSwap(aPlayerLocation); }
    
}

/***************************************************************************
** void GamePlay::randomSquareSwap(Space* aPlayerLocation)
** This method swaps the player location with another space
** It takes an Space pointer as a parameter and has no return.
******************************************************************************/
void GamePlay::randomSquareSwap(Space* aPlayerLocation)
{
    Space* tempPointerA = NULL;
    Space* tempPointerB = NULL;
    
    tempPointerA = myBoardPtr->getRandomLocation();
    
    tempPointerB = aPlayerLocation;
    
    aPlayerLocation = tempPointerA;

    
    tempPointerA = tempPointerB;
    
    tempPointerA = NULL;
    tempPointerB = NULL;

}

/***************************************************************************
** void GamePlay::inventory()
** This method displays the players bag
** It takes no parameters and has no return.
******************************************************************************/
void GamePlay::inventory()
{
    cout << "\n\n";
    player->showObjects();
}

/***************************************************************************
** void GamePlay::checkPurse()
** This method displays the players purse
** It takes no parameters and has no return.
******************************************************************************/
void GamePlay::checkPurse()
{
    cout << "\n\nCoins: " <<player->getCoins() <<endl;
    cout << "Pelts: " <<player->getPelts();
}

/***************************************************************************
** void GamePlay::inventory()
** This method displays the  map
** It takes no parameters and has no return.
******************************************************************************/
void GamePlay::displayMap()
{
    cout << "\n\n";
    myBoardPtr->displayTheBoard(playerLocation);
}

