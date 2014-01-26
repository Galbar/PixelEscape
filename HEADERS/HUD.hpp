#ifndef HUD_HPP
#define HUD_HPP

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class HUD
{
   public:

   	HUD (sf::RenderWindow* window, int level);
      ~HUD();

	 	void draw();
	 	void update();
      void reset();

      void pause();
      void resume();

   private:

      sf::RenderWindow* m_window;

      sf::Text m_levelLabel;
      sf::Text m_PauseLabel;
      sf::Sprite m_PauseSprite;
      
      sf::Font m_font;

      bool isPaused;
};

#endif