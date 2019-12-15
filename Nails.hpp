/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Description:  This is the class declaration for Nails.
**  It has a base class of Object, default constructor and
** one method.
******************************************************************************/

#ifndef Nails_hpp
#define Nails_hpp

#include <iostream>
#include "Object.hpp"
#include <vector>

class Nails : public Object
{
public:
    Nails();
    void addObject(std::vector<Object*>& aBackpack) override;
     
    
};

#endif /* Nails_hpp */
