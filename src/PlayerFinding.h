#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class PlayerFinding {
private:
	struct sNode
	{
		bool bObstancle = false; // is this node an obstruction
		bool bVisited = false;  // have we search this node before
		float gCost;           // distance from starting node
		float hCost;           // distance to ending node 
		int x;				// horizontal distance measure
		int y;				// vertical distance measure
		  // connection to neighbour
		vector<sNode*> vNeighour; //connection to neighbour
		sNode* parent;      //Node connection to the node that offers shortest distance 
	};

	sNode* node = nullptr;
	int nMapWidth = 16;
	int nMapHeight = 16;

public:
	void spawn();
	bool onPlayerUpdate();
};
