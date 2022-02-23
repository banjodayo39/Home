#include "Engine.h"


int AStart(Grid& grid) {
	Vector2i currNode;
	int heuristic = 0;
	int dim = 12;
	try {
		// check for heuristic value not null
		if (heuristic == NULL) {
			cout << "Access granted - you are old enough.";
		}
		else {
			throw 505;
		}
	}
	catch (int myNum) {
		cout << "Access denied - Please put an heuristic value \n";
	}

    // change direction
	vector<Vector2i> delta = {{-1, 0}, {0, -1}, {1, 0}, {0, 1} };

	// open list of element 
	vector<vector<int> > closed(dim);
	vector<vector<int> > action(dim);

	for (int i = 0; i < dim; i++) {
		// declare  the i-th row to size of column 
		for (int j = 0; j < dim; j++) {
			closed[i][j] = 0;
			action[i][j] = 0;
		}
	}

	closed[12][0] = 1;

	

	return 0;
}
