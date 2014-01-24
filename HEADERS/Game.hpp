#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game
{
public:
    Game(sf::RenderWindow* window);
    ~Game();

    void execute();

private:
    sf::RenderWindow* m_window;
    bool m_paused;
};


#endif
