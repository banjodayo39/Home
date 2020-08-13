#include "Player.h"

void Player::spawn(Vector2f startPosition) {
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;
	m_Sprite.setPosition(m_Position);
}

FloatRect Player::getPosition() {
	return m_Sprite.getGlobalBounds();
}

// A rectangle representing the position of different parts of the sprite

void Player::setNodePos(Vector2i _nodePos){
	nodePos.x  = _nodePos.x;
	nodePos.y = _nodePos.y;
}

Vector2i Player::getNodePos() {
	return nodePos;
}

//get the sprite
Sprite Player::getSprite() {
	return m_Sprite;
}

