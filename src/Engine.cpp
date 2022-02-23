#include "Engine.h"


Engine::Engine()
{
	// Get the screen resolution and create an SFML window and View
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	
	backgroundStart.x = (resolution.x - 600) * 0.3f;
	backgroundStart.y = (resolution.y - 600 ) * 0.8f;

	std::cout << resolution.x << "," << resolution.y << std::endl;

	m_Window.create(VideoMode(resolution.x, resolution.y),
		"Home",
		Style::Close | Style::Resize);

	// Initialize the full screen view
	m_MainView.setSize(resolution);

	// Can this graphics card use shaders?
	if (!sf::Shader::isAvailable())
	{
		// Time to get a new PC
		m_Window.close();
	}
	m_houseTexture = TextureHolder::GetTexture(
		"graphics/house.gif");

	//m_player = TextureHolder::GetTexture("graphics/wall.jpg");
	m_wall = TextureHolder::GetTexture("graphics/block.png");
	m_wall_h = TextureHolder::GetTexture("graphics/block_h.png");
	m_background = TextureHolder::GetTexture("graphics/bng.jpg");
	house.setTexture(m_houseTexture);

	Texture* p_background = &m_background;
	// Associate the sprite with the texture
	m_Background.setPointCount(4);
	m_Background.setPoint(0, Vector2f(0, 0));
	m_Background.setPoint(1, Vector2f(600, 0));
	m_Background.setPoint(2, Vector2f(600, 600));
	m_Background.setPoint(3, Vector2f(0, 600));
	std::cout<<backgroundStart.x << ", " << backgroundStart.y <<std::endl;
	m_Background.setPosition((int)backgroundStart.x, (int)backgroundStart.y);

	Vector2f backBoard;
	backBoard = m_Background.getPosition();
	house.setPosition(Vector2f(backBoard.x + 10, backBoard.y + 10));
	Vector2f start = Vector2f(backBoard.x + 10, backBoard.y + 10);

	grid.setGrid(start, m_wall);

	//spawn the background
	createBlockBackground(backBoard, m_wall);

}

void Engine::run()
{
	// Timing 	
	Clock clock;

	while (m_Window.isOpen())
	{
		Time dt = clock.restart();
		// Update the total game time
		m_GameTimeTotal += dt;
		// Make a decimal fraction from the delta time
		float dtAsSeconds = dt.asSeconds();
		input();
		update(grid, dtAsSeconds);
		draw();
	}
}
