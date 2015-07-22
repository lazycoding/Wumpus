#pragma once
#include "Sprite.h"
class Hunter : public Sprite
{
public:
	Hunter(void);
	~Hunter(void);
	void Move( int roomId );
	bool Shoot();
	bool Alive() const { return alive;}
	void Initialize(int roomId);
	int AtRoom() const { return room_id; }
	void Dead();

	virtual std::string Warnning();

private:
	int arrow_count;
	int room_id;
	bool alive;
};

