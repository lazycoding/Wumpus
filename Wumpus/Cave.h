#pragma once

#include "Room.h"
#include <vector>

class Cave
{
public:
	Cave(void);
	~Cave(void);
	void ConstructRooms( int caveRoom );
	bool Hit( int roomId );
	Room& At(int roomId);
	int RandRoom();// [0,rooms.size() -1]

private:
	std::vector<Room> rooms;
};

