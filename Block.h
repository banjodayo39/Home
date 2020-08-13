#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Block {

protected:
	RectangleShape rect;
	Vector2f m_Position;
	Vector2f m_Size;

public: 
	Block();

	// spawn the block
	void spawn(Vector2f position, Vector2f size);

	// get the position and dimens of the block
	FloatRect getPosition();
	Vector2f getSize();
	
	//get the rect 
	RectangleShape getRect();
};

