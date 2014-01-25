#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"
#include "Input.hpp"

class Player : public GameObject
{
public:
    Player(int x, int y, GameScene* scene);
    ~Player();

    virtual void update();
    virtual void draw();

private:
    bool m_is_moving;
    Input m_input;
};
#endif
