#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Game.hpp"

#define WINDOW_SIZE 688 // CAMBIAR TAMBIEN EN GAMESCENE

int main()
{
    sf::Music hola;
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE, 32), "Project RGB", sf::Style::Default);

    Game game(window);

    game.execute();

    delete window;
}
