#include "Game.hpp"

sf::RenderWindow* Game::s_window;

Game::Game(sf::RenderWindow* window)
{
    s_window = window;
    m_window = window;
    m_lvl_paths.push_back("data/levels/test.png");

    sc = new GameScene(m_window, 1, m_lvl_paths[0]);


    PlayerConfig cfg;
    cfg.keyMap = vector<sf::Keyboard::Key> (MAPPINGSIZE);
    cfg.keyMap[MOVEUP] = sf::Keyboard::W;
    cfg.keyMap[MOVELEFT] = sf::Keyboard::A;
    cfg.keyMap[MOVEDOWN] = sf::Keyboard::S;
    cfg.keyMap[MOVERIGHT] = sf::Keyboard::D;
    cfg.keyMap[ALTMOVEUP] = sf::Keyboard::Up;
    cfg.keyMap[ALTMOVELEFT] = sf::Keyboard::Left;
    cfg.keyMap[ALTMOVEDOWN] = sf::Keyboard::Down;
    cfg.keyMap[ALTMOVERIGHT] = sf::Keyboard::Right;
    cfg.keyMap[JOINCOMPONENTS] = sf::Keyboard::J;
    cfg.keyMap[SELECTR] = sf::Keyboard::Num1;
    cfg.keyMap[SELECTG] = sf::Keyboard::Num2;
    cfg.keyMap[SELECTB] = sf::Keyboard::Num3;
    cfg.keyMap[SELECTOTHER] = sf::Keyboard::Num4;

    new Input(cfg.keyMap, m_window);
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
