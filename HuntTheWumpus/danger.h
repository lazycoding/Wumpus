#ifndef _DANGER_H__
#define _DANGER_H__
#include <string>
class Agent;
class Danger
{
public:
	enum DangerType{ None = 0, Bat = 1, Trap = 2, Wumpus = 3};
	Danger(DangerType _danger_type = None) : danger_type(_danger_type){}
	bool IsDanger() const;
	std::string Warn() const;
	bool Raise(Agent* _agent);
	bool ClearDanger();

private:
	DangerType danger_type;
};


#endif // !_DANGER_H__
