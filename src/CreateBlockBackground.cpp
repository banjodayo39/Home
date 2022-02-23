#include "Engine.h"

void Engine::createBlockBackground(Vector2f backBoard, Texture &m_wall) {

	std::string type = "block";
	int count = 0;
	//for (auto it = obstanceCells.begin(); it != obstanceCells.end(); it++) {
	//	collisionMap.insert(std::pair<int, sf::FloatRect>(count, grid.node[*it].getPosition()));
	//	count += 1;
	//	std::cout << "Coll" << endl;
	//}
	borderBottom.spawn(Vector2f(backBoard.x, backBoard.y + 610), Vector2f(620, 10));
	count += 1;
	collisionMap.insert(std::pair<int, sf::FloatRect>(count, borderBottom.getPosition()));
	borderTop.spawn(Vector2f(backBoard.x, backBoard.y), Vector2f(610, 10));
	count += 1;
	collisionMap.insert(std::pair<int, sf::FloatRect>(count, borderTop.getPosition()));
	borderLeft.spawn(Vector2f(backBoard.x, backBoard.y), Vector2f(10, 610));
	count += 1;
	collisionMap.insert(std::pair<int, sf::FloatRect>(count, borderLeft.getPosition()));
	borderRight.spawn(Vector2f(backBoard.x + 610, backBoard.y), Vector2f(10, 610));
	count += 1;
	collisionMap.insert(std::pair<int, sf::FloatRect>(count, borderRight.getPosition()));
	Vector2f position = Vector2f(50, 50);

}
