#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "FastNoiseLite.h"

#include "Generation/Map.hpp"
#include <iostream>

sf::RenderWindow window;

int main()
{
    window.create(sf::VideoMode(800, 400), "SFML");

    Map m(sf::Vector2u(1,1), 400, 400);
    m.GenerateMap();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
        }

        window.clear();
        window.draw(m);
        window.display();
    }

    return 0;
}