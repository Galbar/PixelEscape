#include "Input.hpp"
#include <cstdio>

Input* Input::s_input = NULL;

Input::Input()
{

}

Input::Input(vector<sf::Keyboard::Key> v, sf::RenderWindow* window)
{
    m_window = window;
    mapSize = MAPPINGSIZE;
    valueMapSize = VALUESIZE;
    keys = vector<sf::Keyboard::Key> (mapSize);
    keysPressed = vector<bool> (mapSize, false);
    keysOldPressed = vector<bool> (mapSize, false);
    keyValues = vector<float> (valueMapSize, 128);

    for (int i = 0; i < int(v.size()); i++)
        keys[i] = v[i];

    s_input = this;
}

Input::~Input()
{
    delete s_input;
}

bool Input::getKeyPressed(int n)
{
    return keysPressed[n];
}

bool Input::getKeyDown(int n)
{
    return keysPressed[n] && !keysOldPressed[n];
}

float Input::getValue(int n)
{
    return keyValues[n];
}


/*
void Input::setKey(int n, Keyboard::Key val)
{
keys[n] = val;
}

Keyboard::Key Input::getKey(int n)
{
return keys[n];
}*/

void Input::update()
{
    keysOldPressed = keysPressed;

    for (int i = 0; i < mapSize; i++)
    {
        keysPressed[i] = sf::Keyboard::isKeyPressed(keys[i]);
    }

    sf::Vector2i mpos = sf::Mouse::getPosition(*m_window);

    sf::Vector2f pos ( float(mpos.x) - float(m_window->getSize().x) / 2,
              float(m_window->getSize().y) / 2 - float(mpos.y));
    pos /= float(m_window->getSize().y/2);

    keyValues[POINTERX] = pos.x;
    keyValues[POINTERY] = pos.y;
}
