#pragma once
#include "command.h"
class AgentShot :
	public Command
{
public:
	AgentShot(void);
	~AgentShot(void);
	virtual bool Execute(Agent*, const std::vector<int>& params, const CavernDanger& _dangers);
};

