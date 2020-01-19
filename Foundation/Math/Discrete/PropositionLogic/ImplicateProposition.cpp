#include "ImplicateProposition.h"

using namespace math;

ImplicateProposition::ImplicateProposition(Proposition* a, Proposition* b)
	:ImplicateProposition()
{
	setA(a);
	setB(b);
}

ImplicateProposition::ImplicateProposition()
{
	this->setLogicID(COMPOUND_PROPOSITION_SIGNAL_IMPLICATE);
}

ImplicateProposition::ImplicateProposition(const ImplicateProposition& value)
	:ImplicateProposition()
{
	*this = value;
}

ImplicateProposition::~ImplicateProposition()
{

}

Proposition* ImplicateProposition::clone()
{
	return create<ImplicateProposition>();
}

Proposition* ImplicateProposition::deepClone()
{
	ImplicateProposition* proposition = create<ImplicateProposition>();
	proposition->setChildren(this->deepCloneChildren());
	return proposition;
}

bool ImplicateProposition::isTrue()
{
	if (getA()->isTrue() && !getB()->isTrue())
	{
		return false;
	}

	return true;
}

ImplicateProposition& ImplicateProposition::operator=(const ImplicateProposition& value)
{
	CompoundProposition::operator=(value);

	return *this;
}



//////////////////////////////////////////////////////////////////////////
DoubleImplicateProposition::DoubleImplicateProposition(Proposition* a, Proposition* b)
	:DoubleImplicateProposition()
{
	setA(a);
	setB(b);
}

DoubleImplicateProposition::DoubleImplicateProposition()
{
	this->setLogicID(COMPOUND_PROPOSITION_SIGNAL_DOUBLEIMPLICATE);
}

DoubleImplicateProposition::DoubleImplicateProposition(const DoubleImplicateProposition& value)
	:DoubleImplicateProposition()
{
	*this = value;
}

DoubleImplicateProposition::~DoubleImplicateProposition()
{

}

bool DoubleImplicateProposition::isTrue()
{
	return getA()->isTrue() == getB()->isTrue();
}

Proposition* DoubleImplicateProposition::clone()
{
	return create<DoubleImplicateProposition>();
}

Proposition* DoubleImplicateProposition::deepClone()
{
	DoubleImplicateProposition* proposition = create<DoubleImplicateProposition>();
	proposition->setChildren(this->deepCloneChildren());
	return proposition;
}

DoubleImplicateProposition& DoubleImplicateProposition::operator=(const DoubleImplicateProposition& value)
{
	CompoundProposition::operator=(value);
	return *this;
}
