#include "ExponentialFunction.h"
#include <cmath>
#include "Basic/base.h"

using namespace math;


ExponentialFunction::ExponentialFunction()
{

}

ExponentialFunction::ExponentialFunction(float exp)
{
	setExp(exp);
}

Decimal ExponentialFunction::getValue(const Decimal& var)
{
	return (double)powl((long double)getExp(), (long double)var);
}
