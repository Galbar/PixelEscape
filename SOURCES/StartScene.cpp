#include "StartScene.hpp"

StartScene::StartScene(sf::RenderWindow* window) : Scene(window){

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
	
	m_title_py = -200;

	m_title_texture.loadFromFile("data/textures/title.png");
	m_title_sprite.setTexture(m_title_texture);
	m_title_sprite.setPosition(50, m_title_py);	


	m_playButtonTexture.loadFromFile("data/textures/play.png");
	m_playButtonSprite.setTexture(m_playButtonTexture);
	m_playButtonSprite.setPosition(370, 570);	

	m_playButtonRect = m_playButtonSprite.getGlobalBounds ();
	


	m_t = std::clock();

}

StartScene::~StartScene()
{
	
}

void StartScene::draw()
{
	for (int i = 0; i < m_rectangles.size(); ++i)
	{
		m_window->draw(m_rectangles[i]);
	}

	if(m_title_py< 105)
		m_title_py+=1.5;

	m_title_sprite.setPosition(50, (int) m_title_py);
	
	m_window->draw(m_title_sprite);

	std::clock_t t=  std::clock();
	t = t - m_t;
	
	if((float)t>150000){
		m_window->draw(m_playButtonSprite);
	}
		
	Scene::draw();
}

void StartScene::update()
{
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		
		sf::Vector2i mousePos = sf::Mouse::getPosition(*m_window);

		if(m_playButtonRect.contains(mousePos.x, mousePos.y)){
			//startGame();
			std::cerr << "[StartScene] Start Game" << std::endl;
		}
	}
}

