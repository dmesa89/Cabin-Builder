/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the class declaration for Observation
** It contains private data members, set and get methods
** for those members and virtual public method.
******************************************************************************/

#include "Observation.hpp"

/***************************************************************************
**Observation::Observation()
** This is the default constructor for Observation. it sets
** observation but calling setObservation and sets the square
** char to O.
******************************************************************************/
Observation::Observation()
{
    setObservation();
    setSquare('O');
}

/***************************************************************************
**void Observation::setObservation()
** This is method randomly chooses an observation based
** on the roll of a die. It takes no parameters and has no return.
******************************************************************************/
void Observation::setObservation()
{
    die.setSides(5);
    int roll = die.rollingDie();
    switch (roll)
    {
        case 1: observation = "You notice it is a nice day today.\n";
            break;
        case 2: observation = "You hear a rabbit in the trees.\n";
            break;
        case 3: observation = "You hear the birds chirping.\n";
            break;
        case 4: observation = "It's quiet, too quiet.\n";
            break;
        case 5: observation = "It looks like something off in the distance.\n";
            break;
        default: observation = "You notice it is a nice day today.\n";
            break;
    }
}

/***************************************************************************
**string Observation::getObservation()
** This is method returns observation.
** on the roll of a die. It takes no parameters and returns a string.
******************************************************************************/
string Observation::getObservation()
{
    return observation;
}
/***************************************************************************
**void Observation::changeObservation(string aChangeObservation)
** This method takes a string that and changes observation to it.
** It has no return.
******************************************************************************/
void Observation::changeObservation(string aChangeObservation)
{
    observation = aChangeObservation;
}

/***************************************************************************
**void Observation::setSquare(char theSquare)
** This method takes a char that is the square and calls
** changeSquare to change the square.
******************************************************************************/
void Observation::setSquare(char theSquare)
{
    changeSquare(theSquare);
}

