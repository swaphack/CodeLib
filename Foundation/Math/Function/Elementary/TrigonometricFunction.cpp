#include "TrigonometricFunction.h"

#include <cmath>
#include <cassert>

using namespace math;

Decimal SinFunction::getValue(const Decimal& var)
{
	return sinl(var);
}

Decimal CosFunction::getValue(const Decimal& var)
{
	return cosl(var);
}

Decimal TanFunction::getValue(const Decimal& var)
{
	return tanl(var);
}

Decimal CotFunction::getValue(const Decimal& var)
{
	Decimal val = tanl(var);

	assert(val != Integer::zero());

	return 1.0 / val.value();
}

Decimal SecFunction::getValue(const Decimal& var)
{
	Decimal val = cosl(var);

	assert(val != Integer::zero());

	return 1.0 / val.value();
}

Decimal CscFunction::getValue(const Decimal& var)
{
	Decimal val = sinl(var);

	assert(val != Integer::zero());

	return 1.0 / val.value();
}
