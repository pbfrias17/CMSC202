/***********************************************
** File:     GridGame.cpp
** Project:  CMSC 202 Project 4, Spring 14
** Author:   Paolo Frias
** Due Date: 4/25/14
** Section:  07
** E-mail:   pfrias2@umbc.edu
**
**   This is the GridGame class implementation. It defines all the
**	methods used in GridGame and it's derived classes.
***********************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "GridGame.h"

using namespace std;


GridGame::GridGame() {
	m_type = GAME_UNKNOWN;
	m_gameName = "Unknown";
}

GridGame::GridGame(enum GameType type, const char *gameName) {
	m_type = type;
	m_gameName = gameName;
}

GridGame::~GridGame() {}

/* Output a message saying:
* "Welcome to <GAME NAME>!\nHope you enjoy playing.\n"
*/
void GridGame::OutputGreeting() const {
	cout << "Welcome to " << m_gameName << "!\n";
}

char GridGame::GetPlayerSymbol(int player) const {
	if(player >= static_cast<int>(strlen(m_playerSymbols))) {
		cerr << "GetPlayerSymbol: illegal request\n";
		exit(1);
	}
	return m_playerSymbols[player];
}

int GridGame::GetBoardSize() const {
	return m_boardSize;
}

/* Returns NULL on good move, else returns err string.
* Note that this check is game-neutral (at least for TTT and Reversi)
*/
const char *GridGame::IsLegalMove(int player, int row, int col) const {
	if(row < 0 || row >= m_boardSize || col < 0 || col >= m_boardSize) {
		return "Row or column out of range";
	} else if(m_board[row][col] != '-') {
		return "Position already played";
	} else {
		return NULL;
	}
}

bool GridGame::InBounds(int row, int col, int boardSize) {
	return (row >= 0 && row < boardSize && col >= 0 && col < boardSize);
}


/*
* Puts new piece for player at {row, col} position
* Preconditions:
*   Assumes position has already been pre-checked by IsLegalMove() for
*   valid bounds and emptiness.
*/
void GridGame::DoBasicMove(int player, int row, int col) {
	const char *errStr;

	// We're paranoid--double-check
	if((errStr = IsLegalMove(player, row, col)) != NULL) {
		cerr << errStr << "--exiting\n";
		exit(1);
	}
	m_board[row][col] = m_playerSymbols[player];
}

void GridGame::OutputBoard() const {
	for(int r = 0; r < m_boardSize; r++) {
		for(int c = 0; c < m_boardSize; c++) {
			cout << m_board[r][c];
		}
		cout << endl;
	}
}

