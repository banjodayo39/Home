#include "Engine.h"

struct Plan {
private: 
	int m_Cost;
	Vector2i m_Goal;
	Plan* plan;
	Vector2i m_Pos;
	Grid m_Grid;
	vector<vector<int>> m_Heuristic;
	vector<Vector2i> m_Path;
	vector<Vector2i> s_Path;

public:
	Plan(Grid& grid, Vector2i goal, int cost);
	void makeHeuristic(Grid& grid, Vector2i goal, int cost);
	bool aStar();
};