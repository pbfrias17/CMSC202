#ifndef GRIDGAME_H
#define GRIDGAME_H

#include "GameType.h"

class GridGame {
public:
	GridGame();

	GridGame(enum GameType type, const char *name);

	enum GameType GetType() { return m_type; }

	void OutputGreeting() const;

	char GetPlayerSymbol(int player) const;

	int GetBoardSize() const;

	const char* IsLegalMove(int player, int row, int col) const;

	bool InBounds(int row, int col, int boardSize);

	void DoBasicMove(int player, int row, int col);

	void OutputBoard() const;

protected:
	int m_boardSize;
	const char *m_playerSymbols;
	char **m_board;
	enum GameType m_type;
	const char *m_gameName;
};

#endif //GRIDGAME_H