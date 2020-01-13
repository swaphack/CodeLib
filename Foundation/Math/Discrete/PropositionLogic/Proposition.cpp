#include "Proposition.h"

using namespace math;

PropositionCache Proposition::_propositionCache;

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

bool Proposition::hasSameLogic(Proposition* proposition)
{
	if (proposition == nullptr)
	{
		return false;
	}

	if (proposition->getType() != this->getType())
	{
		return false;
	}

	return proposition->getLogicID() == this->getLogicID();
}

bool Proposition::operator==(const Proposition& value) const
{
	return getInstanceID() == value.getInstanceID();
}

Proposition& Proposition::operator=(const Proposition& value)
{
	Node::operator=(value);

	this->setLogicID(value.getLogicID());

	return *this;
}

bool Proposition::operator!=(const Proposition& value) const
{
	return getInstanceID() != value.getInstanceID();
}

bool Proposition::operator>=(const Proposition& value) const
{
	return getInstanceID() >= value.getInstanceID();
}

bool Proposition::operator>(const Proposition& value) const
{
	return getInstanceID() > value.getInstanceID();
}

bool Proposition::operator<(const Proposition& value) const
{
	return getInstanceID() < value.getInstanceID();
}

bool Proposition::operator<=(const Proposition& value) const
{
	return getInstanceID() <= value.getInstanceID();
}

void Proposition::cleanCache()
{
	_propositionCache.clear();
}

