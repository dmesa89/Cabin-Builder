/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Description:  This is the class declaration for Space.
**It is an abstract class with four data members Space pointers.
** There are set and get methods for the Space pointers.
******************************************************************************/
#ifndef Space_hpp
#define Space_hpp

#include <iostream>


class Space
{
    private:
        Space* top;
        Space* right;
        Space* left;
        Space* bottom;
        
        char square;
        
    
    public:
        //default constructor
        Space();
            
        //parametered constructor
        Space(char theSquare);
        
        //set and get methods

        void setTop(Space* pointer);
        void setRight(Space* pointer);
        void setLeft(Space* pointer);
        void setBottom(Space* pointer);
        void getRandomEvent();
        void changeSquare(char aSquare);
    
        char getSquare();
        Space* getTop();
        Space* getLeft();
        Space* getRight();
        Space* getBottom();
    
        virtual void setSquare (char theSquare) = 0;
        virtual ~Space() = 0;
    
        
    
    
    
    
};

#endif /* Space_hpp */
