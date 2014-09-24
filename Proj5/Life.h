/***********************************************
** File:     Life.h
** Project:  CMSC 202 Project 5, Spring 14
** Author:   Paolo Frias
** Due Date: 5/14/14
** Section:  07
** E-mail:   pfrias2@umbc.edu
**
**   This defines the Life class. These are the mechanics of a
**	game called "Conway's Way of Life". This is a more unique grid based
**	game, therefore more methods here override the parent's.
**
***********************************************/

#ifndef LIFE_H
#define LIFE_H

#include "GridGame.h"

const int LIFE_BOARD_SIZE = 20;
const int DEFAULT_LIFE_PLAYERS = 1;

class Life: public GridGame {
	public:
		/****************************************************************
		* Name: Life
		*   Default no-arg constructor
		* Preconditions: None
		* Postconditions: 
		*	Creates and initializes a game of Life
		****************************************************************/
		Life();

		/****************************************************************
		* Name: Life
		*   Alternate constructor
		* Preconditions: None
		* Postconditions:
		*	Creates and initializes a game of Life with specified player symbols.
		****************************************************************/
		Life(const char *playerSymbols);

		/****************************************************************
		* Name: NumPlayers
		*   Accessor for DEFAULT_LIFE_PLAYERS
		* Preconditions: None
		* Postconditions:
		*	Returns 1 since Life is a one player game.
		****************************************************************/
		int NumPlayers() const;

		/****************************************************************
		* Name: IsLegalMove
		*   Verifies that a move is inbounds and/or accepted in the game
		* Preconditions: None
		* Postconditions:
		*	Returns an error string if not legal- NULL otherwise. The
		*	game of Life accepts Zeros and inputs. 
		****************************************************************/
		const char *IsLegalMove(int player, int row, int col) const;

		/****************************************************************
		* Name: DoMove
		*   Based on player input, either places/removes pieces from the board
		*	or automatically generates new boards.
		* Preconditions: IsLegalMove must be true
		* Postconditions:
		*	Board now reflects player input.
		*	And/or new boards are created.
		****************************************************************/
		void DoMove(int player, int row, int col);

		/****************************************************************
		* Name: DoBasicMove
		*   Places/Removes a piece on the board based on user input
		* Preconditions: Always called inside of DoMove
		* Postconditions:
		*	Board now reflects player input.
		****************************************************************/
		void DoBasicMove(int player, int row, int col);

		/****************************************************************
		* Name: OutputBoard
		*   Displays the board(s)
		* Preconditions: None
		* Postconditions:
		*	Displays the board. The number of times a new board is displayed
		*	depends on the player input.
		****************************************************************/
		void OutputBoard();

		/****************************************************************
		* Name: Life
		*   Checks to see if the user is done playing.
		* Preconditions: None
		* Postconditions:
		*	Returns True if player input "0, 0"- False otherwise.
		*	If True, board is displayed one last time
		****************************************************************/
		bool IsDone() const;

		/****************************************************************
		* Name: OutputResults
		*   Displays game summary
		* Preconditions: None
		* Postconditions:
		*	Prints out the number of generations generated and the number
		*	of cells remaining.
		****************************************************************/
		void OutputResults() const;

	private:
		/****************************************************************
		* Name: GenGen
		*   Generates the next generation of cells
		* Preconditions: None
		* Postconditions:
		*	Using predetermined rules, the next iteration of cells is 
		*	generated.
		****************************************************************/
		void GenGen(int player);

		/****************************************************************
		* Name: CheckSurrounding
		*   Counts all the neighbors that are around each cell of the game board
		*	and maps them out onto a logic board
		* Preconditions: None
		* Postconditions:
		*	The logic board (m_boolBoard) now reflects the newly generated cells
		****************************************************************/
		void CheckSurrounding(bool isFilled, int row, int col);

		bool m_done;
		int m_genCount;
		int m_iterations;
		bool m_boolBoard[LIFE_BOARD_SIZE][LIFE_BOARD_SIZE];


  /*
   * YOUR CODE HERE.
   * MUST HAVE:
   *
   *   default constructor: calls parent's constructor with "O"
   *	
   *   1-arg constructor: takes a char* pointing to a string of
   *     player symbols (will always be a single-echar string),
   *     passes that to GridGame's constructor
   *
   * Virtual functions from GridGame that you might, or might not, want
   * to override in this class:
   *   OutputGreeting()
   *   NumPlayers()  NEW
   *   IsDone();
   *   OutputBoard()
   *   OutputResults()
   *   GetPlayerSymbol()int player)
   *   const char * IsLegalMove(int player, int row, int col)
   *   DoMove(int player, int row, int col)
   *
   * Some of these definitely have to be overridden.  Read the
   * project description for an explanation of how we have adapted
   * the Life game to work like a GridGame--that should provide
   * enough information to decide what you need to do.  For example,
   * the functions IsLegalMove() and DoMove() will very likely
   * need overriding.
   */

};

#endif //LIFE_H
