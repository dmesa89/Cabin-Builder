/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the class declaration for Observation
** It contains private data members, set and get methods
** for those members and virtual public method.
******************************************************************************/

#ifndef Observation_hpp
#define Observation_hpp

#include <iostream>
#include "Space.hpp"
#include <string>
#include "Die.hpp"
using std::string;
using std::cout;
using std::endl;

class Observation : public Space
{
    private:
        Die die;
        string observation;
    
    public:
        Observation();
        void setObservation();
        string getObservation();
        void changeObservation(string aChange);
        void setSquare(char theSquare) override;
    
};


#endif 
