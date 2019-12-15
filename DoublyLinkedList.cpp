/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the source code for class DoublyLinkedList.
** It contains private data members and public methods that
** set and get the private data members. It also has various
** methods to add a node class and delete node class from the
** list.
******************************************************************************/

#include <iostream>
#include "DoublyLinkedList.hpp"
using std::cout;
using std::endl;


/***************************************************************************
** void DoublyLinkedList::setHeadPointer(Space* aHeadNode)
** This method takes a pointer to a Node and sets it to node
** headpointer. It has no return.
******************************************************************************/
void DoublyLinkedList::setHeadPointer(Space* aHeadNode)
{ headPointer = aHeadNode; }
/***************************************************************************
** void DoublyLinkedList::setTailPointer(Space* aTailNode)
** This method takes a pointer to a Node and sets it to node
** tailpointer. It has no return.
******************************************************************************/
void DoublyLinkedList::setTailPointer(Space* aTailNode)
{ tailPointer = aTailNode; }

/***************************************************************************
** Space* DoublyLinkedList::getHeadPointer()
** This method has no parameter. It returns a Node* pointer
** which is the headpointer
******************************************************************************/
Space* DoublyLinkedList::getHeadPointer()
{ return headPointer; }

/***************************************************************************
** Space* DoublyLinkedList::getTailPointer()
** This method has no parameter. It returns a Node* pointer
** which is the tailpointer
******************************************************************************/
Space* DoublyLinkedList::getTailPointer()
{ return tailPointer; }

/***************************************************************************
** Space* DoublyLinkedList::getTailPointer()
** This method has no parameter. It returns a Node* pointer
** which is the tailpointer
******************************************************************************/
void DoublyLinkedList::setNodePointer(Space* aNode)
{ nodePointer = aNode; }

/***************************************************************************
** Space* DoublyLinkedList::getTailPointer()
** This method has no parameter. It returns a Node* pointer
** which is the tailpointer
******************************************************************************/
Space* DoublyLinkedList::getNodePointer()
{ return nodePointer; }

/***************************************************************************
**DoublyLinkedList::DoublyLinkedList(int ofColumns)
** This method takes in an int value. It
** sets a temp pointer to a new Space object and assigns that
** pointer to the headpointer if headpointer is null. It assigns
** the temp pointer to a tail pointer otherwise
** and asigns the old tail pointer
** the next or previous node. It has no return.
******************************************************************************/
DoublyLinkedList::DoublyLinkedList(int ofColumns) 
{
    
        for(int i = 0; i < ofColumns; i++)
        {
            die.setSides(100);
            int roll = die.rollingDie();
            
            if(roll < 6)
            {tempPointer = new Merchant;}
            else if(roll < 16)
            {tempPointer = new Bandit;}
            else if(roll < 26 )
            {tempPointer = new Bear;}
            else if(roll < 41)
            {tempPointer = new Wolf;}
            else if(roll < 61)
            {tempPointer = new Observation;}
            else
            {   die.setSides(5);
                int roll = die.rollingDie();
                
                switch (roll)
                {
                    case 1: tempPointer = new Water;
                        break;
                    case 2: tempPointer = new Hammer;
                        break;
                    case 3: tempPointer = new Axe;
                        break;
                    case 4: tempPointer = new Lumber;
                        break;
                    default: tempPointer = new Nails;
                        break;
                }
            }
            
            if(headPointer == NULL)
            {
                headPointer = tempPointer;
                tailPointer = tempPointer;
                tempPointer = NULL;
            }
            else
            {
                //nodePointer holds the old tailpointer
                nodePointer = tailPointer;
                
                //set new tailPointer to new node
                tailPointer = tempPointer;
                
                //set new tailpointer previous to the nodePointer (old tailPointer)
                tailPointer->setLeft(nodePointer);
                tailPointer->setRight(headPointer);
                
                //set nodePointer next to new tailPointer
                nodePointer->setRight(tailPointer);
                
                nodePointer = NULL;
                tempPointer = NULL;

            }
        }

    
}

/***************************************************************************
**void DoublyLinkedList::traverseList()
** This method has no parameter. It has no return.
** This method traverses the doubly linked list using a
** node pointer and prints the list.
******************************************************************************/
void DoublyLinkedList::traverseList()
{
    //if no headpointer, print list
    if(headPointer != NULL)
    {
        cout <<"The values in the linked list are:" <<endl;
        //traverse the list with node pointer
        nodePointer = headPointer;
        do
        {
            cout << "{";
            //print list 
            cout << nodePointer->getSquare() << "} ";
            nodePointer = nodePointer->getRight();
            
        }
        while(nodePointer != NULL && nodePointer != tailPointer);
        if(nodePointer == tailPointer)
        {
            nodePointer = headPointer->getBottom();
        }
    }
    //if no headpointer, there is no list
    else
    {
        cout << "The linked list is empty!" << endl;
    }
}

DoublyLinkedList::~DoublyLinkedList()
{
    Space* current = NULL;
    
    //if no headpointer, print list
    if(headPointer->getRight() != NULL)
    {
        nodePointer = headPointer;
        do
        {

            current = nodePointer;
            nodePointer = nodePointer->getRight();
            delete current;
            
        }
        while(nodePointer != NULL && nodePointer != tailPointer);
        if(nodePointer == tailPointer)
        {
            delete tailPointer;
        }
    }
    else if(headPointer != NULL)
    {
        delete headPointer;
    }

}


