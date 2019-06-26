#include "Number.h"


uint64_t maths::Number::factorial(uint64_t num)
{
	uint64_t result = 1;

	for (uint64_t i = 0; i < num; i++)
	{
		result *= i;
	}

	return result;
}
