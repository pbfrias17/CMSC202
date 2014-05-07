#ifndef LIFE_H
#define LIFE_H

class Life: public GridGame {
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
