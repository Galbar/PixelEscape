#include "Input.h"
#include <cstdio>

Input::Input(vector<Keyboard::Key> v)
{
    mapSize = MAPPINGSIZE;
    valueMapSize = VALUESIZE;
    keys = vector<sf::Keyboard::Key> (mapSize);
    keysPressed = vector<bool> (mapSize);
    keysOldPressed = vector<bool> (mapSize);
    keyValues = vector<float> (valueMapSize, 128);

    for (int i = 0; i < v.size(); i++)
        keys[i] = v[i];
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
        if(keys[i] == Keyboard::Tab)
            keysPressed[i] = Mouse::isButtonPressed(Mouse::Left);
        else
            keysPressed[i] = Keyboard::isKeyPressed(keys[i]);
    }

    Vector2i mpos = Mouse::getPosition(*app);

    vec2 pos ( float(mpos.x) - float(app->getSize().x) / 2,
              float(app->getSize().y) / 2 - float(mpos.y));
    pos /= float(app->getSize().y/2);

    keyValues[POINTERX] = pos.x;
    keyValues[POINTERY] = pos.y;

    keyValues[DASHX] = 128.0 + (keysPressed[DASH])*1560;

    keyValues[CONNECTED] = true;

}


PlayerConfig playerConfigs[4];
