#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Scene
{
public:
    Scene();
    Scene(sf::RenderWindow* window);
    ~Scene();

    virtual void update();
    virtual void draw();

protected:
	
	sf::RenderWindow* m_window;

private:
	
};

#endif
