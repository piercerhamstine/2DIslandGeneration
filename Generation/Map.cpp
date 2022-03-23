#include "Map.hpp"

Map::Map():vertices(){};

void Map::GenerateMap(sf::Vector2u tileSize, unsigned int width, unsigned int height)
{
    FastNoiseLite noise;
    noise.SetNoiseType(FastNoiseLite::NoiseType::NoiseType_Perlin);
    noise.SetFrequency(.01f);

    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(width*height*4);

    for(unsigned int i = 0; i < width; ++i)
    {
        for(unsigned int j = 0; j < height; ++j)
        {
            sf::Vertex* quad = &vertices[(i+j*width)*4];

            quad[0].position = sf::Vector2f(i*tileSize.x, j*tileSize.y);
            quad[1].position = sf::Vector2f((i+1)*tileSize.x, j*tileSize.y);
            quad[2].position = sf::Vector2f((i+1)*tileSize.x, (j+1)*tileSize.y);
            quad[3].position = sf::Vector2f(i*tileSize.x, (j+1)*tileSize.y);

            float nVal = noise.GetNoise((float)i, (float)j);

            sf::Color tileColor;
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
            else if(nVal < .8)
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