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
    float GetAdjustedRange(float val, float min, float max);
    sf::Color GetTileType(float eVal, float mVal);

    unsigned int mapWidth;
    unsigned int mapHeight;
    float centerX;
    float centerY;
    sf::Vector2u tileSize;

    sf::Color currentTileColor;

    NoiseHelper elevation;
    NoiseHelper moisture;

    sf::Color snow = sf::Color(250, 248, 250);
    sf::Color stone = sf::Color(162, 159, 161);
    sf::Color forest = sf::Color(90, 102, 82);
    sf::Color grass = sf::Color(92, 153, 51);
    sf::Color plains = sf::Color(162,179,107);
    sf::Color coast = sf::Color(227, 208, 79);
    sf::Color ocean = sf::Color(0, 163, 131);
};

#endif