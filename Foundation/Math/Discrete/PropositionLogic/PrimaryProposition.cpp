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
{
	*this = value;
}

Proposition* PrimaryProposition::clone()
{
	return create<PrimaryProposition>();
}

Proposition* PrimaryProposition::deepClone()
{
	return create<PrimaryProposition>();
}

PrimaryProposition::~PrimaryProposition()
{
}

bool PrimaryProposition::isTrue()
{
	return getResult() == PropositionResult::TRUE;
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

	if (!Proposition::hasSameLogic(proposition))
	{
		return false;
	}

	return this->getResult() == proposition->as<PrimaryProposition>()->getResult();
}


