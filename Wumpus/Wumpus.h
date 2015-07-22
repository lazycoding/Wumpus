#pragma once
#include "Sprite.h"

class Wumpus : public Sprite
{
public:
	Wumpus(void);
	~Wumpus(void);
	bool Alive() const;
	void Move();
	int AtRoom() const { return room_id; }
	void Dead() { alive = false;}
	void Initialize(int roomId);

	virtual std::string Warnning();

private:
	int room_id;
	bool alive;
};

