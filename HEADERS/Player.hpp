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
    }
};

class Player
{
public:
    Player();
    Player(int x, int y, sf::RenderWindow* window);
    ~Player();

    void update();
    void draw(int cam_x, int cam_y);

    void drawPlayer(int x, int y, int col);

    char getMask();
    sf::Vector2i getActivePos();
    std::vector<bool> getActiveColor(); // [0]:r [1]:g [2]:b
    sf::Vector2i getPos(int i); // 0:r 1:g 2:b
    void killRGB(int i); // 0:r 1:g 2:b

private:
    Component m_r;
    Component m_g;
    Component m_b;
    sf::RenderWindow* m_window;
};
#endif
