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
	if(row == 0) {
		/**
		for(int i = 0; i < col; i++) {
			GenGen();
		}**/
		GenGen();
	}
}

void Life::GenGen() {
	int row = 0, col = 0, count = 0, occCount = 0;
	for(int row = 0; row < m_boardSize; row++) {
		for(int col = 0; col < m_boardSize; col++) {
			if(m_board[row][col] != '-') {
				occCount++;
			}
		}
	}

	cout << occCount << endl;
}

void Life::OutputResults() const {
	cout << "\nInside of Life object: outputting results...\n";
}