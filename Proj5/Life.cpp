/***********************************************
** File:     Life.cpp
** Project:  CMSC 202 Project 5, Spring 14
** Author:   Paolo Frias
** Due Date: 5/14/14
** Section:  07
** E-mail:   pfrias2@umbc.edu
**
**   This defines the Life class implementation. It provides the logic
**	used to automatically generate boards (generations) using a predetermined
**	set of rules. 
**
***********************************************/


/****************************************************************
* Name: Fraction
*   Default (no-arg) constructor
* Preconditions: None
* Postconditions:
*   Creates a mixed number of 0&0/1
****************************************************************/

#include "Life.h"
#include <iostream>
using namespace std;


Life::Life() 
: GridGame("Life", "O", LIFE_BOARD_SIZE), m_done(false), m_genCount(0){}

Life::Life(const char* playerSymbols)
: GridGame("Life", playerSymbols, LIFE_BOARD_SIZE), m_done(false), m_genCount(0) {}

int Life::NumPlayers() const {
	return DEFAULT_LIFE_PLAYERS;
}

bool Life::IsDone() const {
	return m_done;
}

const char *Life::IsLegalMove(int player, int row, int col) const {
	if(row < 0 || row >= m_boardSize || col < 0 || col >= m_boardSize) {
		if(row == -1)
			return NULL;
		else
			return "Row or column out of range";
	} else {
		return NULL;
	}
}

void Life::DoMove(int player, int row, int col) {
	if(row == -1) {
		if(col != -1) {
			m_genCount += col + 1;
			m_iterations = col + 1;
			GenGen(player);
		} else {
			m_done = true;
		}
	} else {
		m_iterations = 0;
		DoBasicMove(player, row, col);
	}

}

void Life::DoBasicMove(int player, int row, int col) {
	const char *errStr;

	// We're paranoid--double-check
	if((errStr = IsLegalMove(player, row, col)) != NULL) {
		cerr << errStr << "--exiting\n";
		exit(1);
	}

	if(m_board[row][col] == '-') {
		m_board[row][col] = GetPlayerSymbol(player);
	} else {
		m_board[row][col] = '-';
	}
}

void Life::GenGen(int player) {
	//create a 2d bool array to map out the next generation
	for(int r = 0; r < m_boardSize; r++) {
		for(int c = 0; c < m_boardSize; c++) {
			m_boolBoard[r][c] = 0;
		}
	}

	for(int row = 0; row < m_boardSize; row++) {
		for(int col = 0; col < m_boardSize; col++) {
			if(m_board[row][col] != '-') {
				CheckSurrounding(true, row, col);
			} else {
				CheckSurrounding(false, row, col);
			}
		}
	}

	//Mapping out the new board
	char symbol = GetPlayerSymbol(player);
	for(int row = 0; row < m_boardSize; row++) {
		for(int col = 0; col < m_boardSize; col++) {
			if(m_boolBoard[row][col]) {
				m_board[row][col] = symbol;
			} else {
				m_board[row][col] = '-';
			}
		}
	}
	
}

void Life::CheckSurrounding(bool isFilled, int row, int col) {

	int neighbors = 0;
	for(int rInc = -1; rInc <= 1; rInc++) {
		for(int cInc = -1; cInc <= 1; cInc++) {
			if(row + rInc >= 0 && col + cInc >= 0 && row + rInc < m_boardSize && col + cInc < m_boardSize) {
				if(m_board[row + rInc][col + cInc] != '-') {
					neighbors++;
				}
			}
		}
	}

	//Actually generating the next generation
	if(isFilled) {
		//subtract 1 from neighbors because we don't consider the center piece as a neighbor to itself
		if(neighbors - 1 < 2) {
			m_boolBoard[row][col] = 0;
		} else if(neighbors - 1 >= 2 && neighbors - 1 <= 3) {
			m_boolBoard[row][col] = 1;
		} else {
			m_boolBoard[row][col] = 0;
		}
	} else {
		if(neighbors >= 3) {
			m_boolBoard[row][col] = 1;
		}
	}
}

void Life::OutputBoard() {
	do {

		for(int r = 0; r < m_boardSize; r++) {
			for(int c = 0; c < m_boardSize; c++) {
				cout << m_board[r][c];
			}
			cout << endl;
		}

		if(m_iterations > 0)
			m_iterations--;

		if(m_iterations != 0) {
			GenGen(0);
			cout << endl;
		}
	} while(m_iterations > 0);
		

}

void Life::OutputResults() const {
	int count = 0;
	for(int r = 0; r < m_boardSize; r++) {
		for(int c = 0; c < m_boardSize; c++) {
			if(m_board[r][c] != '-')
				count++;
		}
	}

	cout << "\nWent through " << m_genCount << " generations.\n";
	cout << "There are " << count << " cells living.\n";

	int myInt;
	cin >> myInt >> myInt;
}