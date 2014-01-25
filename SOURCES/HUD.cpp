#include "HUD.hpp"

HUD* HUD::pHUDInstance = NULL;

HUD* HUD::sharedHUD()
{
  if (pHUDInstance == NULL)  
  {

    pHUDInstance = new HUD(); 

  }

  return pHUDInstance; 
}

HUD::HUD()
{

	m_window = Game::s_window;

	if (!m_font.loadFromFile("data/fonts/PressStart2P.ttf"))
	{
		std::cerr << "[HUD] Fuente no encontrada." << std::endl;
	}

	m_levelLabel.setFont(m_font);
	m_levelLabel.setString("level 1");
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
