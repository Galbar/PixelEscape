#include "Game.hpp"

Game::Game(sf::RenderWindow* window)
{
    m_window = window;
    std::string m_lvl_paths[LVL_NUMBER] = {
        "data/levels/level1.png"
    };

    sc = new GameScene(m_window, 1, m_lvl_paths[0]);

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
        sc->update();

        m_window->clear();
        // HERE DRAWING UPDATES
        sc->draw();

        m_window->display();
    }
}
