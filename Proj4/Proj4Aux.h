#ifndef PROJ4AUX_H
#define PROJ4AUX_H

#include "GridGame.h"

/****************************************************************
* Name: Fraction
*   Default (no-arg) constructor
* Preconditions: None
* Postconditions:
*   Creates a mixed number of 0&0/1
****************************************************************/
GridGame *SetupGame(int argc, char *argv[]);

/****************************************************************
* Name: Fraction
*   Default (no-arg) constructor
* Preconditions: None
* Postconditions:
*   Creates a mixed number of 0&0/1
****************************************************************/
bool GameSpecificIsDone(GridGame *game);


void DoOnePlayer(GridGame *game, int player);
void GameSpecificOutputResults(GridGame *game);

#endif //PROJ4AUX_H