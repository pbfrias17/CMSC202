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

}

bool TicTacToe::IsDone() const { return false; }

void TicTacToe::OutputResults() const {}



//
// SEE THE APOLOGY IN TICTACTOE.H EXPLAINING THE PITIFUL STATE
// OF THIS FILE  --PROFESSOR
//