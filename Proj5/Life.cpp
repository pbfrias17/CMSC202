#include "Life.h"
#include <iostream>
using namespace std;


Life::Life() 
: GridGame("Life", "O", LIFE_BOARD_SIZE) {
	m_tempBoard = new char *[LIFE_BOARD_SIZE];
	for(int r = 0; r < LIFE_BOARD_SIZE; r++) {
		m_tempBoard[r] = new char[LIFE_BOARD_SIZE];
		for(int c = 0; c < LIFE_BOARD_SIZE; c++) {
			m_tempBoard[r][c] = '-';
		}
	}
}

Life::Life(const char* playerSymbols)
: GridGame("Life", playerSymbols, LIFE_BOARD_SIZE) {
	m_tempBoard = new char *[LIFE_BOARD_SIZE];
	for(int r = 0; r < LIFE_BOARD_SIZE; r++) {
		m_tempBoard[r] = new char[LIFE_BOARD_SIZE];
		for(int c = 0; c < LIFE_BOARD_SIZE; c++) {
			m_tempBoard[r][c] = '-';
		}
	}
}

int Life::NumPlayers() const {
	return DEFAULT_LIFE_PLAYERS;
}

bool Life::IsDone() const {
	return false;
}

const char *Life::IsLegalMove(int player, int row, int col) const {
	if(row < 0 || row >= m_boardSize || col < 0 || col >= m_boardSize) {
		if(row == -1)
			return NULL;
		else
			return "Row or column out of range";
	} else if(m_board[row][col] != '-') {
		return "Position already played";
	} else {
		return NULL;
	}
}

void Life::DoMove(int player, int row, int col) {
	if(row == -1) {
		/**
		for(int i = 0; i < col; i++) {
			GenGen();
		}**/
		cout << "Generating next generation of cells...\n";
		GenGen();
	} else {
		DoBasicMove(player, row, col);
	}
}

void Life::GenGen() {

	for(int row = 0; row < m_boardSize; row++) {
		for(int col = 0; col < m_boardSize; col++) {
			if(m_board[row][col] != '-') {
				CheckSurrounding(true, row, col);
			} else {
				CheckSurrounding(false, row, col);
			}
		}
	}

}

void Life::CheckSurrounding(bool isFilled, int row, int col) {
	int occCount = 0;
	if(isFilled) {
		//checking each 3X3 grid
		for(int rInc = -1; rInc <= 1; rInc++) {
			for(int cInc = -1; cInc <= 1; cInc++) {
				if(row + rInc >= 0 && col + cInc >= 0)
					if(m_board[row + rInc][col + cInc] != '-')
						occCount++;
			}
		}
		if(occCount > 0) {
			cout << occCount << endl;
		}
	} else {
		//diff checking
	}
}

void Life::OutputResults() const {
	cout << "\nInside of Life object: outputting results...\n";
}