#include "Map.hpp"
#include <iostream>

Map::Map(sf::Vector2u tileSize, unsigned int width, unsigned int height):vertices()
{
    seaNoise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    seaNoise.SetSeed(50);

    elevationNoise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);

    moisterNoise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    moisterNoise.SetSeed(100);


    mapWidth = width;
    mapHeight = height;
    this->tileSize = tileSize;
    freq = 1.f;
    redist = 1.f;

    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(mapWidth*mapHeight*4);
};

float Map::GetFreq()
{
    return freq;
};

void Map::SetFreq(float val)
{
    freq = val;
};

float Map::GetRedist()
{
    return redist;
};

void Map::SetRedist(float val)
{
    redist = val;
}

sf::Color Map::GetTileType(float eVal, float mVal)
{
    if(eVal < .1) return ocean;
    if(eVal < 0.15) return coast;

    if(eVal > 0.8)
    {
        if(mVal < .3)
        {
            return snow;
        }

        return stone;
    };

    if(eVal > 0.35)
    {
        if(mVal < .4)
        {
            return forest;
        }
        return grass;
    };

    return plains;
};

float GetNoise(float x, float y)
{

};

void Map::GenerateMap()
{
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

void Map::UpdateMap()
{
    for(unsigned int i = 0; i < mapWidth; ++i)
    {
        for(unsigned int j = 0; j < mapHeight; ++j)
        {
            sf::Vertex* quad = &vertices[(i+j*mapWidth)*4];
        };
    };
};

void Map::draw(sf::RenderTarget& rtarget, sf::RenderStates states) const
{
    rtarget.draw(vertices, states);
};