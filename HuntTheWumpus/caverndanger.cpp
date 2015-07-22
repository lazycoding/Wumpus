#include "caverndanger.h"
#include <algorithm>
using namespace std;

CavernDanger::CavernDanger()	
{
}

CavernDanger::~CavernDanger()
{
}

Danger CavernDanger::getDanger(int cavern_serial) const
{
	auto findit = cavern_danger.find(cavern_serial);	
	if(findit != cavern_danger.end())
	{
		return findit->second;
	}
	return Danger();
}

void CavernDanger::setDanger(int _cavern, Danger _danger)
{
	cavern_danger.insert(make_pair(_cavern, _danger));
}

bool CavernDanger::IsClear() const
{
	for(auto it = cavern_danger.begin(); it!=cavern_danger.end(); ++it)
	{
		if(it->second.IsDanger())
			return false;
	}
	return true;
}
