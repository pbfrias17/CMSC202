/***********************************************
** File:     Reversi.h
** Project:  CMSC 202 Project 4, Spring 14
** Author:   Paolo Frias
** Due Date: 4/25/14
** Section:  07
** E-mail:   pfrias2@umbc.edu
**
**   This defines the Reversi class. This is a derived class from GridGame
**	and contains methods and members more specific to Reversi.
***********************************************/

#ifndef REVERSI_H
#define REVERSI_H
#include "GridGame.h"

const int REVERSI_BOARD_SIZE = 8;

class Reversi : public GridGame {
public:
	/****************************************************************
	* Name: Reversi
	*   Default (no-arg) constructor
	* Preconditions: None
	* Postconditions:
	*   Creates an empty square grid of REVERSI_BOARD_SIZE and 
	*	initializes players as X and O
	****************************************************************/
	Reversi();

	/****************************************************************
	* Name: Reversi
	*   Alternate constructor
	* Preconditions: None
	* Postconditions:
	*   Creates an empty square grid of REVERSI_BOARD_SIZE and 
	*	initializes players as provided playerSymbols
	****************************************************************/
	Reversi(const char *playerSymbols);

	/****************************************************************
	* Name: ~Reversi
	*   Default deconstructor
	* Preconditions: None
	* Postconditions:
	*   Deletes Reversi object when need be
	****************************************************************/
	~Reversi();

	/****************************************************************
	* Name: IsDone
	*   Checks to see if the Reversi match is complete
	* Preconditions: None
	* Postconditions:
	*   returns true if the board is completely filled- 
	*	otherwise returns false
	****************************************************************/
	bool IsDone() const;

	/****************************************************************
	* Name: DoMove
	*   Calls DoBasicMove to allocate playerSymbol on specified
	*	space. Also 'flips' symbols accordingly.
	* Preconditions: row and col must be legal coordinates
	* Postconditions:
	*   m_board now reflects new move and all affected symbols
	****************************************************************/
	void DoMove(int player, int row, int col);

	/****************************************************************
	* Name: OutputResults
	*   Displays game summary
	* Preconditions: IsDone must return true
	* Postconditions:
	*   Prints out the winner of the match (most points) or a tie
	*	if the players have the same points
	****************************************************************/
	void OutputResults() const;

protected:

	/****************************************************************
	* Name: FlipTilesInDir
	*   Main reversi game logic that flips tiles according
	*	to the rules of the game
	* Preconditions: called after DoMove is successful
	* Postconditions:
	*   Checks all 8 directions from the specified row and col to
	*	see if any tiles need to be flipped
	****************************************************************/
	void FlipTilesInDir(char playerSym, int row, int rowIncr,
		int col, int colIncr);
};

#endif //REVERSI_H