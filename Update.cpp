#include "Engine.h"
#include <SFML/Graphics.hpp>

using namespace sf;



auto f2 = [](Player& player, Grid& grid) {
	player.update(grid);
};

auto f = [](Player& player, Grid& grid) {
	player.update(grid);
};

void Engine::update(Grid grid, float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		m_Playing = false;
		m_Actor.setNodePos(Vector2i(11, 2));
		//m_Zombie1.setNodePos(122);

		FloatRect playerStart =  grid.node[m_Actor.getNodePos().x][m_Actor.getNodePos().y].getPosition();
		FloatRect zombieStart = grid.node[11][0].getPosition();

	    m_Actor.spawn(Vector2f(playerStart.left, playerStart.top));
		m_Zombie1.spawn(Vector2f(zombieStart.left, zombieStart.top));
		/*m_Zombie2.spawn(Vector2f(bngStart.x + 410, bngStart.y + 400), GRAVITY);
		m_Zombie3.spawn(Vector2f(bngStart.x + 110, bngStart.y + 100), GRAVITY);*/

		m_NewLevelRequired = false;
		// Make sure spawn is called only once
		m_TimeRemaining = 10;
		m_Playing = true;
	}

	if (m_Playing)
	{
		std::thread t2(f2, std::ref(m_Zombie1), std::ref(grid));
		std::thread t(f, std::ref(m_Actor), std::ref(grid) );
		
		//which direction is the player moving to 
	
		t.join();
		t2.join();
		
		//m_Actor.update(grid);
		
		//FloatRect playerStart = grid.node[m_Actor.getNodePos()].getPosition();
		//m_Actor.spawn(Vector2f(playerStart.left, playerStart.top));
		// Count down the time the player has left
	    m_TimeRemaining -= dtAsSeconds;

		// Have Thomas and Bob run out of time?
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = false;
		}
	}// End if playing

}