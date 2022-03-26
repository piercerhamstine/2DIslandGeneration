#ifndef MAP_HPP
#define MAP_HPP

#include "../FastNoiseLite.h"
#include "SFML/Graphics.hpp"
#include <math.h>

class Map : public sf::Drawable
{
public:
    Map(sf::Vector2u tileSize, unsigned int width, unsigned int height);

    void GenerateMap();
    void UpdateMap();

    float GetFreq();
    void SetFreq(float val);
    float GetRedist();
    void SetRedist(float val);
private:
    virtual void draw(sf::RenderTarget& rTarget, sf::RenderStates rStates) const;
    sf::VertexArray vertices;

    float GetNoise(float x, float y);

    sf::Color GetTileType(float eval, float mval);

    unsigned int mapWidth;
    unsigned int mapHeight;
    sf::Vector2u tileSize;

    sf::Color plains = sf::Color(214, 252, 76);
    sf::Color grass = sf::Color(76, 164, 39);
    sf::Color forest = sf::Color(46, 107, 17);
    sf::Color ocean = sf::Color(19, 75, 158);
    sf::Color lake = sf::Color(33, 150, 208);
    sf::Color stone = sf::Color(125, 125, 125);
    sf::Color snow = sf::Color(242, 242, 242);
    sf::Color coast = sf::Color(246, 234, 124);
};

#endif