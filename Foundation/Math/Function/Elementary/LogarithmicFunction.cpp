#include "LogarithmicFunction.h"

#include <cmath>
#include <cassert>

using namespace math;


LogarithmicFunction::LogarithmicFunction()
{

}

LogarithmicFunction::LogarithmicFunction(float base)
{
	setBase(base);
}


Decimal LogarithmicFunction::getValue(const Decimal& var)
{
	Decimal base = logl(getBase());

	assert(base != Integer::zero());

	Decimal exp = logl(var);

	return exp / base;
}
