#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "FastNoiseLite.h"

#include "Generation/Map.hpp"
#include <iostream>

sf::RenderWindow window;

int main()
{
    window.create(sf::VideoMode(1200, 720), "SFML");

    Map m(sf::Vector2u(1,1), 700, 700);
    m.GenerateMap();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(m);
        window.display();
    }

    return 0;
}