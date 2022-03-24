#include "Map.hpp"
#include <iostream>

Map::Map():vertices(){};

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

void Map::GenerateMap(sf::Vector2u tileSize, unsigned int width, unsigned int height)
{
    mapWidth = width;
    mapHeight = height;
    tileSize = tileSize;
    freq = 1.f;
    redist = 1.f;

    FastNoiseLite noise;
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);

    //FastNoiseLite moisterNoise;
    //noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);

    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(width*height*4);

    sf::Color tileColor;
    for(unsigned int i = 0; i < width; ++i)
    {
        for(unsigned int j = 0; j < height; ++j)
        {
            sf::Vertex* quad = &vertices[(i+j*width)*4];

            quad[0].position = sf::Vector2f(i*tileSize.x, j*tileSize.y);
            quad[1].position = sf::Vector2f((i+1)*tileSize.x, j*tileSize.y);
            quad[2].position = sf::Vector2f((i+1)*tileSize.x, (j+1)*tileSize.y);
            quad[3].position = sf::Vector2f(i*tileSize.x, (j+1)*tileSize.y);

            float nVal = noise.GetNoise((float)i*freq, (float)j*freq);
            nVal = (nVal - (-1))/(1-(-1));
            nVal = pow(nVal, redist);
            
            if(nVal < 0.1)
            {
                tileColor = water;
            }
            else if(nVal < 0.2)
            {
                tileColor = coast;
            }
            else if(nVal < 0.5)
            {
                tileColor = grass;
            }
            else if(nVal < 0.7)
            {
                tileColor = forest;
            }
            else if(nVal < .9)
            {
                tileColor = stone;
            }
            else
            {
                tileColor = snow;
            }

            for(int i = 0; i < 4; ++i)
            {
                quad[i].color = tileColor;
            }
        };
    };
};

void Map::UpdateMap()
{
    FastNoiseLite noise;
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    
    sf::Color tileColor;
    for(unsigned int i = 0; i < mapWidth; ++i)
    {
        for(unsigned int j = 0; j < mapHeight; ++j)
        {
            sf::Vertex* quad = &vertices[(i+j*mapWidth)*4];

            float nVal = noise.GetNoise((float)i*freq, (float)j*freq);
            nVal = (nVal - (-1))/(1-(-1));

            nVal = pow(nVal, redist);

            if(nVal < 0.1)
            {
                tileColor = water;
            }
            else if(nVal < 0.2)
            {
                tileColor = coast;
            }
            else if(nVal < 0.5)
            {
                tileColor = grass;
            }
            else if(nVal < 0.7)
            {
                tileColor = forest;
            }
            else if(nVal < .9)
            {
                tileColor = stone;
            }
            else
            {
                tileColor = snow;
            }

            for(int i = 0; i < 4; ++i)
            {
                quad[i].color = tileColor;
            }
        };
    };
};

void Map::draw(sf::RenderTarget& rtarget, sf::RenderStates states) const
{
    rtarget.draw(vertices, states);
};