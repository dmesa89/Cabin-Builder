/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Description:  This is the source code for Object.
**It is an abstract class with two data members.
** There are set and get methods for the data members.
******************************************************************************/

#include "Object.hpp"

/***************************************************************************
**void Object::setObject(bool anObject)
** This method takes in a bool and sets object to it to determine
** if it has been used.
******************************************************************************/
void Object::setObject(bool anObject)
{
    object = anObject;
}

/***************************************************************************
**void Object::setName(string aName)
** This method takes in a string Name and sets it to the object.
** It has no return.
******************************************************************************/
void Object::setName(string aName)
{
    name = aName;
}

/***************************************************************************
**string Object::getName()
** This method returns a string name. It has no parameter.
******************************************************************************/
string Object::getName()
{
    return name;
}

/***************************************************************************
**void Object::setSquare(char theSquare)
** This method takes a char square and calls Changesquare to
** set the square.
******************************************************************************/
void Object::setSquare(char theSquare)
{
    changeSquare(theSquare);
}
