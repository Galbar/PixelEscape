#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"

class Player : public GameObject
{
public:
    Player(int x, int y);
    ~Player();

    virtual void update(sf::RenderWindow* m_window);
    virtual void draw();

private:
    bool m_is_moving;
};
#endif