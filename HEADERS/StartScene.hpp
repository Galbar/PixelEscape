#ifndef	STARTSCENE_HPP
#define STARTSCENE_HPP

#include <string>
#include <iostream>
#include <vector>

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

	//sf::Text m_gameTitle_2;	

	std::vector<sf::RectangleShape> m_rectangles;

	//sf::Sprite m_title_sprite;
	//sf::Texture m_title_texture;
};

#endif