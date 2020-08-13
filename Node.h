 #pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextureHolder.h"

using namespace std;
using namespace sf;


struct Node
{
	bool bObstancle = false; // is this node an obstruction
	bool bVisited = false;  // have we search this node before
	float gCost;           // distance from starting node
	float hCost;           // distance to ending node 
	  // connection to neighbour
	vector<Node*> vNeighour; //connection to neighbour
	Node* parent;      //Node connection to the node that offers shortest distance 
	RectangleShape rect;

	void spawn(Vector2f position);
	// get the position and dimens of the block

	bool onPlayerUpdate();
	FloatRect getPosition();
	Vector2f getSize();
	Vector2f m_Position;
	//void setNodeBackground(Texture &wall);

	//get the rect 
	RectangleShape getRect();

protected:


	Vector2f m_Size;
	Texture m_wall;
};