#include "InverseTrigonometricFunction.h"

#include <cmath>
#include <cassert>
using namespace math;

Decimal math::ArcSinFunction::getValue(const Decimal& var)
{
	return asinl(var.value());
}

Decimal math::ArcCosFunction::getValue(const Decimal& var)
{
	return acosl(var.value());
}

Decimal math::ArcTanFunction::getValue(const Decimal& var)
{
	return atanl(var.value());
}

Decimal math::ArcCotFunction::getValue(const Decimal& var)
{
	Decimal val = var.value();
	assert(val != Integer::zero());
	return atanl(1.0 / val.value());
}

Decimal math::ArcSecFunction::getValue(const Decimal& var)
{
	Decimal val = var.value();
	assert(val != Integer::zero());
	return asinl(1.0 / var.value());
}

Decimal math::ArcCscFunction::getValue(const Decimal& var)
{
	Decimal val = var.value();
	assert(val != Integer::zero());
	return acosl(1.0 / var.value());
}
