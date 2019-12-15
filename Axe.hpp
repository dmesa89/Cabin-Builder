/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Description:  This is the class declaration for Axe.
**  It has a base class of Object, default constructor and
** one method.
******************************************************************************/

#ifndef Axe_hpp
#define Axe_hpp

#include <iostream>
#include <vector>
#include "Object.hpp"

class Axe : public Object
{
    public:
        Axe();
        void addObject(std::vector<Object*>& aBackpack) override;
        
};

#endif /* Axe_hpp */
