#include "Engine.h"

void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{

			// Handle the player quitting 
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				try {
					m_Window.close();
				}
				catch (exception& e) {
					cout << "Exception Caught"<<e.what()<<endl;
				}
				
			}

			// Handle the player starting the game
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				m_Playing = true;
			}
		}
	}

	if (m_Actor.handleInput()) {
		m_Actor.m_downPressed = false;
		m_Actor.m_LeftPressed = false;
		m_Actor.m_RightPressed = false;
		m_Actor.m_UpPressed = false;
	}
}