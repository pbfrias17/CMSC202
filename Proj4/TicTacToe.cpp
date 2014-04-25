/***********************************************
** File:     TicTacToe.cpp
** Project:  CMSC 202 Project 4, Spring 14
** Author:   Paolo Frias
** Due Date: 4/25/14
** Section:  07
** E-mail:   pfrias2@umbc.edu
**
**   This is the TicTacToe class implementation. It defines methods
**	used only in TicTacToe game objects.
***********************************************/

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

TicTacToe::~TicTacToe() {}

void TicTacToe::DoMove(int player, int row, int col) {
	DoBasicMove(player, row, col);
	char playerSym = GetPlayerSymbol(player);
	//Used m_winner member to store the winner's symbol for use
	//in result outputting.
	m_winner = NULL;
	
	//Brute force checking :c
	//First check to see if the 'middle' spaces are taken, then check
	//if it is also surrounded by the player's symbols.
	//Used fixed numbers here since Tic Tac Toe is always a 3x3 grid game.
	if(m_board[0][1] == playerSym) {
		if(m_board[0][0] == playerSym && m_board[0][2] == playerSym) {
			m_winner = playerSym;
		}
	}
	if(m_board[1][0] == playerSym) {
		if(m_board[0][0] == playerSym && m_board[2][0] == playerSym) {
			m_winner = playerSym;
		}
	}
	if(m_board[1][2] == playerSym) {
		if(m_board[0][2] == playerSym && m_board[2][2] == playerSym) {
			m_winner = playerSym;
		}
	}
	if(m_board[2][1] == playerSym) {
		if(m_board[2][0] == playerSym && m_board[2][2] == playerSym) {
			m_winner = playerSym;
		}
	}
	if(m_board[1][1] == playerSym) {
		if(m_board[0][0] == playerSym && m_board[2][2] == playerSym) {
			m_winner = playerSym;
		} else if(m_board[0][1] == playerSym && m_board[2][1] == playerSym) {
			m_winner = playerSym;
		} else if(m_board[0][2] == playerSym && m_board[2][0] == playerSym) {
			m_winner = playerSym;
		} else if(m_board[1][0] == playerSym && m_board[1][2] == playerSym) {
			m_winner = playerSym;
		}
	}
}

bool TicTacToe::IsDone() const {
	if(m_winner != NULL) {
		return true;
	} else {
		//Game is also over if the board is completely filled, regardless of 
		//whether or not a player has achieved Tic Tac Toe.
		for(int r = 0; r < m_boardSize; r++) {
			for(int c = 0; c < m_boardSize; c++) {
				if(m_board[r][c] == '-')
					return false;
			}
		}
		return true;
	}

}
			

void TicTacToe::OutputResults() const {
	//If m_winner is not NULL, a player won. Otherwise, no one won
	//and the game is a tie.
	if(m_winner != NULL)
		cout << "\nPlayer " << m_winner << " wins!\n";
	else
		cout << "\nThe game is a tie.\n";

	int myInt;
	cin >> myInt;
}

//
// SEE THE APOLOGY IN TICTACTOE.H EXPLAINING THE PITIFUL STATE
// OF THIS FILE  --PROFESSOR
//