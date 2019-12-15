/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the class declaration for DoublyLinkedList.
** It contains private data members and public methods that
** set and get the private data members. It also has various
** methods to add a node class and delete node class from the
** list.
******************************************************************************/

#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include <iostream>
#include "Character.hpp"
#include "Bear.hpp"
#include "Wolf.hpp"
#include "Observation.hpp"
#include "Object.hpp"
#include "Axe.hpp"
#include "Water.hpp"
#include "Nails.hpp"
#include "Lumber.hpp"
#include "Hammer.hpp"
#include "Bandit.hpp"
#include "Merchant.hpp"
#include "Die.hpp"


class DoublyLinkedList
{
    private:
        Space* nodePointer = NULL;
        Space* headPointer = NULL;
        Space* tailPointer = NULL;
        Space* tempPointer = NULL;
        Die die; 
        

    public:
        DoublyLinkedList(int ofColumns);


        void setHeadPointer(Space* aHeadNode);
        void setTailPointer(Space* aTailNode);
        void setNodePointer(Space* aNode);

        Space* getHeadPointer();
        Space* getTailPointer();
        Space* getNodePointer();
    
        void deleteNode(bool head);
        void traverseList();
        
        ~DoublyLinkedList();
    
    
};

#endif
