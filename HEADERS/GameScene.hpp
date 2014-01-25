#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include "Scene.hpp"
#include "Player.hpp"
#include <vector>
#include <string>
#include <iostream>

#define WINDOW_SIZE 688
#define TILE_COUNT 43

struct Tile
{
    bool r;
    bool g;
    bool b;
    bool is_begin;
    bool is_end;
    int index;

    char getMask()
    {
        return 4*r + 2*g + b;
    }

    sf::Color beginColor()
    {
        return sf::Color(100, 100, 100);
    }

    sf::Color endColor()
    {
        return sf::Color(200, 200, 200);
    }

    Tile()
    {
        r = false;
        g = false;
        b = false;
        is_begin = false;
        is_end = false;
        index = 0;
    }

    Tile(sf::Color c)
    {
        r = false;
        g = false;
        b = false;
        is_begin = false;
        is_end = false;
        if (c == sf::Color::Black)
        {
            // nada
            index = 0;
        }
        else if (c == sf::Color::White)
        {
            r = true;
            g = true;
            b = true;
            index = 1;
        }
        else if (c == sf::Color::Red)
        {
            r = true;
            index = 2;
        }
        else if (c == sf::Color::Green)
        {
            g = true;
            index = 3;
        }
        else if (c == sf::Color::Blue)
        {
            b = true;
            index = 4;
        }
        else if (c == sf::Color::Yellow)
        {
            r = true;
            g = true;
            index = 5;
        }
        else if (c == sf::Color::Magenta)
        {
            r = true;
            b = true;
            index = 6;
        }
        else if (c == sf::Color::Cyan)
        {
            g = true;
            b = true;
            index = 7;
        }
        else if (c == beginColor())
        {
            is_begin = true;
            index = 8;
        }
        else if (c == endColor())
        {
            is_end = true;
            index = 9;
        }
        else
        {
            std::cerr << "[Tile] Color desconocido para mi :/" << std::endl;
        }
    }
};

typedef std::vector<std::vector<Tile> > TileMatrix;

class GameScene : public Scene
{
public:
    GameScene();
    GameScene(sf::RenderWindow* window, const int lvl, const std::string& path);
    ~GameScene();

    virtual void update();
    virtual void draw();

private:
    TileMatrix m_map;
    Tile m_required_color;
    Player* m_player;
    sf::Texture m_tilemap;
    int m_x_begin; // porque se lee mejor
    int m_y_begin;
};

#endif
