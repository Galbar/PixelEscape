#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"
#include "Input.hpp"

class Player : public GameObject
{
public:
    Player();
    Player(int x, int y, GameScene* scene);
    ~Player();

    virtual void update();
    virtual void draw();

private:
    Input m_input;

};
#endif
