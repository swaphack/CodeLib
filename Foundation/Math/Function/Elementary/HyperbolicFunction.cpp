#include "HyperbolicFunction.h"
#include <cmath>
#include <cassert>
using namespace math;

Decimal math::SinhFunction::getValue(const Decimal& var)
{
	return sinhl(var.value());
}

Decimal math::CoshFunction::getValue(const Decimal& var)
{
	return coshl(var.value());
}

Decimal math::TanhFunction::getValue(const Decimal& var)
{
	return tanhl(var.value());
}

Decimal math::CothFunction::getValue(const Decimal& var)
{
	double value = tanhl(var.value());
	if (value == 0) return 0;
	return 1.0 / value;
}

Decimal math::SechFunction::getValue(const Decimal& var)
{
	double value = coshl(var.value());
	if (value == 0) return 0;
	return 1.0 / value;
}

Decimal math::CschFunction::getValue(const Decimal& var)
{
	double value = sinhl(var.value());
	if (value == 0) return 0;
	return 1.0 / value;
}
