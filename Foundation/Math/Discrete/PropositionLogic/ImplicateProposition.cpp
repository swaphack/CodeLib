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
	this->setCompoundType(CompoundPropositionType::Implicate);
}

bool ImplicateProposition::isTrue()
{
	if (getA()->isTrue() && !getB()->isTrue())
	{
		return false;
	}

	return true;
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
	this->setCompoundType(CompoundPropositionType::DoubleImplicate);
}

bool DoubleImplicateProposition::isTrue()
{
	return getA()->isTrue() == getB()->isTrue();
}
