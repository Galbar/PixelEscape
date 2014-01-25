#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include "Scene.hpp"

class GameScene : public Scene
{
public:
    GameScene(sf::RenderWindow* window, const int lvl, const std::string& path);
    ~GameScene();

    virtual void update();
    virtual void draw();
};

#endif
