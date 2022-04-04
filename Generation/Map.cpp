#include "Map.hpp"
#include <iostream>

Map::Map(sf::Vector2u tileSize, unsigned int width, unsigned int height):vertices()
{
    mapWidth = width;
    mapHeight = height;
    this->tileSize = tileSize;

    centerX = (float)mapWidth/2.f;
    centerY = (float)mapHeight/2.f;

    elevation.SetNoiseType(FastNoiseLite::NoiseType::NoiseType_OpenSimplex2);
    moisture.SetNoiseType(FastNoiseLite::NoiseType::NoiseType_OpenSimplex2);

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

float Map::GetAdjustedRange(float val, float min, float max)
{
    return (val - min) / (max - min);
};

sf::Color Map::GetTileType(float eVal, float mVal)
{
    if(eVal > .9)
    {
        if(mVal > .3f) return snow;
        return stone;
    };
    if(eVal > .6)
    {
        if(mVal > .6f) return forest;
        return stone;
    };
    if(eVal > .3)
    {
        if(mVal > .3f) return grass;
        return plains;
    };

    if(eVal > .2)
    {
        if(mVal > .4f) return plains;
        return coast;
    }

    if(eVal > .15) return coast;
    return ocean;
};

void Map::GenerateMap()
{
    elevation.SetSeed(time(nullptr));
    moisture.SetSeed(time(NULL));

    for(unsigned int i = 0; i < mapWidth; ++i)
    {
        for(unsigned int j = 0; j < mapHeight; ++j)
        {
            sf::Vertex* quad = &vertices[(i+j*mapWidth)*4];

            // Elevation Noise
            float eVal = 1.f * elevation.GetNoise(i*1.f, j*1.f) + (0.5f * elevation.GetNoise(i*2.f, j*2.f))+ (0.25f * elevation.GetNoise(i*4.f, j*4.f))
            + (0.125f * elevation.GetNoise(i*8, j*8));
            eVal = eVal / (1.f + 0.5f+0.25f+0.125f);

            // Elevation shaping
            eVal = pow(eVal*1.25f, .4f);

            // Moisture Noise
            float mVal = 1.f * moisture.GetNoise(i*1.f, j*1.f) + (0.25f * moisture.GetNoise(i*4.f, j*4.f)) + (0.0625f*moisture.GetNoise(i*16.f,j*16.f));
            mVal = mVal/(1.f + 0.25f + 0.0625f);

            // Gradient
            float dx = centerX - (float)i;
            float dy = centerY - (float)j;
            float dist = sqrt(dx*dx + dy*dy);
            dist = GetAdjustedRange(dist, 0, centerX);

            // Make sure distance doesn't exceed 1
            if(dist > 1.0f) dist = 1.0f;

            // Apply gradient to noise
            eVal = (eVal-dist);
            if(eVal < 0.f) eVal = 0.f;
            eVal = GetAdjustedRange(eVal, 0.f, 1.f);

            currentTileColor = GetTileType(eVal, mVal);
            quad[0].color = quad[1].color = quad[2].color = quad[3].color = currentTileColor;
        };
    };
};

void Map::draw(sf::RenderTarget& rtarget, sf::RenderStates states) const
{
    rtarget.draw(vertices, states);
};