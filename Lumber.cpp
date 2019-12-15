/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Description:  This is the source code for Lumber.
**  It has a base class of Object, default constructor and
** one method.
******************************************************************************/

#include "Lumber.hpp"

/***************************************************************************
**Lumber::Lumber()
** This is the default constructor and calls set methods to set
** Object data members.
******************************************************************************/
Lumber::Lumber()
{
    setName("Lumber");
    setObject(true);
    setSquare('J');
}

/***************************************************************************
** void Lumber::addObject(std::vector<Object*>& aBackpack)
** This is a method to add object to a vector. It takes a ref
** to a vector and adds it. It has no return.
******************************************************************************/
void Lumber::addObject(std::vector<Object*>& aBackpack)
{
    Object * objectPointer = NULL;
    objectPointer = new Lumber;
    aBackpack.push_back(objectPointer);
    
}
