#ifndef MEMUSCENE_HPP
#define MENUSCENE_HPP

#include "Scene.hpp"

class MenuScene : public Scene
{
public:
    MenuScene(sf::RenderWindow* window);
    ~MenuScene();

    virtual void update();
    virtual void draw();
};

#endif
