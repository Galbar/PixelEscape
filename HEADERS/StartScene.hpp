#ifndef	STARTSCENE_HPP
#define STARTSCENE_HPP

#include <string>
#include <iostream>

#include "Scene.hpp"


class StartScene: public Scene
{

public:

	StartScene();
    StartScene(sf::RenderWindow* window);
    ~StartScene();

    void draw();
    void update();

private:
 	sf::Font m_font;
	sf::Text m_gameTitle;
};

#endif