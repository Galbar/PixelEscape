#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"
#include "Input.hpp"

class Player : public GameObject
{
public:
    Player();
    Player(int x, int y);
    ~Player();

    virtual void update();
    virtual void draw();

    sf::Vector2i getPos();
    void setPos(sf::Vector2i n_pos);

private:
    bool m_is_moving;
    Input m_input;

};
#endif
