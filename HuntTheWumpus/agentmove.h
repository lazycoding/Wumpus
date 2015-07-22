#pragma once
#include "command.h"
class AgentMove :
	public Command
{
public:
	AgentMove(void);
	~AgentMove(void);
	virtual bool Execute(Agent*, const std::vector<int>& params, const CavernDanger& _dangers);
};

