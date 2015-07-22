#include "agentmove.h"
#include "agent.h"
#include "caverndanger.h"

AgentMove::AgentMove(void)
{
}


AgentMove::~AgentMove(void)
{
}

bool AgentMove::Execute(Agent* agent, const std::vector<int>& params, const CavernDanger& _dangers)
{
	if(params.size() != 1)
		return false;
	agent->Move(params[0]);
	Danger d = _dangers.getDanger(params[0]);
	d.Raise(agent);
	return true;
}
