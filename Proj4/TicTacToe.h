#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "GridGame.h"

const int TICTACTOE_BOARD_SIZE = 3;

class TicTacToe : public GridGame {
public:
	/*
	* Move as many of these member functions as REASONABLE up
	* into common parent class
	*/
	TicTacToe();

	TicTacToe(const char *playerSymbols);

	bool IsDone() const;

	void DoMove(int player, int row, int col);

	void OutputResults() const;


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