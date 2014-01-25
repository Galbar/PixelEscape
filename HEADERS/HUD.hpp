#ifndef HUD_HPP
#define HUD_HPP

#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "DisplayObject.hpp"
#include "Game.hpp"

class HUD
{
   public:

   	static HUD* sharedHUD();

	 	void draw();
	 	void update();
    void reset();

   protected:

     	HUD();

      HUD(const HUD & ) ;
      HUD &operator= (const HUD & ) ;
     

   private:

      static HUD* pHUDInstance;

      sf::RenderWindow* m_window;

      std::vector<DisplayObject*>  m_displayObjects;
      
      sf::Text m_levelLabel;
      sf::Font m_font;
};

#endif