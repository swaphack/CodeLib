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

PrimaryProposition::~PrimaryProposition()
{

}

bool PrimaryProposition::isTrue()
{
	return getResult() == PropositionResult::TRUE;
}

bool PrimaryProposition::isSameTo(Proposition* proposition)
{
	if (proposition == nullptr)
	{
		return false;
	}

	if (proposition->getType() != PropositionType::Primary)
	{
		return false;
	}

	return Proposition::isSameTo(proposition);
}

PrimaryProposition& PrimaryProposition::operator=(const PrimaryProposition& value)
{
	Proposition::operator=(value);
	this->setResult(value.getResult());
	return *this;
}


