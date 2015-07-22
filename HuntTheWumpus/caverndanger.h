#ifndef _CAVERN_DANGER_H__
#define _CAVERN_DANGER_H__
#include <map>
#include "danger.h"

class CavernDanger
{
public:
	CavernDanger();
	~CavernDanger();
	Danger getDanger(int cavern_serial) const;
	void setDanger(int _cavern_serial,  Danger _danger);
	bool IsClear() const;
private:
	std::map<int, Danger> cavern_danger;
};


#endif // !_CAVERN_DANGER_H__
