#include "ManyValuedProposition.h"

using namespace math;

bool ManyValuedProposition::isTrue() const
{
	return getPercent() > 0;
}

bool ManyValuedProposition::isSameTo(Proposition* proposition)
{
	if (!Proposition::isSameTo(proposition))
	{
		return false;
	}

	ManyValuedProposition* pValue = dynamic_cast<ManyValuedProposition*>((Proposition*)proposition);
	if (pValue == nullptr)
	{
		return false;
	}

	return this->getPercent() == pValue->getValue();
}

float ManyValuedProposition::getValue() const
{
	return getPercent();
}
