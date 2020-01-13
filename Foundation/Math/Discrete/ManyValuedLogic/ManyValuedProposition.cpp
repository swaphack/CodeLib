#include "ManyValuedProposition.h"

using namespace math;

bool ManyValuedProposition::isTrue() const
{
	return getPercent() > 0;
}

bool ManyValuedProposition::hasSameLogic(Proposition* proposition)
{
	if (!Proposition::hasSameLogic(proposition))
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
