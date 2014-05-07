#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe()
: GridGame(GAME_TICTACTOE, "Tic Tac Toe") {
	m_playerSymbols = "XO";

	m_boardSize = TICTACTOE_BOARD_SIZE;
	m_board = new char *[m_boardSize];
	for(int r = 0; r < m_boardSize; r++) {
		m_board[r] = new char[m_boardSize];
		for(int c = 0; c < m_boardSize; c++) {
			m_board[r][c] = '-';
		}
	}
}

TicTacToe::TicTacToe(const char *playerSymbols)
: GridGame(GAME_TICTACTOE, "Tic Tac Toe") {
	m_playerSymbols = playerSymbols;

	m_boardSize = TICTACTOE_BOARD_SIZE;
	m_board = new char *[m_boardSize];
	for(int r = 0; r < m_boardSize; r++) {
		m_board[r] = new char[m_boardSize];
		for(int c = 0; c < m_boardSize; c++) {
			m_board[r][c] = '-';
		}
	}
}

void TicTacToe::DoMove(int player, int row, int col) {
	DoBasicMove(player, row, col);
	char playerSym = GetPlayerSymbol(player);
	m_winner = GetPlayerSymbol(player);
	m_score = 0;
	for (int r = 0; r < m_boardSize; r++) {
		for (int c = 0; c < m_boardSize; c++) {
			if (playerSym == m_board[r][c]) {
				if (r == 0 && c == 0)
					m_score += 8;
				if (r == 0 && c == 1)
					m_score += 1;
				if (r == 0 && c == 2)
					m_score += 6;
				if (r == 1 && c == 0)
					m_score += 3;
				if (r == 1 && c == 1)
					m_score += 5;
				if (r == 1 && c == 2)
					m_score += 7;
				if (r == 2 && c == 0)
					m_score += 4;
				if (r == 2 && c == 1)
					m_score += 9;
				if (r == 2 && c == 2)
					m_score += 2;
			}
		}
	}
	if (m_score != 15)
		m_winner == NULL;

}

bool TicTacToe::IsDone() const {
	if (m_score == 15) {
		return true;
	} else {
		for (int row = 0; row < m_boardSize; row++) {
			for (int col = 0; col < m_boardSize; col++) {
				if (m_board[row][col] == '-') {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}
			

void TicTacToe::OutputResults() const {
	int myInt;
	if (m_winner != NULL) {
		cout << m_winner << " wins!\n";
	} else {
		cout << "Game is a tie\n";
	}
	cin >> myInt;
}



//
// SEE THE APOLOGY IN TICTACTOE.H EXPLAINING THE PITIFUL STATE
// OF THIS FILE  --PROFESSOR
//