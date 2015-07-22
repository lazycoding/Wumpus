#include "hunt_game.h"
#include <cassert>
#include <ctime>
#include <iostream>
#include <sstream>
#include <memory>
#include "command_parser.h"
#include "lazy_random_helper.h"
#include "commandFactory.h"
#include "command.h"
using namespace std;

class CavernsBuilder
{
public:
	static bool Link(vector<Cavern>* map);
	static const int kMaxCavern;
};
const int CavernsBuilder::kMaxCavern = 20;

bool CavernsBuilder::Link(vector<Cavern>* map)
{
	lazy::random::setsrand();
	map->reserve(CavernsBuilder::kMaxCavern);
	for (int i = 0; i < CavernsBuilder::kMaxCavern; i++)
	{
		map->push_back(Cavern());
		map->at(i).setSerial(i);
	}
	typedef vector<Cavern>::iterator cavern_it;

	for(cavern_it iter = map->begin(); iter != map->end(); ++iter)
	{
		while(iter->LinkedSize() < 3)
		{
			int link_to = lazy::random::randint(map->size());
			Cavern& cavern = map->at(link_to);
			if(cavern.LinkedSize() < 3)
			{
				bool success_link = iter->LinkTo(&cavern);
			}
		}
	}
	return true;
}

class DangersBuilder
{
public:
	DangersBuilder()
	{
		lazy::random::setsrand();
	}
	
	static void GenerateDanger(CavernDanger* dangers, int count_of_caverns)
	{
		int wumpus_cavern = lazy::random::randint(count_of_caverns);
		dangers->setDanger(wumpus_cavern, Danger::Wumpus);		
		int bat_cavern = -1;
		while (true)
		{
			bat_cavern = lazy::random::randint(count_of_caverns);
			if(wumpus_cavern != bat_cavern)
			{	
				dangers->setDanger(bat_cavern, Danger::Bat);
				break;
			}
		}
		while (true)
		{
			int trap_cavern = lazy::random::randint(count_of_caverns);
			if(trap_cavern != bat_cavern && trap_cavern != wumpus_cavern)
			{
				dangers->setDanger(trap_cavern, Danger::Trap);
				break;
			}
		}
	}
};

HuntGame& HuntGame::getHuntGame()
{
	static HuntGame instance;
	return instance;
}

HuntGame::HuntGame()
	:game_over(false)
{

}

HuntGame::~HuntGame()
{

}

bool HuntGame::Initialize()
{
	bool init_success = CavernsBuilder::Link(&game_map);
	if(init_success)
		DangersBuilder::GenerateDanger(&dangers, game_map.size());
#ifdef _DEBUG
	for(auto it = game_map.begin(); it != game_map.end(); ++it)
	{
		cout << it->Display() << '\n';
	}
#endif
	while (true)
	{
		int postion = lazy::random::randint(game_map.size());
		if(!dangers.getDanger(postion).IsDanger())
		{
			player_agent.setCurrentCavern(postion);			
			break;
		}
	}
	return init_success;
}

bool HuntGame::IsOver() const
{
	int current_cavern = player_agent.getCurrentCavern();
	Danger danger = dangers.getDanger(current_cavern);
	if(game_over || player_agent.IsExhaustArrow())
		return true;
	return false;
}

string HuntGame::PromptDanger() const
{
	stringstream ss;
	int current_cavern = player_agent.getCurrentCavern();
	ss << "you are in cavern#" << current_cavern << " now.\n";
	const Cavern& cavern = game_map[current_cavern];	
	string warnning;
	string prompt = ss.str() +  cavern.Display() + "\n";
	ss.str("");
	for(int i = 0; i < cavern.LinkedSize(); ++i)
	{
		Danger danger = dangers.getDanger(cavern[i]->getSerial());
		warnning = danger.Warn();
		if(warnning.length() > 0)
			ss << warnning << '\n';
	}
	warnning = ss.str();	
	return prompt + warnning;
}

void HuntGame::AgentAct(const CommandParser& _command)
{
	CommandParser::CommandType cmd = _command.getCommand();
	vector<int> param = _command.getParameters();
	shared_ptr<Command> act;
	act.reset(CommandFactory::Create(cmd));
	if(!act.get())
	{
		return;
	}
	bool is_executed = act->Execute(&player_agent, param, dangers);
	game_over = !player_agent.IsAlive() || is_executed; 
}
bool HuntGame::ValidParam(const CommandParser& _command) const
{
	CommandParser::CommandType cmd = _command.getCommand();
	vector<int> param = _command.getParameters();
	int cavern = player_agent.getCurrentCavern();
	Cavern _cavern = game_map[cavern];
	return _cavern.IsLinked(param[0]);
}

bool HuntGame::IsWin() const
{
	return player_agent.IsAlive();
}
