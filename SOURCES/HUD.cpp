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
	sf::Font font;

	if (!font.loadFromFile("data/levels/PressStart2P.ttf"))
	{

	}

	scoreLabel = sf::text("hello", font);
	scoreLabel.setFont(font);
	scoreLabel.setCharacterSize(30);
	scoreLabel.setStyle(sf::Text::Regular);
	
}


void HUD::draw()
{
	for (int i = 0; i < m_displayObjects.size(); ++i)
	{
		m_displayObjects[i]->draw();
	}
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
