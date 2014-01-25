#include "Game.hpp"

Game::Game(sf::RenderWindow* window)
{
    m_window = window;
    std::string m_lvl_paths[LVL_NUMBER] = {
        "data/levels/level1.jpg"
    };
}

Game::~Game()
{

}

void Game::execute()
{
    while(1)
    {
        // EVENTS
        sf::Event event;
        if (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window->close();
                break;
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                m_window->close();
                break;
            }
        }

        // HERE LOGIC UPDATES


        m_window->clear();
        // HERE DRAWING UPDATES




        m_window->display();
    }
}
