#ifndef LIFE_H
#define LIFE_H

#include "GridGame.h"

//LIFE_BOARD_SIZE should be 20 in this demonstration----
const int LIFE_BOARD_SIZE = 20;
const int DEFAULT_LIFE_PLAYERS = 1;

class Life: public GridGame {
	public:
		Life();
		Life(const char *playerSymbols);
		int NumPlayers() const;
		void DoMove(int player, int row, int col);
		bool IsDone() const;
		void OutputResults() const;

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
