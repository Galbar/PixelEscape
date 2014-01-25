#include "StartScene.hpp"

StartScene::StartScene(sf::RenderWindow* window) : Scene(window){

	if (!m_font.loadFromFile("data/fonts/PressStart2P.ttf"))
	{
		std::cerr << "[StartScene] Fuente no encontrada." << std::endl;
	}

	m_gameTitle.setFont(m_font);
	m_gameTitle.setString(("PIXEL ESCAPE"));
	m_gameTitle.setCharacterSize(90);
	m_gameTitle.setPosition(200,350);
	m_gameTitle.setColor(sf::Color::Yellow);
}

void StartScene::draw()
{
	Scene::draw();

	m_window ->draw(m_gameTitle);
}

void StartScene::update()
{
	Scene::update();
}

