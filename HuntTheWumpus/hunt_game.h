#ifndef _HUNT_GAME_H__
#define _HUNT_GAME_H__
#include <string>
#include <vector>
#include "agent.h"
#include "cavern.h"
#include "caverndanger.h"
#include "noncopy.h"

class CommandParser;
class HuntGame : public Noncopy
{
public:	
	~HuntGame();
	bool Initialize();
	bool IsOver() const;
	std::string PromptDanger() const;
	bool ValidParam(const CommandParser&) const;
	bool IsWin() const;
	void AgentAct(const CommandParser&);
	static HuntGame& getHuntGame();
	
private:
	HuntGame();
	bool game_over;
	Agent player_agent;
	std::vector<Cavern> game_map;
	CavernDanger dangers;
};  
#endif // !_HUNT_GAME_H__
