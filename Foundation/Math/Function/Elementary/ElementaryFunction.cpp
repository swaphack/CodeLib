#include "ElementaryFunction.h"
#include <cmath>
#include <cassert>

using namespace math;



Decimal ElementaryFunction::getValue(const Decimal& var)
{
	return 0;
}
//////////////////////////////////////////////////////////////////////////
ConstantFunction::ConstantFunction()
{

}

ConstantFunction::ConstantFunction(float constant)
{
	setConstant(constant);
}

Decimal ConstantFunction::getValue(const Decimal& var)
{
	return getConstant();
}

//////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////
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