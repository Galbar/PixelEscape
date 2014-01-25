#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Input.hpp"

struct Component
{
    bool is_alive;
    bool is_active;
    int x;
    int y;

    Component()
    {

    }

    Component(int _x, int _y)
    {
        x = _x;
        y = _y;
        is_alive = true;
        is_active = true;
    }

    void die()
    {
        is_alive = false;
        is_active = false;
    }
};

class Player
{
public:
    Player();
    Player(int x, int y, sf::RenderWindow* window);
    ~Player();

    virtual void update();
    virtual void draw();

    char getMask();
    sf::Vector2i getActivePos();
    std::vector<bool> getActiveColor(); // [0]:r [1]:g [2]:b
    sf::Vector2i getPos(int i); // 0:r 1:g 2:b
    void killRGB(int i); // 0:r 1:g 2:b

private:
    Input m_input;
    Component m_r;
    Component m_g;
    Component m_b;
    sf::RenderWindow* m_window;
};
#endif
