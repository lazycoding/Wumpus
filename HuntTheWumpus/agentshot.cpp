#include "agentshot.h"
#include "agent.h"
#include "caverndanger.h"
using std::vector;

AgentShot::AgentShot(void)
{
}


AgentShot::~AgentShot(void)
{
}

bool AgentShot::Execute(Agent* agent, const vector<int>& params, const CavernDanger& dangers)
{
	for(vector<int>::size_type i = 0; i < params.size(); i++)
	{
		agent->Shot(params[i]);
		Danger d = dangers.getDanger(params[i]);
		if(d.ClearDanger())
		{
			return true;
		}
	}
	return false;
}
