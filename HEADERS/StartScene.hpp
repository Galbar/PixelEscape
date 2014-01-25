#ifndef	STARTSCENE_HPP
#define STARTSCENE_HPP


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Scene.hpp"
#include "DisplayObject.hpp"

class StartScene: public Scene
{

public:

	StartScene();
    Scene(sf::RenderWindow* window);
    ~StartScene();

private:
	
	DisplayObject* m_gameTitle;
	DisplayObject* m_playButton;
	
};

#endif