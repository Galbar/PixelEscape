#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Game.hpp"
#include "GameScene.hpp"

class GameObject
{
public:
    GameObject(int x, int y, GameScene* scene);
    ~GameObject();

    int getX();
    int getY();

    virtual void update();
    virtual void draw();

protected:
    int m_x;
    int m_y;
    GameScene* m_scene;
};
#endif