#include "ManyValuedProposition.h"

using namespace math;

ManyValuedProposition::ManyValuedProposition()
{
	this->setType(PropositionType::Primary);
}

ManyValuedProposition::ManyValuedProposition(float percent)
	:ManyValuedProposition()
{
	this->setPercent(percent);
}

ManyValuedProposition::ManyValuedProposition(const ManyValuedProposition& proposition)
	: ManyValuedProposition()
{
	*this = proposition;
}

ManyValuedProposition::~ManyValuedProposition()
{

}

bool ManyValuedProposition::isTrue()
{
	return getPercent() > 0;
}

bool ManyValuedProposition::hasSameLogic(Proposition* proposition)
{
	if (proposition == nullptr)
	{
		return false;
	}

	if (!proposition->is<ManyValuedProposition>())
	{
		return false;
	}

	return Proposition::hasSameLogic(proposition);
}

Proposition* ManyValuedProposition::clone()
{
	ManyValuedProposition* proposition = create<ManyValuedProposition>();
	proposition->setLogicID(this->getLogicID());
	return proposition;
}

Proposition* ManyValuedProposition::deepClone()
{
	ManyValuedProposition* proposition = create<ManyValuedProposition>();
	proposition->setLogicID(this->getLogicID());
	return proposition;
}

ManyValuedProposition& ManyValuedProposition::operator=(const ManyValuedProposition& value)
{
	Proposition::operator=(value);
	this->setPercent(value.getPercent());
	return *this;
}
