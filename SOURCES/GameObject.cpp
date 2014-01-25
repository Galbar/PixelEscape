#include "GameObject.hpp"

GameObject::GameObject(int x, int y)
{
    m_x = x;
    m_y = y;
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
