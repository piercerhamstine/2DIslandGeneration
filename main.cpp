#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "FastNoiseLite.h"

#include "Generation/Map.hpp"


sf::RenderWindow window;

int main()
{
    window.create(sf::VideoMode(800, 400), "SFML");

    Map m;
    m.GenerateMap(sf::Vector2u(10,10), 20, 20);

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