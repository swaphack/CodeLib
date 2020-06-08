#include "Random.h"
#include "macros.h"

#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace sys;

uint32_t Random::_seed = 0;

Random::Random()
{
	
}

Random::~Random()
{

}

void Random::setSeed(uint32_t seed)
{
	_seed = seed;

	srand(seed);
}

uint32_t Random::getSeed()
{
	return _seed;
}

float Random::getNumber(float minValue, float maxValue)
{
	float min = minValue < maxValue ? minValue : maxValue;
	float max = maxValue > minValue ? maxValue : minValue;
	if (min == max)
	{
		return min;
	}
	return getNumber0_1() * (max - min) + min;
}

uint32_t Random::getNumber(uint32_t maxValue)
{
	return (uint32_t)getNumber0_1() * maxValue;
}

int32_t Random::getNumber(int32_t minValue, int32_t maxValue)
{
	return (int32_t)getNumber((float)minValue, (float)maxValue);
}

float Random::getNumber0_1()
{
	return rand() * 1.0f / RAND_MAX;
}

int32_t Random::getNumber0_max()
{
	return rand();
}

