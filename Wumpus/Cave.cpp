#include "Cave.h"
#include <time.h>

Cave::Cave(void)
{
}


Cave::~Cave(void)
{
}

void Cave::ConstructRooms( int caveRoom )
{
	rooms.clear();
	rooms.resize(caveRoom);

	int n = 1;
	for (auto it = rooms.begin(); it != rooms.end(); it++, ++n)
	{
		it->RoomID(n);
	}

	srand((unsigned int)time(nullptr));
	for (auto it = rooms.begin(); it != rooms.end(); it++)
	{
		while(it->ConnectTo(rooms[rand() % caveRoom]) != Room::full)
		{
			;
		}
	}
}

bool Cave::Hit( int roomId )
{
	return true;
}


int Cave::RandRoom()
{
	srand((unsigned)time(nullptr));
	return rand() % (rooms.size() - 1);
}

Room& Cave::At( int roomId )
{
	return rooms.at(roomId);
}
