#include "Player.hpp"
#include <iostream>

//Player(int x, int y, GameScene* scene) : GameObject(x, y, scene)
Player::Player(int x, int y) : GameObject(x, y)
{
    m_is_moving = false;
}

Player::~Player()
{

}

void Player::update(sf::RenderWindow* m_window)
{
    sf::Event event;
    while (m_window->pollEvent(event))
    {
        std::cerr << event.type << std::endl;
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::W)
                m_y--;
            else if (event.key.code == sf::Keyboard::D)
                m_x++;
            else if (event.key.code == sf::Keyboard::S)
                m_y++;
            else if (event.key.code == sf::Keyboard::A)
                m_x--;
            std::cerr << "( " << m_x << " , " << m_y << " )" << std::endl;
        }
        if (event.type == sf::Event::KeyReleased)
        {
            std::cerr << "hai!" << std::endl;
            m_is_moving = not (event.key.code == sf::Keyboard::W 
                            or event.key.code == sf::Keyboard::D 
                            or event.key.code == sf::Keyboard::S 
                            or event.key.code == sf::Keyboard::A);
        }
    }

}

void Player::draw()
{

}
