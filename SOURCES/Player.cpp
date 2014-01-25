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
    Input::s_input->update();

    if (Input::s_input->getKeyDown(MOVEUP) or Input::s_input->getKeyDown(ALTMOVEUP))
    {
        if (m_r.is_active and m_r.is_alive)
            m_r.y--;
        if (m_g.is_active and m_g.is_alive)
            m_g.y--;
        if (m_b.is_active and m_b.is_alive)
            m_b.y--;
    }
    else if (Input::s_input->getKeyDown(MOVERIGHT) or Input::s_input->getKeyDown(ALTMOVERIGHT))
    {
        if (m_r.is_active and m_r.is_alive)
            m_r.x++;
        if (m_g.is_active and m_g.is_alive)
            m_g.x++;
        if (m_b.is_active and m_b.is_alive)
            m_b.x++;
    }
    else if (Input::s_input->getKeyDown(MOVEDOWN) or Input::s_input->getKeyDown(ALTMOVEDOWN))
    {
        if (m_r.is_active and m_r.is_alive)
            m_r.y++;
        if (m_g.is_active and m_g.is_alive)
            m_g.y++;
        if (m_b.is_active and m_b.is_alive)
            m_b.y++;
    }
    else if (Input::s_input->getKeyDown(MOVELEFT) or Input::s_input->getKeyDown(ALTMOVELEFT))
    {
        if (m_r.is_active and m_r.is_alive)
            m_r.x--;
        if (m_g.is_active and m_g.is_alive)
            m_g.x--;
        if (m_b.is_active and m_b.is_alive)
            m_b.x--;
    }
    else if (Input::s_input->getKeyDown(JOINCOMPONENTS))
    {
        sf::Vector2i p = getActivePos();
        m_r.is_active = (m_r.is_alive and m_r.x == p.x and m_r.y == p.y);
        m_g.is_active = (m_g.is_alive and m_g.x == p.x and m_g.y == p.y);
        m_b.is_active = (m_b.is_alive and m_b.x == p.x and m_b.y == p.y);
    }
    else if (Input::s_input->getKeyDown(SELECTR))
    {
        if (m_r.is_alive)
        {
            m_g.is_active = false;
            m_b.is_active = false;
            m_r.is_active = true;
        }
    }
    else if (Input::s_input->getKeyDown(SELECTG))
    {
        if (m_g.is_alive)
        {
            m_r.is_active = false;
            m_b.is_active = false;
            m_g.is_active = true;
        }
    }
    else if (Input::s_input->getKeyDown(SELECTB))
    {
        if (m_b.is_alive)
        {
            m_r.is_active = false;
            m_g.is_active = false;
            m_b.is_active = true;
        }
    }
    else if (Input::s_input->getKeyDown(SELECTOTHER))
    {
        if (m_r.is_active and !m_g.is_active and !m_b.is_active
            and m_g.is_alive and m_b.is_alive and samePos(m_g, m_b))
        {
            m_r.is_active = false;
            m_g.is_active = true;
            m_b.is_active = true;
        }
        else if (m_g.is_active and !m_r.is_active and !m_b.is_active
            and m_r.is_alive and m_b.is_alive and samePos(m_r, m_b))
        {
            m_r.is_active = true;
            m_g.is_active = false;
            m_b.is_active = true;
        }
        else if (m_b.is_active and !m_g.is_active and !m_r.is_active
            and m_g.is_alive and m_r.is_alive and samePos(m_g, m_r))
        {
            m_r.is_active = true;
            m_g.is_active = true;
            m_b.is_active = false;
        }
    }
    std::cerr << "player ( " << getActivePos().x << " , " << getActivePos().y << " )" << std::endl;
}

void Player::drawPlayer(int x, int y, int col)
{
    x+=21;
    y+=21;
    int tile_size = 16;
    int tilemap_size = 8;
    sf::Sprite sprite;
    sf::Texture tilemap;
    if (!tilemap.loadFromFile("data/textures/tilemap.png")) std::cerr << "[GameScene] Error cargando tilemap" << endl;
    sprite.setTexture(tilemap);
    sprite.setPosition(tile_size*x, tile_size*y);
    int tx = (col%tilemap_size)*tile_size;
    int ty = (col/tilemap_size)*tile_size;
    sprite.setTextureRect(sf::IntRect(tx,ty,tile_size,tile_size));
    m_window->draw(sprite);
}

void Player::draw(int cam_x, int cam_y)
{
    int x = cam_x;
    int y = cam_y;
    if (samePos(m_r, m_g) and samePos(m_r, m_b) and m_r.is_alive and m_g.is_alive and m_b.is_alive)
    {
        if (insideFrustum(m_r, x, y))
            drawPlayer(m_r.x-x, m_r.y-y, 1); // WHITE
    }
    else if (samePos(m_r, m_g) and m_r.is_alive and m_g.is_alive)
    {
        if (insideFrustum(m_r, x, y))
            drawPlayer(m_r.x-x, m_r.y-y, 5); // YELLOW
        if (m_b.is_alive and insideFrustum(m_b, x, y))
            drawPlayer(m_b.x-x, m_b.y-y, 4); // BLUE
    }
    else if (samePos(m_r, m_b) and m_r.is_alive and m_b.is_alive)
    {
        if (insideFrustum(m_r, x, y))
            drawPlayer(m_r.x-x, m_r.y-y, 6); // MAGENTA
        if (m_g.is_alive and insideFrustum(m_g, x, y))
            drawPlayer(m_g.x-x, m_g.y-y, 3); // GREEN
    }
    else if (samePos(m_b, m_g) and m_b.is_alive and m_g.is_alive)
    {
        if (insideFrustum(m_b, x, y))
            drawPlayer(m_b.x-x, m_b.y-y, 7); // CYAN
        if (m_r.is_alive and insideFrustum(m_r, x, y))
            drawPlayer(m_r.x-x, m_r.y-y, 2); // RED
    }
    else
    {
        if (m_r.is_alive and insideFrustum(m_r, x, y))
            drawPlayer(m_r.x-x, m_r.y-y, 2); // RED
        if (m_g.is_alive and insideFrustum(m_g, x, y))
            drawPlayer(m_g.x-x, m_g.y-y, 3); // GREEN
        if (m_b.is_alive and insideFrustum(m_b, x, y))
            drawPlayer(m_b.x-x, m_b.y-y, 4); // BLUE
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

char Player::getActiveMask()
{
    return 4*m_r.is_alive*m_r.is_active + 2*m_g.is_alive*m_g.is_active + m_b.is_alive*m_b.is_active;
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
