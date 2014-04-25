/***********************************************
** File:     TicTacToe.h
** Project:  CMSC 202 Project 4, Spring 14
** Author:   Paolo Frias
** Due Date: 4/25/14
** Section:  07
** E-mail:   pfrias2@umbc.edu
**
**   This defines the TicTacToe class. This is a derived class from GridGame
**	and contains methods and members more specific to TicTacToe.
***********************************************/

#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "GridGame.h"

const int TICTACTOE_BOARD_SIZE = 3;

class TicTacToe : public GridGame {
public:
	/****************************************************************
	* Name: TicTacToe
	*   Default (no-arg) constructor
	* Preconditions: None
	* Postconditions:
	*   Creates a 3x3 empty grid for TicTacToe and initializes
	*	players as X and O
	****************************************************************/
	TicTacToe();

	/****************************************************************
	* Name: TicTacToe
	*   Alternate constructor
	* Preconditions: None
	* Postconditions:
	*   Creates a 3x3 empty grid for TicTacToe and initializes
	*	players as provided playerSymbols
	****************************************************************/
	TicTacToe(const char *playerSymbols);

	/****************************************************************
	* Name: ~TicTacToe
	*   Default deconstructor
	* Preconditions: None
	* Postconditions:
	*   Deconstructs TicTacToe objects when need be
	****************************************************************/
	~TicTacToe();

	/****************************************************************
	* Name: IsDone
	*   Checks to see if the TicTacToe match is complete
	* Preconditions: None
	* Postconditions:
	*   return true if a player has achieved three in a row, or if
	*	if the board is filled- false otherwise
	****************************************************************/
	bool IsDone() const;

	/****************************************************************
	* Name: DoMove
	*   Calls DoBasicMove and allocated player symbol at
	*	specified coordinate on the board. Also contains logic that
	*	indicates if a game is over.
	* Preconditions: row and col must be legal coordinates
	* Postconditions:
	*   m_board now reflects chosen coordinates
	*	m_winner is initialized
	****************************************************************/
	void DoMove(int player, int row, int col);

	/****************************************************************
	* Name: OutputResults
	*   Displays who won the match, or if it ended in a tie
	* Preconditions: IsDone must return true
	* Postconditions:
	*   Prints out game summary
	****************************************************************/
	void OutputResults() const;

protected:
	char m_winner;

	//
	// SORRY, JANE DOE, BUT I DID NOT GET TO REALLY WORK ON
	// THIS MUCH--YOU SHOULD LOOK AT THE MOST EXCELLENT CODE IN
	// REVERSI TO SEE WHAT THIS SHOULD LOOK LIKE.
	//
	// I ALSO HAVE A PREMONITION THAT I WILL BE CHANGING THE REVERSI
	// CLASS A LOT, AND I HAVE THIS SINKING FEELING THAT I AM DESTINED
	// TO LOSE THE MODIFICATIONS, SO IF THAT HAPPENS, YOU SHOULD FINISH
	// UPGRADING REVERSI.H AND REVERSI.CPP FIRST BEFORE WORKING ON
	// THE TICTACTOE CLASS--IT MIGHT SAVE YOU A LOT OF WORK.
	//
	// THE PROFESSOR
	//

};

#endif //TICTACTOE_H