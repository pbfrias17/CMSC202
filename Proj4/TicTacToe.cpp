#include <iostream>
#include <cstring>
#include <cstdlib>
#include "TicTacToe.h"
#include <cstdlib>

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
	int row = 0, col = 0;
	int score[5];
	char player = m_playerSymbols(player);
	for (int row = 0; row <= m_boardSize; row++) {
		for (int col = 0; col <= m_boardSize; col++) {
			if (player == m_board[row][col] && row == 0 && col == 0) 
				score

	}

}

bool TicTacToe::IsDone() const {
	
	
	return false;
}
			

void TicTacToe::OutputResults() const {}



//
// SEE THE APOLOGY IN TICTACTOE.H EXPLAINING THE PITIFUL STATE
// OF THIS FILE  --PROFESSOR
//