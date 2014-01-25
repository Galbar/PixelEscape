#include "Player.hpp"
#include <iostream>

Player::Player()
{

}

Player::Player(int x, int y) : GameObject(x, y)
{
    m_is_moving = false;
    PlayerConfig cfg;
    cfg.keyMap = vector<sf::Keyboard::Key> (MAPPINGSIZE);
    cfg.keyMap[MOVEUP] = sf::Keyboard::W;
    cfg.keyMap[MOVELEFT] = sf::Keyboard::A;
    cfg.keyMap[MOVEDOWN] = sf::Keyboard::S;
    cfg.keyMap[MOVERIGHT] = sf::Keyboard::D;
    m_input = Input(cfg.keyMap, scene->m_window);
}

Player::~Player()
{

}

void Player::update()
{
    m_input.update();

    if (m_input.getKeyDown(MOVEUP))
        m_y--;
    else if (m_input.getKeyDown(MOVERIGHT))
        m_x++;
    else if (m_input.getKeyDown(MOVEDOWN))
        m_y++;
    else if (m_input.getKeyDown(MOVELEFT))
        m_x--;

}

void Player::draw()
{

}

sf::Vector2i Player::getPos()
{
    return sf::Vector2i(m_x, m_y);
}

void Player::setPos(sf::Vector2i n_pos)
{
    m_x = n_pos.x;
    m_y = n_pos.y;
}
