/***********************************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Description: This contains the class methods for LoadedDie and data
** members. This class rolls a  die,  less than the number of sides given.
 ***********************************************************************************************/

//include guards
#ifndef Die_hpp
#define Die_hpp

#include <stdio.h>

class Die
{
    //data members
    protected:
        int N;
        int randomNum;
    
    //function declarations
    public:
        Die();
        void setSides(int sides);
        int rollingDie();
        
};


#endif /* Die_hpp */
