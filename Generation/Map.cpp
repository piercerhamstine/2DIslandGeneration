#include "Map.hpp"
#include <iostream>

Map::Map(sf::Vector2u tileSize, unsigned int width, unsigned int height):vertices()
{
    mapWidth = width;
    mapHeight = height;
    this->tileSize = tileSize;

    elevation.SetNoiseType(FastNoiseLite::NoiseType::NoiseType_OpenSimplex2);
    elevation.SetSeed(0);

    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(mapWidth*mapHeight*4);

    // Set vertex positions;
    for(unsigned int i = 0; i < mapWidth; ++i)
    {
        for(unsigned int j = 0; j < mapHeight; ++j)
        {
            sf::Vertex* quad = &vertices[(i+j*mapWidth)*4];

            quad[0].position = sf::Vector2f(i*tileSize.x, j*tileSize.y);
            quad[1].position = sf::Vector2f((i+1)*tileSize.x, j*tileSize.y);
            quad[2].position = sf::Vector2f((i+1)*tileSize.x, (j+1)*tileSize.y);
            quad[3].position = sf::Vector2f(i*tileSize.x, (j+1)*tileSize.y);
        };
    };
};

sf::Color Map::GetTileType(float eVal)
{
    if(eVal > .9) return snow;
    if(eVal > .6) return stone;
    if(eVal > .3) return grass;
    if(eVal > .2) return coast;

    return ocean;
};

void Map::GenerateMap()
{
    for(unsigned int i = 0; i < mapWidth; ++i)
    {
        for(unsigned int j = 0; j < mapHeight; ++j)
        {
            sf::Vertex* quad = &vertices[(i+j*mapWidth)*4];

            float eVal = elevation.GetNoise(i, j);

            currentTileColor = GetTileType(eVal);

            quad[0].color = quad[1].color = quad[2].color = quad[3].color = currentTileColor;
        };
    };
};

void Map::draw(sf::RenderTarget& rtarget, sf::RenderStates states) const
{
    rtarget.draw(vertices, states);
};