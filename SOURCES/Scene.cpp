#include "Scene.hpp"

Scene::Scene()
{

}

Scene::Scene(sf::RenderWindow* window)
{
    m_window = window;
}

Scene::~Scene()
{

}

void Scene::draw()
{
	for (int i = 0; i < m_displayObjects.size(); ++i)
	{
		m_displayObjects[i]->draw();
	}
}

void Scene::update()
{
	for (int i = 0; i < m_displayObjects.size(); ++i)
	{
		m_displayObjects[i]->update();
	}
}


