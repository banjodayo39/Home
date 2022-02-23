#include "Block.h"
#include <iostream>
#include "TextureHolder.h"

Block::Block() {
}

 void Block::spawn(Vector2f position, Vector2f size) {
	 m_Position.x = position.x;
	 m_Position.y = position.y;
	 m_Size.x = size.x;
	 m_Size.y = size.y;

	 
	 rect.setFillColor(Color(85, 105, 47));
 	 rect.setPosition(Vector2f(position.x, position.y));
	 rect.setSize(Vector2f(m_Size.x, m_Size.y));
 }


 FloatRect Block::getPosition() {
	 return rect.getGlobalBounds();
 }
 
 Vector2f Block::getSize() {
	 return m_Size;
 }

 RectangleShape Block::getRect() {
	 return rect;
 };

