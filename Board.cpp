/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the source code for class Board.
** It contains methods that creates the board of Space pointers and
** displays the movement of player object.
******************************************************************************/
#include "Board.hpp"
#include <iostream>

/***************************************************************************
** Board::Board()
** This is the default constructor that initializes the array/board
** with 0.
******************************************************************************/
Board::Board()
{
    rows = 0;
    columns = 0;
}

/***************************************************************************
** Board::Board(int ofrows, int ofcolumns)
** This parametered constructor initializes the row and columns
** to create board size and populates the board with spaces pointers.
** It creates DoublyLInkedLists to the size of columns and
** connects all the space pointers together to form a board.
** It takes in two int parameters of row and colum.
******************************************************************************/
Board::Board(int ofrows, int ofcolumns)
    {
    
    //setting variables
    rows = ofrows;
    columns = ofcolumns;
    
    //create array of pointers for board rows
    ptrToDLL = new DoublyLinkedList*[rows];
    
        //allocate array of column sized memory for each row
        for (int i = 0; i < rows; i++)
        {
            ptrToDLL[i] = new DoublyLinkedList(columns);
        }
        
        Space* tempPointerA = NULL;
        Space* tempPointerB = NULL;
        Space* tempPointerC = NULL;
        
        for(int i = 0; i < rows-1; i++)
        {
            if(i == 0)
            {
                tempPointerA = ptrToDLL[i]->getHeadPointer();
                tempPointerB = ptrToDLL[rows-1]->getHeadPointer();
                tempPointerC = ptrToDLL[i+1]->getHeadPointer();
            }
            else
            {
                tempPointerA = ptrToDLL[i]->getHeadPointer();
                tempPointerB = ptrToDLL[i+1]->getHeadPointer();
                tempPointerC = ptrToDLL[i-1]->getHeadPointer();
            }
            for(int j = 0; j < columns; j++)
            {
                if(i == 0)
                {
                    //set the top and bottom for edges cases (top and bottom)
                    tempPointerA->setTop(tempPointerB);
                    tempPointerA->setBottom(tempPointerC);
                    tempPointerB->setBottom(tempPointerA);
                    
                    
                    //set headpointer to next node to traverse it
                    tempPointerA = tempPointerA->getRight();
                    tempPointerB = tempPointerB->getRight();
                    tempPointerC = tempPointerC->getRight();
                    
                }
                else
                {
                    tempPointerA->setBottom(tempPointerB);
                    tempPointerB->setTop(tempPointerA);
                    tempPointerA->setTop(tempPointerC);
                    
                    //set headpointer to next node to traverse it
                    tempPointerA = tempPointerA->getRight();
                    tempPointerB = tempPointerB->getRight();
                    tempPointerC = tempPointerC->getRight();
                }
                
            
                
            }
        }
        
        
        placeMerchant();
        placePlot();
    
};

/***************************************************************************
** int Board::getRows()
** This method returns the row size.
******************************************************************************/
int Board::getRows()
{
    return rows;
};

/***************************************************************************
** int Board::getColumns()
** This method returns the column size.
******************************************************************************/
int Board::getColumns()
{
    return columns;
};

/***************************************************************************
** void Board::placeMerchant()
** This method changes the char of a merchant object to M so that
** it can be displayed on the board.
** square at that location. It takes no parameters and has no return.
******************************************************************************/

void Board::placeMerchant()
{
    
    Space* tempPointerA = NULL;
    bool changed = false;
    //iterate through board
    for(int i = 0; i < rows; i++)
    {
        tempPointerA = ptrToDLL[i]->getHeadPointer();
        
        for(int j = 0; j < columns; j++)
        {
            //print player instead of char
            // at location
            if(tempPointerA->getSquare() == 'H')
            {
                if(changed == false)
                {
                    tempPointerA->changeSquare('M');
                    changed = true;
                }
                
                
            }
            
            //traverse to next pointer
            tempPointerA = tempPointerA->getRight();
    
         }

    }
    

};

/***************************************************************************
** void Board::placePlot()
** This method changes the char of a random object to P so that
** it can be displayed on the board as the land plot.
** square at that location. It takes no parameters and has no return.
******************************************************************************/
void Board::placePlot()
{
    
    Space* tempPointerA = NULL;
    bool changed = false;
    //iterate through board
    for(int i = 0; i < rows; i++)
    {
        tempPointerA = ptrToDLL[i]->getHeadPointer();
        
        for(int j = 0; j < columns; j++)
        {
            //print player instead of char
            // at location
            if(tempPointerA->getSquare() == 'O')
            {
                if(changed == false)
                {
                    tempPointerA->changeSquare('P');
                    changed = true;
                }
                
                
            }
            
            //traverse to next pointer
            tempPointerA = tempPointerA->getRight();
    
         }

    }
    

    
};
/***************************************************************************
** void Board::placePlot()
** This method finds a random pointer on the board and returns it.
** It takes no parameters and returns a Space pointer.
******************************************************************************/
Space* Board::getRandomLocation()
{
    die.setSides(rows);
    //account for zero row
    int randomRow = die.rollingDie() - 1;
    
    die.setSides(columns);
    //account for zero column
    int randomColumn = die.rollingDie() - 1;
    
    Space* tempPointer = NULL;
    
    tempPointer = ptrToDLL[randomRow]->getHeadPointer();
    
    for(int i = 0; i < randomColumn; i++)
    {
        tempPointer = tempPointer->getRight();
    }
    
    return tempPointer;
}

/***************************************************************************
** void Board::displayTheBoard(Space* aLocation)
** This method displays the board with player location.
** It takes a Space pointer as a parameter which is the
** players current location and has no return.
******************************************************************************/
void Board::displayTheBoard(Space* aLocation)
{
    Space* tempPointerA = NULL;
    
    //print board
    for(int i = 0; i < rows; i++)
    {
        tempPointerA = ptrToDLL[i]->getHeadPointer();
        
        for(int j = 0; j < columns; j++)
        {
            //print player instead of char
            // at location
            if(tempPointerA == aLocation)
            {
                std::cout << 'i';
            }

            //else if player is merchant or plot
            else if(tempPointerA->getSquare() == 'M' || tempPointerA->getSquare() == 'P')
            {
                std::cout << tempPointerA->getSquare();
            }
            //else print a tree
            else
            {
                std::cout << 'Y';
            }
            
            //traverse to next pointer
            tempPointerA = tempPointerA->getRight();
    
         }
        
        //print row enter
        std::cout << "\n";
    }
    
    
}

/***************************************************************************
** Board::~Board()
** This is the destructor the frees the memory.
******************************************************************************/
Board::~Board()
{
    //deallocate array of column sized memory for each row
    for (int i = 0; i < rows; i++)
    {
        delete ptrToDLL[i];
    }
}
