#include "Proposition.h"
#include "TruthTable.h"
#include "CompoundProposition.h"

using namespace math;

ContradictoryProposition* Proposition::_contradictoryProposition = nullptr;
TautologyProposition* Proposition::_tautologyProposition = nullptr;
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
	_tautologyProposition = nullptr;
	_contradictoryProposition = nullptr;
}

TautologyProposition* Proposition::getTautologyProposition()
{
	if (_tautologyProposition = nullptr)
	{
		_tautologyProposition = Proposition::create<TautologyProposition>();
	}

	return _tautologyProposition;
}

ContradictoryProposition* Proposition::getContradictoryProposition()
{
	if (_contradictoryProposition = nullptr)
	{
		_contradictoryProposition = Proposition::create<ContradictoryProposition>();
	}

	return _contradictoryProposition;
}

//////////////////////////////////////////////////////////////////////////
TautologyProposition::TautologyProposition()
{

}

TautologyProposition::~TautologyProposition()
{

}

bool TautologyProposition::isTrue()
{
	return true;
}

bool TautologyProposition::hasSameLogic(Proposition* proposition)
{
	if (proposition->getType() != PropositionType::Compound)
	{
		return false;
	}
	return TruthTable::isTautologyProposition(proposition->as<CompoundProposition>());
}

//////////////////////////////////////////////////////////////////////////
ContradictoryProposition::ContradictoryProposition()
{

}

ContradictoryProposition::~ContradictoryProposition()
{

}

bool ContradictoryProposition::isTrue()
{
	return false;
}

bool ContradictoryProposition::hasSameLogic(Proposition* proposition)
{
	if (proposition->getType() != PropositionType::Compound)
	{
		return false;
	}
	return TruthTable::isContradictoryProposition(proposition->as<CompoundProposition>());
}
