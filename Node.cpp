#include "Node.h"
#include "TextureHolder.h"
using namespace sf;

void Node::spawn(Vector2f position) {
	m_Position.x = position.x;
	m_Position.y = position.y;
	m_Size = Vector2f(50, 50);
	rect.setSize(Vector2f(m_Size.x, m_Size.y));
	rect.setPosition(Vector2f(m_Position.x, m_Position.y));
}

bool Node::onPlayerUpdate() {

	return true;
}

FloatRect Node::getPosition() {
	return rect.getGlobalBounds();
}

Vector2f Node::getSize() {
	return m_Size;
}

RectangleShape Node::getRect() {
	return rect;
};