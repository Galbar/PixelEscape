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

}


void HUD::draw()
{
	for (int i = 0; i < m_displayObjects.size(); ++i)
	{
		m_displayObjects[i].draw();
	}
}

void HUD:update()
{
	for (int i = 0; i < m_displayObjects.size(); ++i)
	{
		m_displayObjects[i].update();
	}
}

void HUD::reset()
{

}
