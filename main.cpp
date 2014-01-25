#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "HEADERS/Game.hpp"

#define WINDOW_SIZE 672 // CAMBIAR TAMBIEN EN GAMESCENE

int main()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE, 32), "Project RGB", sf::Style::Default);

    Game game(window);

    game.execute();
}
