/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Description:  This is the class declaration for Water.
**  It has a base class of Object, default constructor and
** one method. 
******************************************************************************/

#ifndef Water_hpp
#define Water_hpp

#include <iostream>
#include "Object.hpp"
#include <vector>


class Water : public Object
{
    public:
        Water();
        void addObject(std::vector<Object*>& anObject) override; 
};

#endif
