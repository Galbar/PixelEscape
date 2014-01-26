#ifndef	STARTSCENE_HPP
#define STARTSCENE_HPP

#include <string>
#include <iostream>
#include <vector>
#include <time.h> 

#include "Scene.hpp"
#include "AudioPlayer.hpp"

class StartScene: public Scene
{

public:

	StartScene();
    StartScene(sf::RenderWindow* window);
    ~StartScene();

    void draw();
    void update();
    bool startGame();

private:

    int m_start_sound;
	std::vector<sf::RectangleShape> m_rectangles;

	sf::Sprite m_title_sprite;
	sf::Texture m_title_texture;

	sf::Sprite m_playButtonSprite;
	sf::Texture m_playButtonTexture;

	std::clock_t m_t;

	float m_title_py;

	sf::FloatRect m_playButtonRect;
    bool m_start;

};

#endif