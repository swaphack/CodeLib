#include "Proposition.h"

using namespace math;

Proposition::Proposition(const Proposition& proposition)
{
	*this = proposition;
}

Proposition::Proposition()
{

}

Proposition::~Proposition()
{

}

bool Proposition::isTrue()
{
	return false;
}

bool Proposition::hasSameIdentify(Proposition* proposition)
{
	return proposition->getIdentify() == getIdentify();
}

bool Proposition::isSameTo(Proposition* proposition)
{
	if (proposition == nullptr)
	{
		return false;
	}

	if (getType() != proposition->getType())
	{
		return false;
	}

	if (proposition->getIdentify() != this->getIdentify())
	{
		return false;
	}

	return proposition->isTrue() == this->isTrue();
}

bool Proposition::operator==(const Proposition& value) const
{
	return getIdentify() == value.getIdentify();
}

Proposition& Proposition::operator=(const Proposition& value)
{
	this->setIdentify(value.getIdentify());
	this->setUserData(value.getUserData());

	return *this;
}

bool Proposition::operator!=(const Proposition& value) const
{
	return getIdentify() != value.getIdentify();
}

bool Proposition::operator>=(const Proposition& value) const
{
	return getIdentify() >= value.getIdentify();
}

bool Proposition::operator>(const Proposition& value) const
{
	return getIdentify() > value.getIdentify();
}

bool Proposition::operator<(const Proposition& value) const
{
	return getIdentify() < value.getIdentify();
}

bool Proposition::operator<=(const Proposition& value) const
{
	return getIdentify() <= value.getIdentify();
}

