#ifndef HUD_HPP
#define HUD_HPP

#include <vector>
#include <string>
#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class HUD
{
   public:

   	HUD (sf::RenderWindow* window, int level);

	 	void draw();
	 	void update();
      void reset();

   private:

      sf::RenderWindow* m_window;

      sf::Text m_levelLabel;
      sf::Text m_endColorLabel;
      
      sf::Font m_font;
};

#endif