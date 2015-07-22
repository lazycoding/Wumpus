#include "Room.h"
#include "Sprite.h"
#include <algorithm>
#include <sstream>
#include <iostream>

template<typename T>
std::string ToString(T& val)
{
	std::stringstream ss;
	ss << val;
	return ss.str();
}

inline void LogString(std::string log)
{
#ifdef _DEBUG
	std::cout << ">" << log << std::endl;
#endif
}


Room::Room(void):id(0), sprite(nullptr)
{
}


Room::~Room(void)
{
}

int Room::ConnectTo( Room& r )
{
	if ( id == r.id )
	{
		LogString("roomself!");
		return self;
	}

	if( connect_rooms.size() == MAX_CONNECT_ROOM )
	{
		LogString("linked rooms are full!");
		return full;
	}

	if (r.connect_rooms.size() == MAX_CONNECT_ROOM)
	{
		LogString("room connect to is full!");
		return goon;
	}

	if ( Connected(r) )
	{
		LogString("had been linked!");
		return connected;
	}

	connect_rooms.push_back(&r);
	r.connect_rooms.push_back(this);
	return succeeded;
}

bool Room::Connected( const Room& r )
{
	return std::find(connect_rooms.begin(), connect_rooms.end(), &r) != connect_rooms.end() ? true : false;
}

bool Room::SpriteEnter( Sprite* spriteObject )
{
	if(sprite)
		return false;
	sprite = spriteObject;
	return true;
}

std::string Room::ShowConnectRoomId()
{
	std::string roomstring;
	for(auto it = connect_rooms.begin(); it != connect_rooms.end(); it++)
	{
		roomstring += ToString( (*it)->id );
		roomstring += ",";
	}
	roomstring.erase(roomstring.length() - 1, 1);

	return roomstring;
}

std::string Room::OnWarn()
{
	std::string out;
	for (auto it = connect_rooms.begin(); it != connect_rooms.end(); it++)
	{
		if((*it)->sprite)
		{
			out += "Room(";
			out += ToString((*it)->id);
			out += ") Warn:";
			out += (*it)->sprite->Warnning();
			out += "\r\n";
		}
	}
	return out;
}

bool Room::SpriteLeave()
{
	sprite = nullptr;
	return true;
}

