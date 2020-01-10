#include "ConstantFunction.h"

using namespace math;


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
