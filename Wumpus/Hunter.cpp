#include "Hunter.h"


Hunter::Hunter(void):arrow_count(5),room_id(0), alive(true)
{
}


Hunter::~Hunter(void)
{
}

void Hunter::Move( int roomId )
{
	room_id = roomId;
}

bool Hunter::Shoot()
{
	if (arrow_count > 0)
	{
		--arrow_count;
		return true;
	}
	return false;
}

void Hunter::Initialize(int roomId)
{
	this->room_id = roomId;
	this->alive = true;
}

void Hunter::Dead()
{
	alive = false;
}

std::string Hunter::Warnning()
{
	return "";
}
