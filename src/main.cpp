#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512, 32), "Project RGB", sf::Style::Default);

    while(1)
    {
        window.display();
    }
}
