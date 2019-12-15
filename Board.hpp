/***************************************************************************
** Project Name: Final Project Cabin Builder
** Author: Daniel Mesa
** Date: 12/8/19
** Descriptin:  This is the class declaration for Board.
** It contains private data members and public methods called
** that creates the board of Space pointers and
** displays the movement of player object.
******************************************************************************/
#ifndef board_hpp
#define board_hpp

#include "Space.hpp"
#include "DoublyLinkedList.hpp"
#include "Die.hpp"


class Board {
    private:
        int rows,
            columns;
        Space** ptrToSpace;
        DoublyLinkedList** ptrToDLL; 
        Die die;
        Merchant* merchant;
    
    public:
    Board();
    Board(int ofrows, int ofcolumns);
    char whatIsSquare(int location[]);
    Space* getRandomLocation();
    void placeMerchant();
    void placePlot();
    void displayTheBoard(Space* aLocation);
    int getRows();
    int getColumns();
    ~Board();
    
    
};

#endif /* board_hpp */
