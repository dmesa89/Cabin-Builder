/***********************************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Description: This contains the source code for LoadedDie .
** This class rolls a  die,  less than the number of sides given.
 ***********************************************************************************************/

#include <iostream>
#include <cstdlib>
#include "Die.hpp"

/***********************************************************************************************
** Description: This is the default constructor for Die. It initializes the data
** members to zero.
 ***********************************************************************************************/
Die::Die()
{
    randomNum = 0;
    N = 0;
    
};

/***********************************************************************************************
** Description: This is the set method for N sides. It sets the number of sides
** for the die with input from user.
 ***********************************************************************************************/
void Die::setSides(int sides)
{
    N = sides;
}


/***********************************************************************************************
** int LoadedDie::rollingDie()
** Description: This method rolls the die. It creates a random number less
** than the given sides. It takes in no paremeters and returns an int.
 ***********************************************************************************************/
int Die::rollingDie()
{
    randomNum = rand()% N + 1;
    return randomNum;
    
};




