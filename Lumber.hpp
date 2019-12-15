/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Description:  This is the class declaration for Lumber.
**  It has a base class of Object, default constructor and
** one method.
******************************************************************************/

#ifndef Lumber_hpp
#define Lumber_hpp

#include <iostream>
#include "Object.hpp"
#include <vector>

class Lumber : public Object
{
public:
    Lumber();
    void addObject(std::vector<Object*>& aBackpack) override;
    
};
#endif /* Lumber_hpp */
