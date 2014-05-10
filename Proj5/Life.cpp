#include "Life.h"
#include <iostream>
using namespace std;


Life::Life() 
: GridGame("Life", "O", LIFE_BOARD_SIZE) {}

Life::Life(const char* playerSymbols)
: GridGame("Life", playerSymbols, LIFE_BOARD_SIZE) {}

int Life::NumPlayers() const {
	return DEFAULT_LIFE_PLAYERS;
}

bool Life::IsDone() const {
	return false;
}

void Life::DoMove(int player, int row, int col) {
	DoBasicMove(player, row, col);
}

void Life::OutputResults() const {
	cout << "\nInside of Life object: outputting results...\n";
}