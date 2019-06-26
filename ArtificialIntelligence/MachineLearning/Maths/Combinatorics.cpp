#include "Combinatorics.h"
#include "Number.h"

uint64_t maths::Combinatorics::pick(uint64_t nPickNum, uint64_t nTotalNum)
{
	return Number::factorial(nTotalNum) / (Number::factorial(nTotalNum - nPickNum) * Number::factorial(nPickNum));
}
