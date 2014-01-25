#include "GameObject.hpp"

//GameObject(int x, int y, GameScene* scene)
GameObject::GameObject(int x, int y)
{
    m_x = x;
    m_y = y;
    //m_scene = scene;
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
