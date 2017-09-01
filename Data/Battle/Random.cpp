#include "Random.h"
#include <cstdlib>
#include <ctime>


static Random* s_pInstance = nullptr;

Random::Random()
{
	srand((unsigned int)time(0));
}

Random::~Random()
{

}

Random* Random::GetInstance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new Random();
	}

	return s_pInstance;
}

void Random::SetSeed(int seed)
{
	srand(seed);
}

int Random::Next(int minVal, int maxVal)
{
	if (maxVal == minVal)
	{
		return minVal;
	}
	else if (maxVal < minVal)
	{
		return -1;
	}

	return rand() % (maxVal - minVal) + minVal;
}

float Random::Next(float minVal, float maxVal)
{
	if (maxVal == minVal)
	{
		return minVal;
	}
	else if (maxVal < minVal)
	{
		return -1;
	}

	return Next() * (maxVal - minVal) + minVal;
}

float Random::Next()
{
	return 1.0f * rand() / RAND_MAX;
}
