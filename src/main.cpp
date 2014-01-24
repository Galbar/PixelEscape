#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(512, 512, 32), "Project RGB", sf::Style::Default);

    while(1)
    {
        // EVENTS
        sf::Event event;
        if (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
                break;
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window->close();
                break;
            }
        }

        // HERE LOGIC UPDATES



        // HERE DRAWING UPDATES




        window->display();
    }
}
