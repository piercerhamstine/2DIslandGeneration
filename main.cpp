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

    FastNoiseLite noise;
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);


    Map m(sf::Vector2u(1,1), 200, 200);
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
            m.SetFreq(m.GetFreq() - .01f);
            m.UpdateMap();
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            m.SetFreq(m.GetFreq() + .01f);
            m.UpdateMap();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            m.SetRedist(m.GetRedist() - .01f);
            m.UpdateMap();
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            m.SetRedist(m.GetRedist() + .01f);
            m.UpdateMap();
        }

        window.clear();
        window.draw(m);
        window.display();
    }

    return 0;
}