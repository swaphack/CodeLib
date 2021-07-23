#include "PrimaryProposition.h"

using namespace math;

PrimaryProposition::PrimaryProposition()
{
	this->setType(PropositionType::Primary);
}

PrimaryProposition::PrimaryProposition(PropositionResult result)
	:PrimaryProposition()
{
	this->setResult(result);
}

PrimaryProposition::PrimaryProposition(const PrimaryProposition& value)
	: PrimaryProposition()
{
	*this = value;
}

PrimaryProposition::~PrimaryProposition()
{
}

Proposition* PrimaryProposition::clone()
{
	PrimaryProposition* proposition = create<PrimaryProposition>();
	proposition->setLogicID(this->getLogicID());
	return proposition;
}

Proposition* PrimaryProposition::deepClone()
{
	PrimaryProposition* proposition = create<PrimaryProposition>();
	proposition->setLogicID(this->getLogicID());
	return proposition;
}

bool PrimaryProposition::isTrue()
{
	return getResult() == PropositionResult::EPR_TRUE;
}

PrimaryProposition& PrimaryProposition::operator=(const PrimaryProposition& value)
{
	Proposition::operator=(value);
	this->setResult(value.getResult());
	return *this;
}

bool PrimaryProposition::hasSameLogic(Proposition* proposition)
{
	if (proposition == nullptr)
	{
		return false;
	}

	if (!proposition->is<PrimaryProposition>())
	{
		return false;
	}

	return Proposition::hasSameLogic(proposition);
}


