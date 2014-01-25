#include "Game.hpp"


Game::Game(sf::RenderWindow* window)
{
    m_window = window;
    m_lvl_paths.push_back("data/levels/level13.png");

    Gsc = new GameScene(m_window, 1, m_lvl_paths[0]);
    Ssc = new StartScene(m_window);

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
    cfg.keyMap[PAUSE] = sf::Keyboard::P;
    cfg.keyMap[RESTART] = sf::Keyboard::R;

    new Input(cfg.keyMap, m_window);

    m_paused = false;
    m_is_in_game_scene = false;

    //Musica molona!!
    AudioPlayer* a_p = AudioPlayer::sharedAudioPlayer();
    m_music_start_scene = a_p->addMusic(std::string("data/audio/music/Cancion Inicio.wav"));
    m_music_paused = a_p->addMusic(std::string("data/audio/music/Cancion para pausa.wav"));
    m_music_playing = a_p->addMusic(std::string("data/audio/music/PrimerLevel.wav"));
    m_music_final_boss = a_p->addMusic(std::string("data/audio/music/Final Boss Song.wav"));
    a_p->stopMusic();
}

Game::~Game()
{
    delete Gsc;
    delete Ssc;
}

void Game::execute()
{
    sf::Time music_offset;
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

        if (m_is_in_game_scene)
        {
            if (Input::s_input->getKeyPressed(PAUSE))
            {
                if (m_paused)
                {
                    AudioPlayer* a_p = AudioPlayer::sharedAudioPlayer();
                    a_p->stopMusic();
                    a_p->playMusic(m_music_playing);
                    a_p->setMusicOffset(music_offset);
                    Gsc->resume();
                }
                else
                {
                    AudioPlayer* a_p = AudioPlayer::sharedAudioPlayer();
                    music_offset = a_p->getMusicOffset();
                    a_p->stopMusic();
                    a_p->playMusic(m_music_paused);
                    Gsc->pause();
                }
                m_paused = !m_paused;
            }
            if (!m_paused)
            {
                Gsc->update();
            }
            m_window->clear();
            Gsc->draw();
            m_window->display();
        }
        else
        {
            Ssc->update();
            m_window->clear();
            Ssc->draw();
            m_window->display();
        }
    }
}
