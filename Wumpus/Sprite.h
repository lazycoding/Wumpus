#pragma once

#include <iostream>

class Sprite
{
public:
	Sprite(void);
	~Sprite(void);

	virtual std::string Warnning() = 0;
};

