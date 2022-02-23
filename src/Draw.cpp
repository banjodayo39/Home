#include "Engine.h"

void Engine::draw()
{
	// Rub out the last frame
	m_Window.clear(Color::Black);

	// Switch to m_MainView
	m_Window.setView(m_MainView);
	m_Window.draw(m_Actor.getSprite());
	m_Window.draw(borderBottom.getRect());
	m_Window.draw(borderLeft.getRect());
	m_Window.draw(borderTop.getRect());
	m_Window.draw(borderRight.getRect());
	m_Window.draw(m_Zombie1.getSprite());
	m_Window.draw(m_Zombie2.getSprite());
	m_Zombie2.getSprite();
	m_Window.draw(m_Zombie3.getSprite());

	m_Window.draw(house);
	for (auto it = obstanceCells.begin(); it != obstanceCells.end(); it++) {
		Vector2i  pos;
		int w, h;
		pos = *it;
		w = pos.x;
		h = pos.y;
		if(grid.node[w][h].bObstancle)
			m_Window.draw(grid.nodes[w][h].getRect());
	}
	//for (int i = 0; i < 144; i++) {
	//	if (grid.node[i].bObstancle) {
	//		m_Window.draw(grid.node[i].getRect());
	//	}
	//}

	// Show everything we have just drawn
	m_Window.display();
}
