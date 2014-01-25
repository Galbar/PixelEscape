#include "GameObject.hpp"

GameObject::GameObject(int x, int y, GameScene* scene)
{
    m_x = x;
    m_y = y;
    m_scene = scene;
}

GameObject::~GameObject()
{

}

void GameObject::update()
{

}

void GameObject::draw()
{

}

int GameObject::getX()
{
    return m_x;
}

int GameObject::getY()
{
    return m_y;
}
