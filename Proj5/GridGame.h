/***********************************************
** File:     GridGame.h
** Project:  CMSC 202 Project 5, Spring 14
** Author:   Paolo Frias
** Due Date: 5/14/14
** Section:  07
** E-mail:   pfrias2@umbc.edu
**
**   This defines the GridGame class. It's an abstract parent class 
**	for other grid based games.
**
***********************************************/

#ifndef GRIDGAME_H
#define GRIDGAME_H

class GridGame {
public:
	/****************************************************************
	* Name: GridGame
	*   Default (no-arg) constructor
	* Preconditions: None
	* Postconditions:
	*   Creates a board of unknown type and size of 0. FUN.
	****************************************************************/
    GridGame();

	/****************************************************************
	* Name: ~GridGame
	*   Default (no-arg) constructor
	* Preconditions: None
	* Postconditions:
	*   Deletes/Destructs the dynamically allocated game board when need be.
	****************************************************************/
    ~GridGame();

	/****************************************************************
	* Name: OutputGreeting
	*   Displays greeting to player based on gametype
	* Preconditions: None
	* Postconditions:
	*   Prints out greeting and m_gametype.
	****************************************************************/
    virtual void OutputGreeting() const;

	/****************************************************************
	* Name: NumPlayers
	*   Accessor for each game type's default player number
	* Preconditions: None
	* Postconditions:
	*   Returns DEFAULT_NUM_PLAYERS
	****************************************************************/
	virtual int NumPlayers() const;

	/****************************************************************
	* Name: IsDone
	*   Each game has different criteria for being finished.
	*	This is a pure virtual method.
	* Preconditions: None
	* Postconditions: None
	****************************************************************/
	virtual bool IsDone() const = 0;

	/****************************************************************
	* Name: GetPlayerSymbol
	*   Accessor for the player's symbol, depending on whose turn it is
	* Preconditions: None
	* Postconditions:
	*   Returns the symbol of the current player
	****************************************************************/
    virtual char GetPlayerSymbol(int player) const;

	/****************************************************************
	* Name: GetBoardSize
	*   Accessor for m_boardSize
	* Preconditions: None
	* Postconditions:
	*   Returns board size for the specified game type
	****************************************************************/
    int GetBoardSize() const;

	/****************************************************************
	* Name: IsLegalMove
	*   Returns NULL on good move, else returns err string.
    *   Note that this check is game-neutral (at least for TTT and Reversi)
	* Preconditions: None
	* Postconditions: None
	****************************************************************/
    virtual const char *IsLegalMove(int player, int row, int col) const;

	/****************************************************************
	* Name: DoMove
	*   Excutes the player's desired move onto the grid
	* Preconditions: Assumes IsLegalMove returns True
	* Postconditions: Board now reflects the new move
	****************************************************************/
	virtual void DoMove(int player, int row, int col);

	/****************************************************************
	* Name: OutputBoard
	*   Displays the grid board for all to see
	* Preconditions: None
	* Postconditions: 
	*   Prints out the game board
	****************************************************************/
    virtual void OutputBoard();

	/****************************************************************
	* Name: OutputResults
	*   Each game type has a different game summary, therefore this is
	*	a pure virtual method.
	* Preconditions: None
	* Postconditions: None
	****************************************************************/
	virtual void OutputResults() const = 0;


protected:

	/****************************************************************
	* Name: GridGame
	*   Alternate Constructor
	* Preconditions: None
	* Postconditions: 
	*	Creates a GridGame of specified type, size and player symbols
	****************************************************************/
    GridGame(const char *name, const char *playerSymbols, int boardSize);

	/****************************************************************
	* Name: DoBasicMove
	*   Simply puts a piece where the player wants.
	* Preconditions: DoMove is called before.
	* Postconditions: 
	*	Board now reflects players new move.
	****************************************************************/
    virtual void DoBasicMove(int player, int row, int col);
    
	char **m_board;
	int m_boardSize;

private:
    const char *m_gameName;
    const char *m_playerSymbols;

};

#endif //GRIDGAME_H
