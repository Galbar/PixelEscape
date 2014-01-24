#include "GameObject.hpp"

GameObject()
{

}

GameObject(int x, int y)
{
    m_x = x;
    m_y = y;
}

~GameObject()
{

}

int getX()
{
    return m_x;
}

int getY()
{
    return m_y;
}
