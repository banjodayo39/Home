#include "Actor.h"
#include "TextureHolder.h"
#include <windows.h>
#include <iostream>


Actor::Actor() {
	 m_Sprite = Sprite(TextureHolder::GetTexture(
		 "graphics/boy.png"));
}

bool Actor::handleInput() {
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		m_UpPressed = true;
	}
	else {
		m_UpPressed = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		m_downPressed = true;
	}
	else {
		m_downPressed = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		m_LeftPressed = true;
	}
	else {
		m_LeftPressed = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		m_RightPressed = true;
	}
	else {
		m_RightPressed = false;
	}

	return false;
}

bool validNode(Grid grid, Vector2i nodePos) {
	if (nodePos.x >= 0 && nodePos.x < 12 && nodePos.y >= 0 && nodePos.y < 12) {
		if (!grid.nodes[nodePos.x][nodePos.y].bObstancle) {
			return true;
			cout << "obstancle" << endl;
		}
		else {
			cout << " not obstancle" << endl;
		}
	}
	return false;
}


bool Actor::update(Grid& grid) {
	bool isGoal = false;
	if (m_LeftPressed) {
		Vector2i tmpNodePos;
		if (nodePos.x >= 0 && nodePos.x < 12 && nodePos.y >= 0 && nodePos.y < 12) {
			tmpNodePos.x = nodePos.x;
			tmpNodePos.y = nodePos.y - 1;
			if (validNode(grid, tmpNodePos)) {
				setNodePos(tmpNodePos);
				//Sleep(500);
				this_thread::sleep_for(0.5s);
			}
			else {
				nodePos = nodePos;
				Sleep(500);
			}
		}
		
	}
	if (m_RightPressed) {
		Vector2i tmpNodePos;
		if (nodePos.x >= 0 && nodePos.x < 12 && nodePos.y >= 0 && nodePos.y < 12) {
			tmpNodePos.x = nodePos.x;
			tmpNodePos.y = nodePos.y + 1;
			if (validNode(grid, tmpNodePos)) {
				setNodePos(tmpNodePos);
				Sleep(500);
			}
			else {
				nodePos = nodePos;
				//	m_Sprite.setPosition(Vector2f(grid.node[nodePos].getPosition().left,
					//	grid.node[nodePos].getPosition().top));
			}
		}
	}
	if (m_UpPressed) {
		if (nodePos.x >= 0 && nodePos.x < 12 && nodePos.y >= 0 && nodePos.y < 12) {
			Vector2i tmpNodePos;
			tmpNodePos.x = nodePos.x - 1;
			tmpNodePos.y = nodePos.y;
			if (validNode(grid, tmpNodePos)) {
				setNodePos(tmpNodePos);
				Sleep(500);
			}
			else {
				nodePos = nodePos;
				Sleep(500);
				//	m_Sprite.setPosition(Vector2f(grid.node[nodePos].getPosition().left,
					//	grid.node[nodePos].getPosition().top));
			}
		}
	}
	if (m_downPressed) {
		if (nodePos.x >= 0 && nodePos.x < 12 && nodePos.y >= 0 && nodePos.y < 12) {
			Vector2i tmpNodePos;
			tmpNodePos.x = nodePos.x + 1;
			tmpNodePos.y = nodePos.y;
			if (validNode(grid, tmpNodePos)) {
				setNodePos(tmpNodePos);
				Sleep(500);
			}

			else {
				nodePos = nodePos;
				Sleep(500);
			}
		}
	}
	FloatRect playerStart = grid.nodes[nodePos.x][nodePos.y].getPosition();
	m_Sprite.setPosition(Vector2f(playerStart.left, playerStart.top));

	return isGoal;
};
