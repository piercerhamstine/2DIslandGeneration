#ifndef MAP_HPP
#define MAP_HPP

#include "../FastNoiseLite.h"
#include "NoiseHelper.hpp"
#include "SFML/Graphics.hpp"
#include <math.h>

class Map : public sf::Drawable
{
public:
    Map(sf::Vector2u tileSize, unsigned int width, unsigned int height);

    void GenerateMap();
private:
    virtual void draw(sf::RenderTarget& rTarget, sf::RenderStates rStates) const;
    sf::VertexArray vertices;

    sf::Color GetTileType(float eval);

    unsigned int mapWidth;
    unsigned int mapHeight;
    sf::Vector2u tileSize;

    sf::Color currentTileColor;

    NoiseHelper elevation;

    sf::Color grass = sf::Color(76, 164, 39);
    sf::Color ocean = sf::Color(33, 150, 208);
    sf::Color stone = sf::Color(125, 125, 125);
    sf::Color snow = sf::Color(242, 242, 242);
    sf::Color coast = sf::Color(246, 234, 124);
};

#endif