#include "HUD.hpp"

HUD::HUD(sf::RenderWindow* window, int level)
{
	m_window = window;

	if (!m_font.loadFromFile("data/fonts/PressStart2P.ttf"))
	{
		std::cerr << "[HUD] Fuente no encontrada." << std::endl;
	}

	std::string levelLabelString("level:" + std::to_string(level));

	m_levelLabel.setFont(m_font);
	m_levelLabel.setString(levelLabelString);
	m_levelLabel.setCharacterSize(25);
	m_levelLabel.setPosition(10,10);
	m_levelLabel.setColor(sf::Color::Blue);


	m_endColorLabel.setFont(m_font);
	m_endColorLabel.setString("end color ");
	m_endColorLabel.setCharacterSize(25);
	m_endColorLabel.setPosition(200,10);
	m_endColorLabel.setColor(sf::Color::Black);	
}


void HUD::draw()
{
	
	m_window->draw(m_levelLabel);	
	m_window->draw(m_endColorLabel);	
	
}

void HUD::update()
{
	
}

void HUD::reset()
{

}
