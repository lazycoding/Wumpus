#pragma once
#include "Cave.h"
#include "Hunter.h"
#include "Wumpus.h"


class WumpusGame
{
public:
	enum CMD { NONE = 0, MOVE, SHOOT };
	WumpusGame(void);
	~WumpusGame(void);

	int Initialize(int caveRoom);
	int Start();
	int Stop();
	void ExcetuCommand(CMD command, int roomId);
	int PraseCommand( CMD& lastCmd );
	void GameOver(bool reAgain);
	bool WumpusEatHunter();
	void Prompt();
	bool DroptoTrap(int roomId);
private:
	CMD		lastCmd;
	Cave	cave;
	Hunter	hunter;
	Wumpus  wumpus;
};

