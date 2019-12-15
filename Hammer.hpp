/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Description:  This is the class declaration for Hammer.
**  It has a base class of Object, default constructor and
** one method.
******************************************************************************/
#ifndef Hammer_hpp
#define Hammer_hpp

#include <iostream>
#include <vector>
#include "Player.hpp"

class Hammer : public Object 
{
    public:
        Hammer();
        void addObject(std::vector<Object*>& aBackpack) override;
        
};

#endif /* Hammer_hpp */
