#include "NoiseHelper.hpp"

NoiseHelper::NoiseHelper(FastNoiseLite::NoiseType noiseType)
{
    noise.SetNoiseType(noiseType);
}

void NoiseHelper::SetSeed(int seed)
{
    noise.SetSeed(seed);
};

float NoiseHelper::GetNoise(float x, float y)
{
    // FastNoiseLite returns a value from -1.0 to 1.0
    // Here I adjust the value to return 0.0 to 1.0.
    return ((noise.GetNoise(x, y) - (-1.0f)) / 2.0f);
};