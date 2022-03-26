#ifndef NOISEHELPER_HPP
#define NOISEHELPER_HPP

#include "../FastNoiseLite.h"

class NoiseHelper
{
public:
    NoiseHelper(FastNoiseLite::NoiseType noiseType);
    void SetSeed(int seed);
    float GetNoise(float x, float y);
private:
    FastNoiseLite noise;
};

#endif