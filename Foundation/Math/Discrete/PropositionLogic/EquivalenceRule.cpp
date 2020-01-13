#include "EquivalenceRule.h"
#include "PrimaryProposition.h"
#include "CompoundProposition.h"

using namespace math;

EquivalenceRule::EquivalenceRule()
{

}

EquivalenceRule::~EquivalenceRule()
{

}

CompoundProposition* EquivalenceRule::GetEquivalenceProposition(CompoundProposition* proposition)
{
	return nullptr;
}

//////////////////////////////////////////////////////////////////////////
EquivalenceRule1::EquivalenceRule1()
{

}

EquivalenceRule1::~EquivalenceRule1()
{

}

CompoundProposition* EquivalenceRule1::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<NegativeProposition>())
	{
		return nullptr;
	}

	auto pTemp = proposition->as<NegativeProposition>();
	if (pTemp->getA() == nullptr || !pTemp->getA()->is<DisjunctiveProposition>())
	{
		return nullptr;
	}

	auto pChild = pTemp->getA()->as<DisjunctiveProposition>();

	NegativeProposition* a = Proposition::createProposition<NegativeProposition>();
	a->setA(pChild->getA());

	NegativeProposition* b = Proposition::createProposition<NegativeProposition>();
	b->setA(pChild->getB());

	CombinedProposition* p = Proposition::createProposition<CombinedProposition>();
	p->setA(a);
	p->setA(b);

	return p;
}

//////////////////////////////////////////////////////////////////////////

EquivalenceRule2::EquivalenceRule2()
{

}

EquivalenceRule2::~EquivalenceRule2()
{

}

CompoundProposition* EquivalenceRule2::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<NegativeProposition>())
	{
		return nullptr;
	}

	auto pTemp = proposition->as<NegativeProposition>();
	if (pTemp->getA() == nullptr || !pTemp->getA()->is<CombinedProposition>())
	{
		return nullptr;
	}

	auto pChild = pTemp->getA()->as<CombinedProposition>();

	NegativeProposition* a = Proposition::createProposition<NegativeProposition>();
	a->setA(pChild->getA());

	NegativeProposition* b = Proposition::createProposition<NegativeProposition>();
	b->setA(pChild->getB());

	DisjunctiveProposition* p = Proposition::createProposition<DisjunctiveProposition>();
	p->setA(a);
	p->setA(b);

	return p;
}

CompoundProposition* EquivalenceRule3::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<DisjunctiveProposition>())
	{
		return nullptr;
	}

	auto pTemp = proposition->as<DisjunctiveProposition>();
	if (pTemp->getA() == nullptr || pTemp->getB() == nullptr)
	{
		return nullptr;
	}

	Proposition* pPrimaryChild = nullptr;
	CombinedProposition* pCombinedChild = nullptr;
	if (pTemp->getB()->is<CombinedProposition>())
	{
		pPrimaryChild = pTemp->getA();
		pCombinedChild = pTemp->getB()->as<CombinedProposition>();
	}
	else if (pTemp->getA()->is<CombinedProposition>())
	{
		pPrimaryChild = pTemp->getB();
		pCombinedChild = pTemp->getA()->as<CombinedProposition>();
	}

	if (pPrimaryChild == nullptr || pCombinedChild == nullptr)
	{
		return nullptr;
	}

	auto pLeftChild = pCombinedChild->getA();
	auto pRightChild = pCombinedChild->getB();

	DisjunctiveProposition* a = Proposition::createProposition<DisjunctiveProposition>();
	a->setA(pPrimaryChild);
	a->setB(pLeftChild);

	DisjunctiveProposition* b = Proposition::createProposition<DisjunctiveProposition>();
	b->setA(pPrimaryChild);
	b->setB(pRightChild);

	CombinedProposition* p = Proposition::createProposition<CombinedProposition>();
	p->setA(a);
	p->setA(b);

	return p;
}
