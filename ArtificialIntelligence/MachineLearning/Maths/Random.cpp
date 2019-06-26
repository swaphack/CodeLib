#include "Random.h"

#include <cmath>
#include <cstdlib>

using namespace maths;

void Random::setSeed(int seed)
{
	::srand(seed);
}

int Random::randNumber(int max)
{
	return randNumber(0, max);
}

int Random::randNumber()
{
	return randNumber(INT_MAX);
}

int Random::randNumber(int min, int max)
{
	return min + ::rand() % (max - min);
}

float Random::randFloat()
{
	return 1.0f * ::rand() / INT_MAX;
}
