#ifndef HUD_HPP
#define HUD_HPP

#include <vector>
#include <string>
#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "DisplayObject.hpp"

class HUD
{
   public:

   	HUD(sf::RenderWindow* window, int level);

	 	void draw();
	 	void update();
    void reset();

   private:

      static HUD* pHUDInstance;

      sf::RenderWindow* m_window;

      std::vector<DisplayObject*>  m_displayObjects;
      
      sf::Text m_levelLabel;
      sf::Font m_font;
};

#endif