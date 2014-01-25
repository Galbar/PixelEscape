#include "Player.hpp"
#include <iostream>

bool samePos(Component a, Component b)
{
    return a.x == b.x and a.y == b.y;
}

bool insideFrustum(Component a, int x, int y)
{
    return a.x >= x-21 and a.x <= x+21 and a.y >= y-21 and a.y <= y+21;
}

Player::Player()
{

}

Player::Player(int x, int y, sf::RenderWindow* window)
{
    PlayerConfig cfg;
    cfg.keyMap = vector<sf::Keyboard::Key> (MAPPINGSIZE);
    cfg.keyMap[MOVEUP] = sf::Keyboard::W;
    cfg.keyMap[MOVELEFT] = sf::Keyboard::A;
    cfg.keyMap[MOVEDOWN] = sf::Keyboard::S;
    cfg.keyMap[MOVERIGHT] = sf::Keyboard::D;
    cfg.keyMap[ALTMOVEUP] = sf::Keyboard::Up;
    cfg.keyMap[ALTMOVELEFT] = sf::Keyboard::Left;
    cfg.keyMap[ALTMOVEDOWN] = sf::Keyboard::Down;
    cfg.keyMap[ALTMOVERIGHT] = sf::Keyboard::Right;
    cfg.keyMap[JOINCOMPONENTS] = sf::Keyboard::J;
    cfg.keyMap[SELECTR] = sf::Keyboard::Num1;
    cfg.keyMap[SELECTG] = sf::Keyboard::Num2;
    cfg.keyMap[SELECTB] = sf::Keyboard::Num3;
    cfg.keyMap[SELECTOTHER] = sf::Keyboard::Num4;

    m_input = Input(cfg.keyMap, window);

    m_window = window;

    m_r = Component(x, y);
    m_g = Component(x, y);
    m_b = Component(x, y);
}

Player::~Player()
{

}

void Player::update()
{
    m_input.update();

    if (m_input.getKeyDown(MOVEUP))
    {
        if (m_r.is_active and m_r.is_alive)
            m_r.y--;
        if (m_g.is_active and m_g.is_alive)
            m_g.y--;
        if (m_b.is_active and m_b.is_alive)
            m_b.y--;
    }
    else if (m_input.getKeyDown(MOVERIGHT))
    {
        if (m_r.is_active and m_r.is_alive)
            m_r.x++;
        if (m_g.is_active and m_g.is_alive)
            m_g.x++;
        if (m_b.is_active and m_b.is_alive)
            m_b.x++;
    }
    else if (m_input.getKeyDown(MOVEDOWN))
    {
        if (m_r.is_active and m_r.is_alive)
            m_r.y++;
        if (m_g.is_active and m_g.is_alive)
            m_g.y++;
        if (m_b.is_active and m_b.is_alive)
            m_b.y++;
    }
    else if (m_input.getKeyDown(MOVELEFT))
    {
        if (m_r.is_active and m_r.is_alive)
            m_r.x--;
        if (m_g.is_active and m_g.is_alive)
            m_g.x--;
        if (m_b.is_active and m_b.is_alive)
            m_b.x--;
    }
    else if (m_input.getKeyDown(JOINCOMPONENTS))
    {
        sf::Vector2i p = getActivePos();
        m_r.is_active = (m_r.is_alive and m_r.x == p.x and m_r.y == p.y);
        m_g.is_active = (m_g.is_alive and m_g.x == p.x and m_g.y == p.y);
        m_b.is_active = (m_b.is_alive and m_b.x == p.x and m_b.y == p.y);
    }
    else if (m_input.getKeyDown(SELECTR))
    {
        if (m_r.is_alive)
        {
            m_g.is_active = false;
            m_b.is_active = false;
            m_r.is_active = true;
        }
    }
    else if (m_input.getKeyDown(SELECTG))
    {
        if (m_g.is_alive)
        {
            m_r.is_active = false;
            m_b.is_active = false;
            m_g.is_active = true;
        }
    }
    else if (m_input.getKeyDown(SELECTB))
    {
        if (m_b.is_alive)
        {
            m_r.is_active = false;
            m_g.is_active = false;
            m_b.is_active = true;
        }
    }
    else if (m_input.getKeyDown(SELECTOTHER))
    {

    }

    std::cerr << "player ( " << getActivePos().x << " , " << getActivePos().y << " )" << std::endl;
}

void Player::draw(int cam_x, int cam_y)
{
    if (samePos(m_r, m_g) and samePos(m_r, m_b) and m_r.is_alive and m_g.is_alive and m_b.is_alive)
    {
        if (insideFrustum(m_r, x, y))

    }
}

sf::Vector2i Player::getPos(int i)
{
    if (i == 0)
        return sf::Vector2i(m_r.x, m_r.y);
    if (i == 1)
        return sf::Vector2i(m_g.x, m_g.y);
    if (i == 2)
        return sf::Vector2i(m_b.x, m_b.y);
}

char Player::getMask()
{
    return 4*m_r.is_alive + 2*m_g.is_alive + m_b.is_alive;
}

sf::Vector2i Player::getActivePos()
{
    if (m_r.is_active and m_r.is_alive)
        return sf::Vector2i (m_r.x, m_r.y);
    if (m_g.is_active and m_g.is_alive)
        return sf::Vector2i (m_g.x, m_g.y);
    if (m_b.is_active and m_b.is_alive)
        return sf::Vector2i (m_b.x, m_b.y);
}

std::vector<bool> Player::getActiveColor()
{
    std::vector<bool> v(3);
    v[0] = m_r.is_active and m_r.is_alive;
    v[1] = m_g.is_active and m_g.is_alive;
    v[2] = m_b.is_active and m_b.is_alive;
    return v;
}

void Player::killRGB(int i)
{
    if (i == 0)
        m_r.die();
    else if (i == 1)
        m_g.die();
    else if (i == 2)
        m_b.die();
}
