#include "StartScene.hpp"

StartScene::StartScene(sf::RenderWindow* window) : Scene(window){

	if (!m_font.loadFromFile("data/fonts/PressStart2P.ttf"))
	{
		std::cerr << "[StartScene] Fuente no encontrada." << std::endl;
	}

	m_gameTitle.setFont(m_font);
	m_gameTitle.setString("play");
	m_gameTitle.setCharacterSize(90);
	m_gameTitle.setPosition(250,470);
	m_gameTitle.setColor(sf::Color::Black);

	sf::RectangleShape rectangle;

	for (int i = 0; i < 16; ++i)
	{

		rectangle.setSize(sf::Vector2f(43, 688));
		
		if(i%3 == 0 ){
			rectangle.setFillColor(sf::Color::Red);
		}else if(i%3==1){
			rectangle.setFillColor(sf::Color::Green);
		}else{
			rectangle.setFillColor(sf::Color::Blue);
		}
		
		rectangle.setPosition(i * 43, 0);

		m_rectangles.push_back(rectangle);
	}
	
}

void StartScene::draw()
{
	for (int i = 0; i < m_rectangles.size(); ++i)
	{
		m_window->draw(m_rectangles[i]);
	}
	
	m_window ->draw(m_gameTitle);
	

	Scene::draw();

	
}

void StartScene::update()
{
	
}

