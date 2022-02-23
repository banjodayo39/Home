#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <thread>
#include "Node.h"
#include "Constants.h"

using namespace sf;
using namespace std::literals::chrono_literals;

class Grid {

public:
	Grid();
	//Node* node = nullptr;
	vector<vector<Node>> nodes;
	void setGrid(Vector2f startPosition, Texture& wall);

};
