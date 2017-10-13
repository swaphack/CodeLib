#include "Random.h"
#include "macros.h"

#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace sys;

Random::Random()
:_min(0)
, _max(1)
{
	srand(time(nullptr));
}

Random::~Random()
{

}


Random* Random::getInstance()
{
	static Random* s_Random = nullptr;
	if (s_Random == nullptr)
	{
		s_Random = new Random();
	}
	return s_Random;
}

void Random::setSeed(unsigned int seed)
{
	srand(seed);
}

void Random::setRange(float minValue, float maxValue)
{
	ASSERT(minValue < maxValue);

	_min = minValue;
	_max = maxValue;
}

float Random::getNextNumber()
{
	float value = rand() *1.0f;

	value = value / RAND_MAX * (_max - _min) + _min;

	return value;
}

int Random::getNextInteger()
{
	int value = rand();
	value = value % (int)(_max - _min) + _min;
	return value;
}

