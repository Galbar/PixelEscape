#include "Game.hpp"


Game::Game(sf::RenderWindow* window)
{
    m_current_lvl = -1;
    m_window = window;
    ifstream lvl_list;
    lvl_list.open("data/levels/info");
    if (!lvl_list.good())
    {
        std::cerr << "[Game] Error al abrir info." << std::endl;
    }
    while (not lvl_list.eof())
    {
        string s;
        getline(lvl_list, s);
        if (s != "")
            m_lvl_paths.push_back("data/levels/" + s + ".PE");
        std::cerr << s << std::endl;
    }
    std::cerr << "# lvls: " << m_lvl_paths.size() << std::endl;
    Gsc = NULL;
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
    AudioPlayer* a_p = AudioPlayer::sharedAudioPlayer();
    a_p->stopMusic();
    a_p->playMusic(m_music_start_scene);

    sf::Time music_offset;
    sf::Time pause_music_offset;
    while(1)
    {
        // EVENTS
        Input::s_input->update();
        sf::Event event;
        bool foo = false;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window->close();
                foo = true;
                break;
            }
        }
        if (foo) break;

        if (m_is_in_game_scene)
        {
            if (Input::s_input->getKeyDown(PAUSE))
            {
                if (m_paused)
                {
                    pause_music_offset = a_p->getMusicOffset();
                    a_p->stopMusic();
                    a_p->playMusic(m_music_playing);
                    a_p->setMusicOffset(music_offset);
                    Gsc->resume();
                    m_paused = false;
                }
                else
                {
                    music_offset = a_p->getMusicOffset();
                    a_p->stopMusic();
                    a_p->playMusic(m_music_paused, 25);
                    a_p->setMusicOffset(pause_music_offset);
                    Gsc->pause();
                    m_paused = true;
                }
            }
            bool need_to_reload = false;
            bool next_level = false;
            if (!m_paused)
            {
                Gsc->update();
                if (Input::s_input->getKeyDown(RESTART) or Gsc->gameOver())
                {
                    need_to_reload = true;
                }
                if (Gsc->win())
                {
                    next_level = true;
                }
            }
            m_window->clear();
            Gsc->draw();
            m_window->display();

            if (need_to_reload)
            {
                reloadLevel();
            }
            if (next_level)
            {
                nextLevel();
            }
        }
        else
        {
            Ssc->update();
            m_window->clear();
            Ssc->draw();
            m_window->display();

            if (Ssc->startGame())
            {
                m_is_in_game_scene = true;
                nextLevel();
            }
        }
    }
}

void Game::nextLevel()
{
    if (m_current_lvl < 0)
    {
        AudioPlayer::sharedAudioPlayer()->playMusic(m_music_playing);
    }
    m_current_lvl++;
    std::clock_t t=  std::clock();
    std::clock_t t2=  std::clock();
    while(t2 - t  < 400000)
    {
        t2 = std::clock();
    }
    if (m_lvl_paths.size() <= m_current_lvl)
    {
        m_is_in_game_scene = false;
        m_current_lvl = -1;
        if (Ssc != NULL)
            delete Ssc;
        Ssc = new StartScene(m_window);
        AudioPlayer::sharedAudioPlayer()->playMusic(m_music_start_scene);
    }
    else
    {
        if (Gsc != NULL)
            delete Gsc;
        Gsc = new GameScene(m_window, m_current_lvl+1, m_lvl_paths[m_current_lvl]);
    }
}

void Game::reloadLevel()
{
    if (Gsc != NULL)
    {
        delete Gsc;
        
    }
    Gsc = new GameScene(m_window, m_current_lvl+1, m_lvl_paths[m_current_lvl]);
}