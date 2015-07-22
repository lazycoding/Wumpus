#include "danger.h"
#include "agent.h"
#include "lazy_random_helper.h"
using namespace std;

bool Danger::IsDanger() const
{
	return danger_type != None; 
}

string Danger::Warn() const
{
	string warning;
	if(danger_type == Wumpus)
	{
		warning= "wumpus is nearest!";
	}
	if(danger_type == Trap)
	{
		warning = "a slight breeze!";
	}
	if(danger_type == Bat)
	{
		warning = "an obnoxious smell!" ;
	}
	return warning;
}

bool Danger::Raise(Agent* _agent)
{
	if(danger_type == Wumpus)
	{
		_agent->BeKilled();
	}
	if(danger_type == Trap)
	{
		_agent->BeKilled();
	}
	if(danger_type == Bat)
	{
		int new_cavern = lazy::random::randint(20);
		_agent->setCurrentCavern(new_cavern);
		return true;
	}
	return false;
}

bool Danger::ClearDanger()
{
	if(danger_type == Wumpus)
	{
		danger_type = None;
		return true;
	}
	return false;
}
