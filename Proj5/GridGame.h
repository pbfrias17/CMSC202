#ifndef GRIDGAME_H
#define GRIDGAME_H

class GridGame {
public:
    GridGame();

    ~GridGame();

    virtual void OutputGreeting() const;

	virtual int NumPlayers() const;

	virtual bool IsDone() const = 0;

    virtual char GetPlayerSymbol(int player) const;

    int GetBoardSize() const;

    /* Returns NULL on good move, else returns err string.
     * Note that this check is game-neutral (at least for TTT and Reversi)
     */
    virtual const char *IsLegalMove(int player, int row, int col) const;

	virtual void DoMove(int player, int row, int col);

    virtual void OutputBoard();

	virtual void OutputResults() const = 0;


protected:
    GridGame(const char *name, const char *playerSymbols, int boardSize);

    virtual void DoBasicMove(int player, int row, int col);

    // The only data member that the subclassed games should really
    // need full read/write access to, once game is set up.
    char **m_board;
	int m_boardSize;
private:
    const char *m_gameName;
    const char *m_playerSymbols;

};

#endif //GRIDGAME_H
