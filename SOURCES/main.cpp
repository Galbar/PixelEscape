#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "AudioPlayer.hpp"

#include "Game.hpp"

#define WINDOW_SIZE 688 // CAMBIAR TAMBIEN EN GAMESCENE

int main()
{
    sf::Music hola;
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE, 32), "· Pixel Escape ·", sf::Style::Close|sf::Style::Titlebar);

    Game game(window);

    game.execute();
    AudioPlayer::deleteAudioPlayer();

    delete window;
}
