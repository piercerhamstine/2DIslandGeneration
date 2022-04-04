#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "FastNoiseLite.h"

#include "Button/Button.hpp"
#include "Generation/Map.hpp"
#include <iostream>

sf::RenderWindow window;

int main()
{
    window.create(sf::VideoMode(1200, 800), "SFML");

    sf::Font font;
    font.loadFromFile("OpenSans-Light.ttf");

    Button b(100,100);
    b.SetFont(font);
    b.SetText("Generate");
    
    Map m(sf::Vector2u(1,1), 700, 700);
    m.GenerateMap();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            b.OnEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(m);
        window.draw(b);
        window.display();
    }

    return 0;
}