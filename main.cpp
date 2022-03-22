#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "FastNoiseLite.h"

sf::RenderWindow window;

int main()
{
    window.create(sf::VideoMode(800, 400), "SFML");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
            window.clear();

            window.display();
    }

    return 0;
}