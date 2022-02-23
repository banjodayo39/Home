#pragma once
#include "Player.h"

class Zombie : public Player {

	Vector2i currNode;

public:
	Zombie();

	void setCurrNode(Vector2i _currNode);

	Vector2i getCurrNode();

	bool virtual handleInput();

	// update function
	bool virtual update(Grid& grid);
};
