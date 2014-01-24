#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "HEADERS/Game.hpp"

int main()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(512, 512, 32), "Project RGB", sf::Style::Default);

    Game game(window);

    game.execute();
}
