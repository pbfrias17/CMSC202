/****************************************************************
* Proj4.cpp:
*
****************************************************************/

#include <iostream>
#include <cstdlib>
#include "Proj4Aux.h"
#include "GridGame.h"

using namespace std;


int main(int argc, char *argv[]) {

	GridGame *game;
	//
	int myInput;
	//

	if ((game = SetupGame(argc, argv)) == NULL) {
		exit(1);
	}
	game->OutputGreeting();
	cin >> myInput;
	for (int player = 0; !GameSpecificIsDone(game); player = 1 - player) {
		DoOnePlayer(game, player);
		game->OutputBoard();
	}
	GameSpecificOutputResults(game);
}