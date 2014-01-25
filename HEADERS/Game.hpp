#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "GameScene.hpp"
#include "MenuScene.hpp"

#define LVL_NUMBER 1

class Game
{
public:
    Game(sf::RenderWindow* window);
    ~Game();

    void execute();

private:
    std::string m_lvl_paths[];
    sf::RenderWindow* m_window;
    bool m_paused;
    bool m_main_menu;

    Scene* sc;

    int m_current_lvl;
};


#endif
