/***********************************************
** File:     TicTacToe.h
** Project:  CMSC 202 Project 5, Spring 14
** Author:   Paolo Frias
** Due Date: 5/14/14
** Section:  07
** E-mail:   pfrias2@umbc.edu
**
**   This defines the TicTacToe class. These are the mechanics for a 
**	game called "Tic Tac Toe". It is a very simple grid based game, so
**	only a few methods are needed to override.
**
***********************************************/

#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "GridGame.h"

const int TICTACTOE_BOARD_SIZE = 3;

class TicTacToe: public GridGame {
 public:
	 /****************************************************************
	 * Name: TicTacToe
	 *   Default no-arg constructor
	 * Preconditions: None
	 * Postconditions:
	 *	Creates and initializes a game of TicTacToe
	 ****************************************************************/
	TicTacToe();

	/****************************************************************
	* Name: TicTacToe
	*   Alternate constructor
	* Preconditions: None
	* Postconditions:
	*	Creates and initializes a game of TicTacToe with specified player symbols
	****************************************************************/
	TicTacToe(const char *playerSymbols);

	/****************************************************************
	* Name: IsDone
	*   Checks to see if m_winner has been found
	* Preconditions: None
	* Postconditions:
	*	Returns True if there's a winner- False otherwise
	****************************************************************/s
	bool IsDone() const;

	/****************************************************************
	* Name: FindWinner
	*	Checks to see if a player has achieved "3 in a row"
	* Preconditions: None
	* Postconditions:
	*	Returns True is "3 in a row" found or if the board if full-
	*	False otherwise
	****************************************************************/
	bool FindWinner(char& winner) const;

	/****************************************************************
	* Name: DoMove
	*   Simply called DoBasicMove
	* Preconditions: None
	* Postconditions:
	*	Board now reflects user input
	****************************************************************/
	void DoMove(int player, int row, int col);

	/****************************************************************
	* Name: OutputResults
	*   Displays game summary
	* Preconditions: None
	* Postconditions:
	*	Prints out the winner, or a tie if there was no winner
	****************************************************************/
	void OutputResults() const;

};

#endif //TICTACTOE_H
