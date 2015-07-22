#include "Wumpus.h"


Wumpus::Wumpus(void):room_id(0), alive(true)
{
}


Wumpus::~Wumpus(void)
{
}

bool Wumpus::Alive() const
{
	return alive;
}

void Wumpus::Move()
{

}

void Wumpus::Initialize( int roomId )
{
	room_id = roomId;
	alive = true;
}

std::string Wumpus::Warnning()
{
	return "Wumpus wumpus!";
}
