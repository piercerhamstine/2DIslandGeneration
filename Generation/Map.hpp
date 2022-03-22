#ifndef MAP_HPP
#define MAP_HPP

#include "../FastNoiseLite.h"
#include "SFML/Graphics.hpp"

class Map : public sf::Drawable
{
public:
    Map();

    void GenerateMap(sf::Vector2u tileSize, unsigned int width, unsigned int height);
private:
    virtual void draw(sf::RenderTarget& rTarget, sf::RenderStates rStates) const;
    sf::VertexArray vertices;

    sf::Color grass = sf::Color(76, 164, 39);
    sf::Color water = sf::Color(33, 150, 208);
};

#endif