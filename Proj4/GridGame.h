#ifndef GRIDGAME_H
#define GRIDGAME_H

#include "GameType.h"

class GridGame {
public:
	GridGame();

	GridGame(enum GameType type, const char *name);

	enum GameType GetType() { return m_type; }

protected:
	enum GameType m_type;
	const char *m_gameName;
};

#endif //GRIDGAME_H