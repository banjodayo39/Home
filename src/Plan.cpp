#include "Plan.h"

Plan::Plan(Grid& grid, Vector2i goal, int cost) {


}

void Plan::makeHeuristic(Grid& grid, Vector2i goal, int cost) {
	m_Heuristic = vector<vector<int>>(ROW);
	for (int w = 0; w < ROW; w++) {
		m_Heuristic[w] = vector<int>(COLUMN);
		for (int h = 0; h < COLUMN; h++) {
			m_Heuristic[w][h] = abs(w - goal.x) + abs(h - goal.y);
		}
	}
}

bool Plan::aStar() {
	vector<Vector2i> delta = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

	// open llist of type [f, g, h, x, y]

	vector<vector<int>> closed = vector<vector<int>>(ROW);

	closed[m_Pos.x][m_Pos.y] = 1;

	vector<vector<int>> action = vector<vector<int>>(ROW);
	int x = m_Pos.x;
	int y = m_Pos.y;
	int h = m_Heuristic[x][y];
	int g = 0;
	int f = g + h;

	vector<vector<int>>  open = { {f, g, h, x, y } };
	bool found = false;
	bool resign = false;
	int count = 0;

	while (!found && !resign) {
		if (open.size() == 0) {
			resign = true;
			cout << "Search is terminated" << endl;
		}
		else {
			sort(open.begin(), open.end());
			reverse(open.begin(), open.end());
			auto next = open[0].pop_back();


		}
			

	}


}