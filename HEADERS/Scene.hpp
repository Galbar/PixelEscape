#ifndef SCENE_HPP
#define SCENE_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Scene
{
public:
    Scene(sf::RenderWindow* window);
    ~Scene();

    virtual void update();
    virtual void draw();

private:
    sf::RenderWindow* m_window;
};

#endif
