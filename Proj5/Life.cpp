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
		GenGen();
	} else {
		DoBasicMove(player, row, col);
	}
}

void Life::GenGen() {

	for(int row = 0; row < m_boardSize; row++) {
		for(int col = 0; col < m_boardSize; col++) {
			if(m_board[row][col] != '-') {
				cout << "found a filled cell:\n";
				CheckSurrounding(true, row, col);
			} else {
				cout << "found an empty cell:\n";
				CheckSurrounding(false, row, col);
			}
		}
	}

}

void Life::CheckSurrounding(bool isFilled, int row, int col) {
	/////
	int myInt;
	cin >> myInt;
	/////
	int neighbors = 0;
	for(int rInc = -1; rInc <= 1; rInc++) {
		for(int cInc = -1; cInc <= 1; cInc++) {
			if(row + rInc >= 0 && col + cInc >= 0)
			if(m_board[row + rInc][col + cInc] != '-')
				neighbors++;
		}
	}
	/////////////////
	if(isFilled)
		cout << "\tthere are " << neighbors - 1 << " neighbors around this cell\n";
	else
		cout << "\tthere are " << neighbors << " neighbors around this cell\n";
	
	if(isFilled) {
		//subtract 1 from neighbors because we don't consider the center piece as a neighbor to itself
		if(neighbors - 1 < 2) {
			cout << "\tdied of loneliness\n";
		} else if(neighbors - 1 >= 2 && neighbors - 1 <= 3) {
			cout << "\tcell stays put\n";
		} else {
			cout << "\tcell dies of overcrowding\n";
		}
	} else {
		if(neighbors >= 3)
			cout << "\treproduction! new cell added\n";
		else
			cout << "\tnothing happens blah\n";
	}
}

void Life::OutputResults() const {
	cout << "\nInside of Life object: outputting results...\n";
}