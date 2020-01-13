#include "BooleanProposition.h"

using namespace math;

//////////////////////////////////////////////////////////////////////////
DisjunctiveProposition::DisjunctiveProposition(Proposition* a, Proposition* b)
	:DisjunctiveProposition()
{
	setA(a);
	setB(b);
}

DisjunctiveProposition::DisjunctiveProposition()
{
	this->setLogicID(COMPOUND_PROPOSITION_SIGNAL_OR);
}

DisjunctiveProposition::DisjunctiveProposition(const DisjunctiveProposition& value)
	:DisjunctiveProposition()
{
	*this = value;
}

DisjunctiveProposition::~DisjunctiveProposition()
{

}

bool DisjunctiveProposition::isTrue()
{
	return getA()->isTrue() || getB()->isTrue();
}

DisjunctiveProposition& DisjunctiveProposition::operator=(const DisjunctiveProposition& value)
{
	CompoundProposition::operator=(value);

	return *this;
}



//////////////////////////////////////////////////////////////////////////
CombinedProposition::CombinedProposition(Proposition* a, Proposition* b)
	:CombinedProposition()
{
	setA(a);
	setB(b);
}

CombinedProposition::CombinedProposition()
{
	this->setLogicID(COMPOUND_PROPOSITION_SIGNAL_AND);
}

CombinedProposition::CombinedProposition(const CombinedProposition& value)
	:CombinedProposition()
{
	*this = value;
}

CombinedProposition::~CombinedProposition()
{

}

bool CombinedProposition::isTrue()
{
	return getA()->isTrue() && getB()->isTrue();
}

CombinedProposition& CombinedProposition::operator=(const CombinedProposition& value)
{
	CompoundProposition::operator=(value);

	return *this;
}

//////////////////////////////////////////////////////////////////////////
NegativeProposition::NegativeProposition(Proposition* a)
	:NegativeProposition()
{
	setA(a);
}

NegativeProposition::NegativeProposition()
{
	_children.resize(1);
	this->setLogicID(COMPOUND_PROPOSITION_SIGNAL_NOT);
}

NegativeProposition::NegativeProposition(const NegativeProposition& value)
	:NegativeProposition()
{
	*this = value;
}

NegativeProposition::~NegativeProposition()
{

}

bool NegativeProposition::isTrue()
{
	return !getA()->isTrue();
}

NegativeProposition& NegativeProposition::operator=(const NegativeProposition& value)
{
	CompoundProposition::operator=(value);

	return *this;
}



//////////////////////////////////////////////////////////////////////////
ExclusiveORProposition::ExclusiveORProposition()
{
	this->setLogicID(COMPOUND_PROPOSITION_SIGNAL_XOR);
}

ExclusiveORProposition::ExclusiveORProposition(Proposition* a, Proposition* b)
	:ExclusiveORProposition()
{
	setA(a);
	setB(b);
}

ExclusiveORProposition::ExclusiveORProposition(const ExclusiveORProposition& value)
	:ExclusiveORProposition()
{
	*this = value;
}

ExclusiveORProposition::~ExclusiveORProposition()
{

}

bool ExclusiveORProposition::isTrue()
{
	return getA()->isTrue() != getB()->isTrue();
}

ExclusiveORProposition& ExclusiveORProposition::operator=(const ExclusiveORProposition& value)
{
	CompoundProposition::operator=(value);

	return *this;
}
