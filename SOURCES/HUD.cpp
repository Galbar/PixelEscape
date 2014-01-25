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
}


void HUD::draw()
{
	for (int i = 0; i < m_displayObjects.size(); ++i)
	{
		m_displayObjects[i]->draw();
	}

	m_window->draw(m_levelLabel);	
}

void HUD::update()
{
	for (int i = 0; i < m_displayObjects.size(); ++i)
	{
		m_displayObjects[i]->update();
	}
}

void HUD::reset()
{

}
