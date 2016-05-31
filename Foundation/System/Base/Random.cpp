#include "Random.h"
#include "macros.h"
#include "Instance.h"

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

Random* Random::getInstance()
{
	return Instance<Random>::getInstance();
}
