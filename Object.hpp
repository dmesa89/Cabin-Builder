/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Description:  This is the class declaration for Object.
**It is an abstract class with two data members.
** There are set and get methods for the data members.
******************************************************************************/

#ifndef Object_hpp
#define Object_hpp

#include <iostream>
#include "Space.hpp"
#include <vector>
#include <string>
using std::string;

class Object : public Space
{
    private:
        string name;
        bool object;
    
    public:
    
    void setObject(bool anObject);
    void setName(string aName);
    string getName();
    
    void setSquare(char theSquare) override;
    
    
    virtual void addObject(std::vector<Object*>& aBackpack) = 0;
};

#endif /* Object_hpp */
