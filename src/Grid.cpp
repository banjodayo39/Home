#include "Grid.h"

Grid::Grid() { 
	//node = new Node[ROW * COLUMN];
	nodes = vector<vector<Node>>(ROW);
}

//vector<int> obstanceCells{ 9, 10, 19, 24, 25, 27, 28, 29, 30, 31, 32, 34,36, 37, 39, 40, 41, 
//    43, 46, 47, 53, 60, 61, 62, 63, 65, 67, 68, 69,
//    72, 74, 77, 81, 82, 84, 86, 88, 89, 91, 92, 93, 96, 103, 108, 109, 111, 112, 113, 
//114, 115, 117, 118, 119, 120, 121, 135, 136, 137, 138, 139, 140, 142, 143};

vector<Vector2i> obstanceCells = { {0, 9}, { 0, 10}, {1, 7}, {2, 0}, {2, 1} , {2, 3}, {2, 4},
{2, 5}, {2, 6}, {2, 7}, {2, 8}, {2, 10}, {3, 0}, {3, 1}, {3, 3}, {3, 4}, {3, 5}, {3, 7}, {3, 10}, {3, 11},
	{4, 5}, {5, 0}, {5, 1}, {5, 2}, {5, 3}, {5, 5}, {5, 7}, {5, 8}, {5, 9}, {6, 0}, {6, 2}, {6, 5},
	{6, 9}, {6, 10}, {7, 0},  {7, 2}, {7, 4}, {7, 5}, {7, 7} ,{ 7, 8}, {7, 9}, {8, 0}, {8, 7},
	{9, 0}, {9, 1}, {9, 3}, {9, 4}, {9, 5}, {9, 6}, {9, 7}, {9, 9}, {9, 10}, {9, 11},
	{10, 0}, {10, 1}, {11, 3}, {11, 4}, {11, 5}, {11, 6}, {11, 7}, {11, 10}, {11, 11}
};

void Grid::setGrid(Vector2f startPosition, Texture& wall) {

	for (int w = 0; w < ROW; w++) {
		nodes[w] = vector<Node>(COLUMN);
		for (int h = 0; h < COLUMN; h++) {
			int pos = h + w * COLUMN;
			nodes[w][h].spawn(Vector2f(startPosition.x + h * WIDTH, startPosition.y + w * HEIGHT));
			nodes[w][h].parent = nullptr;
			nodes[w][h].bObstancle = false;
			nodes[w][h].bVisited = false;
			//node[pos].spawn(Vector2f(startPosition.x + h * WIDTH, startPosition.y + w * HEIGHT));
			//node[pos].parent = nullptr;
			//node[pos].bObstancle = false;
			//node[pos].bVisited = false;
		}
	}

	for (auto it = obstanceCells.begin(); it != obstanceCells.end(); it++) {
		Vector2i  pos;
		int w, h;
		pos = *it;
		w = pos.x;
		h = pos.y;
		nodes[w][h].bObstancle = true;
		nodes[w][h].rect.setTexture(&wall);
	}

	//for (auto it = obstanceCells.begin(); it != obstanceCells.end(); it++) {
	//	
	//	node[*it].bObstancle = true;
	//	node[*it].rect.setTexture(&wall);
	//}
}
