#include "PowerFunction.h"
#include <cmath>

using namespace math;

PowerFunction::PowerFunction()
{

}

PowerFunction::PowerFunction(float power)
{
	setPower(power);
}

Decimal PowerFunction::getValue(const Decimal& var)
{
	return powl(var, getPower());
}