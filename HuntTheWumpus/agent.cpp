#include "agent.h"

int Agent::getCurrentCavern() const
{
	return current_cavern_index;
}

void Agent::setCurrentCavern(int cavern)
{
	current_cavern_index = cavern;
}

void Agent::Move(int cavern)
{
	current_cavern_index = cavern;
}

bool Agent::Shot(int cavern)
{
	if(number_of_arrow <= 0)
		return false;
	--number_of_arrow;
	return true;
}

bool Agent::IsExhaustArrow() const
{
	return number_of_arrow <= 0;
}

bool Agent::IsAlive() const
{
	return alive;
}

void Agent::BeKilled()
{
	alive = false;
}


