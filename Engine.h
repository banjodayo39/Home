#pragma once
#include "TextureHolder.h"
#include "Block.h"
#include "Zombie.h"
#include "Engine.h"
#include <map>
#include "Actor.h"
#include <thread>

using namespace sf;

class Engine {

private:

	//The texture holder
	TextureHolder th;

	//Characters of the game
	Zombie m_Zombie1;
	Zombie m_Zombie2;
	Zombie m_Zombie3;
	
	//Render Window
	RenderWindow m_Window;

	//The main view
	View m_MainView;

	
	//Declare spirite and texture for the background
	ConvexShape m_Background;

	//initilaize the grid
	Grid grid;

	//initilaize player 
	Actor m_Actor;

	// Is the game currently playing?
	bool m_Playing = false;

	bool m_IsZombieActive = false;
	// Is character 1 or 2 the current focus?

	// The force pushing the characters down
	const int GRAVITY = 300;

	// How much time is left in the current level
	float m_TimeRemaining;
	Time m_GameTimeTotal;

	// Is it time for a new/first level?
	bool m_NewLevelRequired = true;

	int m_LeftPlayerGap;
	int m_TopPlayerGap;

	//initialize the grid

	// the texture for the house
	Texture m_houseTexture;
	Texture m_Zombie;
	Texture m_wall;
	Texture m_wall_h;
	Texture m_background;

	Block borderLeft;
	Block borderRight;
	Block borderBottom;
	Block borderTop;
     
	// create a map for collision
	std::map<int, sf::FloatRect> collisionMap;

	//sprite for house
	Sprite house;

	// where player is heading to
	bool m_IsBeforeBlock;
	bool m_IsAboveBlock; 

	// Private functions for internal use only
	void input();
	void update(Grid grid, float dAtseconds);
	void draw();

	// handling threading 
	const int num_of_threads = 1;
	std::vector<std::thread> threads;

	//defining the goal 
	Node* startNode = nullptr; 
	Node* endNode = nullptr; // player's target node
	Node* targetNode = nullptr; //zombie target node

public:
	Vector2f backgroundStart;
	//The engine constructor

	vector<Vector2i> obstanceCells = { {0, 9}, { 0, 10}, {1, 7}, {2, 0}, {2, 1} , {2, 2}, {2, 3}, {2, 4},
	{2, 5}, {2, 6}, {2, 7}, {2, 8}, {2, 10}, {3, 0}, {3, 1}, {3, 3}, {3, 4}, {3, 5}, {3, 7}, {3, 10}, {3, 11},
		{4, 5}, {5, 0}, {5, 1}, {5, 2}, {5, 3}, {5, 5}, {5, 7}, {5, 8}, {5, 9}, {6, 0}, {6, 2}, {6, 5},
		{6, 9}, {6, 10}, {7, 0},  {7, 2}, {7, 4}, {7, 5}, {7, 7} ,{ 7, 8}, {7, 9}, {8, 0}, {8, 7},
		{9, 0}, {9, 1}, {9, 3}, {9, 4}, {9, 5}, {9, 6}, {9, 7}, {9, 9}, {9, 10}, {9, 11},
		{10, 0}, {10, 2}, {11, 3}, {11, 4}, {11, 5}, {11, 6}, {11, 10}, {11, 11}
	};


	Engine();

	//Run calls all the private constructor
	void createBlockBackground(Vector2f backBoard, Texture &wallBackground);
	void run();
};
