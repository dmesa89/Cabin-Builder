
/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Description:  This is the source code for class Space.
**It is an abstract class with four data members Space pointers.
** There are set and get methods for the Space pointers.
******************************************************************************/

#include <iostream>
#include "Space.hpp"

/***************************************************************************
** Space::Space()
**This is the default constructor and sets the values of node
** to zero.
******************************************************************************/
Space::Space()
{
    setTop(NULL);
    setLeft(NULL);
    setRight(NULL);
    setBottom(NULL);
}




/***************************************************************************
** char Space::getSquare()
** This method takes in no parameter and returns an a char
** when called
******************************************************************************/
char Space::getSquare()
{ return square; }

/***************************************************************************
** void Space::setTop(Space *pointer)
** This method takes a pointer to a Space and sets it to next
** pointer on top. It has no return.
******************************************************************************/
void Space::setTop(Space *pointer)
{ top = pointer;}

/***************************************************************************
**Space* Space::getTop()
** This method takes in no parameter and returns a Space pointer
** when called
******************************************************************************/
Space* Space::getTop()
{ return top; }

/***************************************************************************
** void Space::setLeft(Space *pointer)
** This method takes a pointer to a Space and sets it to next
** pointer. It has no return.
******************************************************************************/
void Space::setLeft(Space *pointer)
{ left = pointer;}

/***************************************************************************
**Space* Space::getLeft()
** This method takes in no parameter and returns a Space pointer
** when called
******************************************************************************/
Space* Space::getLeft()
{ return left; }

/***************************************************************************
** void Space::setRight(Space *pointer)
** This method takes a pointer to a Space and sets it to next
** pointer. It has no return.
******************************************************************************/
void Space::setRight(Space *pointer)
{ right = pointer;}

/***************************************************************************
**Space* Space::getRight()
** This method takes in no parameter and returns a Space pointer
** when called
******************************************************************************/
Space* Space::getRight()
{ return right; }

/***************************************************************************
** void Space::setBottom(Space *pointer)
** This method takes a pointer to a Space and sets it to next
** pointer. It has no return.
******************************************************************************/
void Space::setBottom(Space *pointer)
{ bottom = pointer;}

/***************************************************************************
**Space* Space::getBottom()
** This method takes in no parameter and returns a Node* pointer
** when called
******************************************************************************/
Space* Space::getBottom()
{ return bottom; }

/***************************************************************************
**void Space::changeSquare(char aSquare)
** This method takes in a char parameter and sets it to
** square data member. It has no return.
******************************************************************************/
void Space::changeSquare(char aSquare)
{
    square = aSquare;
    
}

Space::~Space(){}
