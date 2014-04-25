/***********************************************
** File:     GridGame.h
** Project:  CMSC 202 Project 4, Spring 14
** Author:   Paolo Frias
** Due Date: 4/25/14
** Section:  07
** E-mail:   pfrias2@umbc.edu
**
**   This defines the GridGame class. This is a base class for more
**	specific grid based board games and contains general methods members
**	universal to many of them.
***********************************************/

#ifndef GRIDGAME_H
#define GRIDGAME_H

#include "GameType.h"

class GridGame {
public:
	/****************************************************************
	* Name: GridGame
	*   Default (no-arg) constructor
	* Preconditions: None
	* Postconditions:
	*   Creates a grid game of Unknown type and Unknown name.
	*	Very mysterious.
	****************************************************************/
	GridGame();

	/****************************************************************
	* Name: GridGame
	*   Alternate constructor
	* Preconditions: None
	* Postconditions:
	*   Creates a grid game of GameType and some name- as in,
	*	m_type and m_name are now defined
	****************************************************************/
	GridGame(enum GameType type, const char *name);

	/****************************************************************
	* Name: ~GridGame
	*   Default deconstructor
	* Preconditions: None
	* Postconditions:
	*   Deletes GridGame object when need be
	****************************************************************/
	~GridGame();

	/****************************************************************
	* Name: GetType
	*   Retrieves type of game
	* Preconditions: None
	* Postconditions:
	*   returns m_type of game
	****************************************************************/
	enum GameType GetType() { return m_type; }

	/****************************************************************
	* Name: OutputGreeting
	*   Displays greeting for specified grid game played
	* Preconditions: None
	* Postconditions:
	*   Prints out welcoming to players
	****************************************************************/
	void OutputGreeting() const;

	/****************************************************************
	* Name: GetPlayerSymbol
	*   Retrieves player symbol
	* Preconditions: None
	* Postconditions:
	*   returns player symbol for specified int player
	****************************************************************/
	char GetPlayerSymbol(int player) const;

	/****************************************************************
	* Name: GetBoardSize
	*   retrieves size of game board
	* Preconditions: None
	* Postconditions:
	*   return int m_boardSize for game
	****************************************************************/
	int GetBoardSize() const;

	/****************************************************************
	* Name: IsLegalMove
	*  Verifies that the input coordinates are legal
	* Preconditions: None
	* Postconditions:
	*   returns error if coordinates land outside of the game board
	*	or on an already exisiting piece- NULL otherwise
	****************************************************************/
	const char* IsLegalMove(int player, int row, int col) const;

	/****************************************************************
	* Name: InBounds
	*   Verifies if the coordinates are InBounds
	* Preconditions: called inside of IsLegalMove
	* Postconditions:
	*   returns false if coordinates land outisde of the game board
	*	-false otherwise
	****************************************************************/
	bool InBounds(int row, int col, int boardSize);

	/****************************************************************
	* Name: DoBasicMove
	*   Allocates playerSymbol at specified coordinate
	* Preconditions: row and col must be legal coordinates
	* Postconditions:
	*   m_board now reflects new move
	****************************************************************/
	void DoBasicMove(int player, int row, int col);

	/****************************************************************
	* Name: OutputBoard
	*   Displays board
	* Preconditions: None
	* Postconditions:
	*   Prints out m_board
	****************************************************************/
	void OutputBoard() const;

protected:
	int m_boardSize;
	const char *m_playerSymbols;
	char **m_board;
	enum GameType m_type;
	const char *m_gameName;
};

#endif //GRIDGAME_H