#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <string>
#include <vector>
#include "AudioPlayer.hpp"
#include "GameScene.hpp"
#include "StartScene.hpp"

#define LVL_NUMBER 1

class Game
{
public:
    Game(sf::RenderWindow* window);
    ~Game();

    void execute();

    static sf::RenderWindow *s_window;

private:
    std::vector<std::string> m_lvl_paths;
    sf::RenderWindow* m_window;
    bool m_paused;
    bool m_is_in_game_scene;
    

    // Music
    int m_music_playing;
    int m_music_paused;
    int m_music_start_scene;
    int m_music_final_boss;

    GameScene* Gsc;
    StartScene* Ssc;

    int m_current_lvl;
};


#endif
