#pragma once
#include "Grid.h"

using namespace sf;

using namespace std;

class Player {
	
protected:

	Sprite m_Sprite;

	//the player's position
	Vector2f m_Position;

	Vector2i nodePos;

	// associate a texture with the sprite
	Texture m_texture;

	FloatRect m_GlobalPosition;

	//which direction is the player moving to 


private:

	// Where are the characters various body parts?
	FloatRect m_Bottom;
	FloatRect m_Top;
	FloatRect m_Right;
	FloatRect m_Left;


public: 

	bool m_LeftPressed;
	bool m_RightPressed;
	bool m_UpPressed;
	bool m_downPressed;

	void spawn(Vector2f startPosition);

	// get player position

	FloatRect getPosition();

	// A rectangle representing the position of different parts of the sprite

	void setNodePos(Vector2i _nodePos);

	Vector2i getNodePos();

	//get the sprite
	Sprite getSprite();

	bool virtual handleInput() = 0;

	bool virtual update(Grid& grid) = 0;
};