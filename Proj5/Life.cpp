#include "Life.h"
#include <iostream>
using namespace std;


Life::Life() 
: GridGame("Life", "O", LIFE_BOARD_SIZE) {}

Life::Life(const char* playerSymbols)
: GridGame("Life", playerSymbols, LIFE_BOARD_SIZE) {}

bool Life::IsDone() const {
	return true;
}

void Life::OutputResults() const {
	cout << "\nInside of Life object: outputting results...\n";
}