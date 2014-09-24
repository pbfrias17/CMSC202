/***********************************************
** File:     Reversi.h
** Project:  CMSC 202 Project 5, Spring 14
** Author:   Paolo Frias
** Due Date: 5/14/14
** Section:  07
** E-mail:   pfrias2@umbc.edu
**
**   This defines the Reversi class. These are the mechanics for a 
**	game called "Reversi". Aside from a few exceptions, it is similar to
**	other grid based games, like Tic Tac Toe.
**
***********************************************/

#ifndef REVERSI_H
#define REVERSI_H
#include "GridGame.h"

const int REVERSI_BOARD_SIZE = 4;

class Reversi: public GridGame {
 public:
	/****************************************************************
	* Name: Reversi
	*   Default no-arg constructor
	* Preconditions: None
	* Postconditions:
	*	Creates and initializes a game of Reversi
	****************************************************************/
	Reversi();

	/****************************************************************
	* Name: Reversi
	*   Alternate constructor
	* Preconditions: None
	* Postconditions:
	*	Creates and initializes a game of Reversi with specified player symbols
	****************************************************************/
	Reversi(const char *playerSymbols);

	/****************************************************************
	* Name: IsDone
	*   Checks to see if the board is full
	* Preconditions: None
	* Postconditions:
	*	Returns true if full- False otherwise
	****************************************************************/
	bool IsDone() const;

	/****************************************************************
	* Name: DoMove
	*   Calls DoBasicMove and then calls FlipTilesInDir
	* Preconditions: None
	* Postconditions:
	*	Board now reflects the new move and affected pieces
	****************************************************************/
	void DoMove(int player, int row, int col);

	/****************************************************************
	* Name: Reversi
	*   Displays Reversi game summary
	* Preconditions: None
	* Postconditions:
	*	Prints out the winner of the game and the number of points
	*	that each player had.
	****************************************************************/
	void OutputResults() const;

  private:
	/****************************************************************
	* Name: Reversi
	*   Simply verifies if the user input a coordinate that exists on the board
	* Preconditions: None
	* Postconditions:
	*	Returns True if on the board- False otherwise
	****************************************************************/
	static bool InBounds(int row, int col, int boardSize);

	/****************************************************************
	* Name: FlipTilesInDir
	*   Main Reversi game logic that checks to see if any of the tiles
	*	will be flipped
	* Preconditions: Always called in DoMove, after DoBasicMove
	* Postconditions:
	*	Board now reflects user input and all the tiles that were flipped
	****************************************************************/
	void FlipTilesInDir(char playerSym, int row, int rowIncr,
				int col, int colIncr);
};

#endif //REVERSI_H
