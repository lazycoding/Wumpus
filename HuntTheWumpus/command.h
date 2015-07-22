#pragma once
#include <vector>
class Agent;
class CavernDanger;
class Command
{
public:
	virtual bool Execute(Agent*, const std::vector<int>&, const CavernDanger&) = 0;
};

