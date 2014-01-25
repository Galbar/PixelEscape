#ifndef HUD_HPP
#define HUD_HPP

#include <vector>

#include <SFML/Graphics.hpp>


#include "DisplayObject.hpp"

class HUD
{
   public:

   	static HUD* sharedHUD();

	 	void draw();
	 	void update();
    void reset();

   protected:

     	HUD();
     

   private:

      static HUD* pHUDInstance;
      std::vector<DisplayObject*>  m_displayObjects;

      sf::Text scoreLabel;

};

#endif