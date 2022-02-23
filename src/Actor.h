#pragma once
#include "Player.h"

class Actor : public Player
{
public:
	Actor();

	//void update(Grid& grid);

	bool virtual handleInput();
	bool virtual update(Grid& grid);
	
};
