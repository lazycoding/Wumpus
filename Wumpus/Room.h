#pragma once

#include <vector>
#include <string>

class Sprite;
class Room
{
public:
	Room(void);
	~Room(void);

	enum { MAX_CONNECT_ROOM = 3};
	enum error_room { succeeded = 0, self = 1, full, connected, goon };

	void RoomID(int id) { this->id = id; }
	inline int RoomID() const { return id; }

	int ConnectTo(Room& r);
	bool Connected( const Room& r );

	inline bool operator==(const Room& r) { return id == r.id; }
	inline bool operator!=(const Room& r) { return !(*this == r); }

	bool SpriteEnter(Sprite* spriteObject);
	bool SpriteLeave();
	std::string ShowConnectRoomId();
	std::string OnWarn();
private:
	int id;
	Sprite* sprite;
	std::vector<Room*> connect_rooms;
};

