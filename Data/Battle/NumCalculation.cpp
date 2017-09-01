#include "NumCalculation.h"
#include "Enum.h"
#include "Property.h"

float NumCalculation::Attack(Property* src, Property* dest)
{
	if (src == nullptr ||  dest == nullptr)
	{
		return 0;
	}

	float atk = src->GetValue((int)ATTRIBUTE::ATK);
	float def = dest->GetValue((int)ATTRIBUTE::DEF);

	return atk * (1 - def / (def + 19));
}

float NumCalculation::AtkInterval(Property* src)
{
	float itv = src->GetValue((int)ATTRIBUTE::ITV);
	if (itv	 == 0)
	{
		return 1.0f;
	}

	return 1.0f / itv;
}
