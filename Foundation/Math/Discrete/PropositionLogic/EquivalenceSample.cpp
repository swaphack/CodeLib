#include "EquivalenceSample.h"
#include "PrimaryProposition.h"
#include "CompoundProposition.h"
#include "ImplicateProposition.h"

using namespace math;

EquivalenceSample::EquivalenceSample()
{

}

EquivalenceSample::~EquivalenceSample()
{

}

Proposition* EquivalenceSample::GetEquivalenceProposition(CompoundProposition* proposition)
{
	return nullptr;
}

bool EquivalenceSample::isTautologyProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return false;
	}
	return Proposition::getTautologyProposition()->hasSameLogic(proposition);
}

bool EquivalenceSample::isContradictoryProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return false;
	}
	return Proposition::getContradictoryProposition()->hasSameLogic(proposition);
}

//////////////////////////////////////////////////////////////////////////
EquivalenceRule0::EquivalenceRule0()
{

}

EquivalenceRule0::~EquivalenceRule0()
{

}

Proposition* EquivalenceRule0::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<CombinedProposition>())
	{
		return nullptr;
	}

	auto pTemp = proposition->as<CombinedProposition>();
	if (pTemp->getA() == nullptr || pTemp->getB() == nullptr)
	{
		return nullptr;
	}

	if (pTemp->getA()->is<CompoundProposition>())
	{
		if (isTautologyProposition(pTemp->getA()->as<CompoundProposition>()))
		{
			return pTemp->getB();
		}
	}

	if (pTemp->getB()->is<CompoundProposition>())
	{
		if (isTautologyProposition(pTemp->getB()->as<CompoundProposition>()))
		{
			return pTemp->getA();
		}
	}

	return nullptr;
}

//////////////////////////////////////////////////////////////////////////
EquivalenceRule1::EquivalenceRule1()
{

}

EquivalenceRule1::~EquivalenceRule1()
{

}

Proposition* EquivalenceRule1::GetEquivalenceProposition(CompoundProposition* proposition)
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

	if (pTemp->getA()->is<CompoundProposition>())
	{
		if (isContradictoryProposition(pTemp->getA()->as<CompoundProposition>()))
		{
			return pTemp->getB();
		}
	}

	if (pTemp->getB()->is<CompoundProposition>())
	{
		if (isContradictoryProposition(pTemp->getB()->as<CompoundProposition>()))
		{
			return pTemp->getA();
		}
	}

	return nullptr;
}

//////////////////////////////////////////////////////////////////////////

EquivalenceRule2::EquivalenceRule2()
{

}

EquivalenceRule2::~EquivalenceRule2()
{

}

Proposition* EquivalenceRule2::GetEquivalenceProposition(CompoundProposition* proposition)
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

	if (pTemp->getA()->is<CompoundProposition>())
	{
		if (isTautologyProposition(pTemp->getA()->as<CompoundProposition>()))
		{
			return pTemp->getA();
		}
	}

	if (pTemp->getB()->is<CompoundProposition>())
	{
		if (isTautologyProposition(pTemp->getB()->as<CompoundProposition>()))
		{
			return pTemp->getB();
		}
	}

	return nullptr;
}
//////////////////////////////////////////////////////////////////////////
EquivalenceRule3::EquivalenceRule3()
{

}

EquivalenceRule3::~EquivalenceRule3()
{

}

Proposition* EquivalenceRule3::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<CombinedProposition>())
	{
		return nullptr;
	}

	auto pTemp = proposition->as<CombinedProposition>();
	if (pTemp->getA() == nullptr || pTemp->getB() == nullptr)
	{
		return nullptr;
	}

	if (pTemp->getA()->is<CompoundProposition>())
	{
		if (isContradictoryProposition(pTemp->getA()->as<CompoundProposition>()))
		{
			return pTemp->getA();
		}
	}

	if (pTemp->getB()->is<CompoundProposition>())
	{
		if (isContradictoryProposition(pTemp->getB()->as<CompoundProposition>()))
		{
			return pTemp->getB();
		}
	}

	return nullptr;
}

//////////////////////////////////////////////////////////////////////////
EquivalenceRule4::EquivalenceRule4()
{

}

EquivalenceRule4::~EquivalenceRule4()
{

}

Proposition* EquivalenceRule4::GetEquivalenceProposition(CompoundProposition* proposition)
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
	
	if (pTemp->getA()->hasSameLogic(pTemp->getB()))
	{
		return pTemp->getA();
	}

	return nullptr;
}
//////////////////////////////////////////////////////////////////////////

EquivalenceRule5::EquivalenceRule5()
{

}

EquivalenceRule5::~EquivalenceRule5()
{

}

Proposition* EquivalenceRule5::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<CombinedProposition>())
	{
		return nullptr;
	}

	auto pTemp = proposition->as<CombinedProposition>();
	if (pTemp->getA() == nullptr || pTemp->getB() == nullptr)
	{
		return nullptr;
	}

	if (pTemp->getA()->hasSameLogic(pTemp->getB()))
	{
		return pTemp->getA();
	}

	return nullptr;
}
//////////////////////////////////////////////////////////////////////////

EquivalenceRule6::EquivalenceRule6()
{

}

EquivalenceRule6::~EquivalenceRule6()
{

}

Proposition* EquivalenceRule6::GetEquivalenceProposition(CompoundProposition* proposition)
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
	if (pTemp->getA() == nullptr)
	{
		return nullptr;
	}

	if (!pTemp->getA()->is<NegativeProposition>())
	{
		return nullptr;
	}

	auto pTempChild = proposition->as<NegativeProposition>();

	return pTempChild->getA();
}
//////////////////////////////////////////////////////////////////////////


EquivalenceRule7::EquivalenceRule7()
{

}

EquivalenceRule7::~EquivalenceRule7()
{

}

Proposition* EquivalenceRule7::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<DisjunctiveProposition>())
	{
		return nullptr;
	}

	DisjunctiveProposition* pTemp = proposition->as<DisjunctiveProposition>();

	DisjunctiveProposition* p = Proposition::create<DisjunctiveProposition>();
	p->setA(pTemp->getB());
	p->setB(pTemp->getA());

	return p;
}
//////////////////////////////////////////////////////////////////////////


EquivalenceRule8::EquivalenceRule8()
{

}

EquivalenceRule8::~EquivalenceRule8()
{

}

Proposition* EquivalenceRule8::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<CombinedProposition>())
	{
		return nullptr;
	}

	CombinedProposition* pTemp = proposition->as<CombinedProposition>();

	CombinedProposition* p = Proposition::create<CombinedProposition>();
	p->setA(pTemp->getB());
	p->setB(pTemp->getA());

	return p;
}
//////////////////////////////////////////////////////////////////////////

EquivalenceRule9::EquivalenceRule9()
{

}

EquivalenceRule9::~EquivalenceRule9()
{

}

Proposition* EquivalenceRule9::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<DisjunctiveProposition>())
	{
		return nullptr;
	}

	DisjunctiveProposition* pTemp = proposition->as<DisjunctiveProposition>();

	Proposition* pPrimaryChild = nullptr;
	DisjunctiveProposition* pDisjunctiveChild = nullptr;

	if (pTemp->getA()->is<DisjunctiveProposition>())
	{
		pDisjunctiveChild = pTemp->getA()->as<DisjunctiveProposition>();
		pPrimaryChild = pTemp->getB();
	}
	else if (pTemp->getB()->is<DisjunctiveProposition>())
	{
		pDisjunctiveChild = pTemp->getB()->as<DisjunctiveProposition>();
		pPrimaryChild = pTemp->getA();
	}

	if (pPrimaryChild == nullptr || pDisjunctiveChild == nullptr)
	{
		return nullptr;
	}

	auto pLeftChild = pDisjunctiveChild->getA();
	auto pRightChild = pDisjunctiveChild->getB();

	DisjunctiveProposition* p1 = Proposition::create<DisjunctiveProposition>();
	p1->setA(pLeftChild);
	p1->setB(pPrimaryChild);

	DisjunctiveProposition* p0 = Proposition::create<DisjunctiveProposition>();
	p0->setA(p1);
	p0->setB(pRightChild);

	return p0;
}

//////////////////////////////////////////////////////////////////////////

EquivalenceRule33::EquivalenceRule33()
{

}

EquivalenceRule33::~EquivalenceRule33()
{

}

Proposition* EquivalenceRule33::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<DisjunctiveProposition>())
	{
		return nullptr;
	}

	DisjunctiveProposition* pTemp = proposition->as<DisjunctiveProposition>();

	Proposition* pPrimaryChild = nullptr;
	DisjunctiveProposition* pDisjunctiveChild = nullptr;

	if (pTemp->getA()->is<DisjunctiveProposition>())
	{
		pDisjunctiveChild = pTemp->getA()->as<DisjunctiveProposition>();
		pPrimaryChild = pTemp->getB();
	}
	else if (pTemp->getB()->is<DisjunctiveProposition>())
	{
		pDisjunctiveChild = pTemp->getB()->as<DisjunctiveProposition>();
		pPrimaryChild = pTemp->getA();
	}

	if (pPrimaryChild == nullptr || pDisjunctiveChild == nullptr)
	{
		return nullptr;
	}

	auto pLeftChild = pDisjunctiveChild->getA();
	auto pRightChild = pDisjunctiveChild->getB();

	DisjunctiveProposition* p1 = Proposition::create<DisjunctiveProposition>();
	p1->setA(pRightChild);
	p1->setB(pPrimaryChild);

	DisjunctiveProposition* p0 = Proposition::create<DisjunctiveProposition>();
	p0->setA(p1);
	p0->setB(pLeftChild);

	return p0;
}
//////////////////////////////////////////////////////////////////////////
EquivalenceRule10::EquivalenceRule10()
{

}

EquivalenceRule10::~EquivalenceRule10()
{

}

Proposition* EquivalenceRule10::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<CombinedProposition>())
	{
		return nullptr;
	}

	CombinedProposition* pTemp = proposition->as<CombinedProposition>();

	Proposition* pPrimaryChild = nullptr;
	CombinedProposition* pDisjunctiveChild = nullptr;

	if (pTemp->getA()->is<CombinedProposition>())
	{
		pDisjunctiveChild = pTemp->getA()->as<CombinedProposition>();
		pPrimaryChild = pTemp->getB();
	}
	else if (pTemp->getB()->is<CombinedProposition>())
	{
		pDisjunctiveChild = pTemp->getB()->as<CombinedProposition>();
		pPrimaryChild = pTemp->getA();
	}

	if (pPrimaryChild == nullptr || pDisjunctiveChild == nullptr)
	{
		return nullptr;
	}

	auto pLeftChild = pDisjunctiveChild->getA();
	auto pRightChild = pDisjunctiveChild->getB();

	CombinedProposition* p1 = Proposition::create<CombinedProposition>();
	p1->setA(pLeftChild);
	p1->setB(pPrimaryChild);

	CombinedProposition* p0 = Proposition::create<CombinedProposition>();
	p0->setA(p1);
	p0->setB(pRightChild);

	return p0;
}

//////////////////////////////////////////////////////////////////////////
EquivalenceRule34::EquivalenceRule34()
{

}

EquivalenceRule34::~EquivalenceRule34()
{

}

Proposition* EquivalenceRule34::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<CombinedProposition>())
	{
		return nullptr;
	}

	CombinedProposition* pTemp = proposition->as<CombinedProposition>();

	Proposition* pPrimaryChild = nullptr;
	CombinedProposition* pDisjunctiveChild = nullptr;

	if (pTemp->getA()->is<CombinedProposition>())
	{
		pDisjunctiveChild = pTemp->getA()->as<CombinedProposition>();
		pPrimaryChild = pTemp->getB();
	}
	else if (pTemp->getB()->is<CombinedProposition>())
	{
		pDisjunctiveChild = pTemp->getB()->as<CombinedProposition>();
		pPrimaryChild = pTemp->getA();
	}

	if (pPrimaryChild == nullptr || pDisjunctiveChild == nullptr)
	{
		return nullptr;
	}

	auto pLeftChild = pDisjunctiveChild->getA();
	auto pRightChild = pDisjunctiveChild->getB();

	CombinedProposition* p1 = Proposition::create<CombinedProposition>();
	p1->setA(pRightChild);
	p1->setB(pPrimaryChild);

	CombinedProposition* p0 = Proposition::create<CombinedProposition>();
	p0->setA(p1);
	p0->setB(pLeftChild);

	return p0;
}

//////////////////////////////////////////////////////////////////////////
EquivalenceRule11::EquivalenceRule11()
{

}

EquivalenceRule11::~EquivalenceRule11()
{

}

Proposition* EquivalenceRule11::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<DisjunctiveProposition>())
	{
		return nullptr;
	}

	DisjunctiveProposition* pTemp = proposition->as<DisjunctiveProposition>();

	Proposition* pPrimaryChild = nullptr;
	CombinedProposition* pDisjunctiveChild = nullptr;

	if (pTemp->getA()->is<CombinedProposition>())
	{
		pDisjunctiveChild = pTemp->getA()->as<CombinedProposition>();
		pPrimaryChild = pTemp->getB();
	}
	else if (pTemp->getB()->is<CombinedProposition>())
	{
		pDisjunctiveChild = pTemp->getB()->as<CombinedProposition>();
		pPrimaryChild = pTemp->getA();
	}

	if (pPrimaryChild == nullptr || pDisjunctiveChild == nullptr)
	{
		return nullptr;
	}

	auto pLeftChild = pDisjunctiveChild->getA();
	auto pRightChild = pDisjunctiveChild->getB();

	DisjunctiveProposition* p1 = Proposition::create<DisjunctiveProposition>();
	p1->setA(pLeftChild);
	p1->setB(pPrimaryChild);

	DisjunctiveProposition* p2 = Proposition::create<DisjunctiveProposition>();
	p2->setA(pRightChild);
	p2->setB(pPrimaryChild);

	CombinedProposition* p0 = Proposition::create<CombinedProposition>();
	p0->setA(p1);
	p0->setB(p2);

	return p0;
}
//////////////////////////////////////////////////////////////////////////


EquivalenceRule12::EquivalenceRule12()
{

}

EquivalenceRule12::~EquivalenceRule12()
{

}

Proposition* EquivalenceRule12::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<CombinedProposition>())
	{
		return nullptr;
	}

	CombinedProposition* pTemp = proposition->as<CombinedProposition>();

	Proposition* pPrimaryChild = nullptr;
	DisjunctiveProposition* pDisjunctiveChild = nullptr;

	if (pTemp->getA()->is<DisjunctiveProposition>())
	{
		pDisjunctiveChild = pTemp->getA()->as<DisjunctiveProposition>();
		pPrimaryChild = pTemp->getB();
	}
	else if (pTemp->getB()->is<DisjunctiveProposition>())
	{
		pDisjunctiveChild = pTemp->getB()->as<DisjunctiveProposition>();
		pPrimaryChild = pTemp->getA();
	}

	if (pPrimaryChild == nullptr || pDisjunctiveChild == nullptr)
	{
		return nullptr;
	}

	auto pLeftChild = pDisjunctiveChild->getA();
	auto pRightChild = pDisjunctiveChild->getB();

	CombinedProposition* p1 = Proposition::create<CombinedProposition>();
	p1->setA(pLeftChild);
	p1->setB(pPrimaryChild);

	CombinedProposition* p2 = Proposition::create<CombinedProposition>();
	p2->setA(pRightChild);
	p2->setB(pPrimaryChild);

	DisjunctiveProposition* p0 = Proposition::create<DisjunctiveProposition>();
	p0->setA(p1);
	p0->setB(p2);

	return p0;
}
//////////////////////////////////////////////////////////////////////////
EquivalenceRule13::EquivalenceRule13()
{

}

EquivalenceRule13::~EquivalenceRule13()
{

}

Proposition* EquivalenceRule13::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<NegativeProposition>())
	{
		return nullptr;
	}

	NegativeProposition* pTemp = proposition->as<NegativeProposition>();
	if (!pTemp->getA()->is<CombinedProposition>())
	{
		return nullptr;
	}

	CombinedProposition* pTempChild = pTemp->getA()->as<CombinedProposition>();

	NegativeProposition* a = Proposition::create<NegativeProposition>();
	a->setA(pTempChild->getA());

	NegativeProposition* b = Proposition::create<NegativeProposition>();
	b->setA(pTempChild->getB());


	DisjunctiveProposition* p0 = Proposition::create<DisjunctiveProposition>();
	p0->setA(a);
	p0->setB(b);

	return p0;
}

//////////////////////////////////////////////////////////////////////////
EquivalenceRule14::EquivalenceRule14()
{

}

EquivalenceRule14::~EquivalenceRule14()
{

}

Proposition* EquivalenceRule14::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<NegativeProposition>())
	{
		return nullptr;
	}

	NegativeProposition* pTemp = proposition->as<NegativeProposition>();
	if (!pTemp->getA()->is<DisjunctiveProposition>())
	{
		return nullptr;
	}

	DisjunctiveProposition* pTempChild = pTemp->getA()->as<DisjunctiveProposition>();

	NegativeProposition* a = Proposition::create<NegativeProposition>();
	a->setA(pTempChild->getA());

	NegativeProposition* b = Proposition::create<NegativeProposition>();
	b->setA(pTempChild->getB());


	CombinedProposition* p0 = Proposition::create<CombinedProposition>();
	p0->setA(a);
	p0->setB(b);

	return p0;
}

//////////////////////////////////////////////////////////////////////////
EquivalenceRule15::EquivalenceRule15()
{

}

EquivalenceRule15::~EquivalenceRule15()
{

}

Proposition* EquivalenceRule15::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<DisjunctiveProposition>())
	{
		return nullptr;
	}

	DisjunctiveProposition* pTemp = proposition->as<DisjunctiveProposition>();

	Proposition* pPrimaryChild = nullptr;
	CombinedProposition* pCombinedChild = nullptr;

	if (pTemp->getA()->is<CombinedProposition>())
	{
		pPrimaryChild = pTemp->getB();
		pCombinedChild = pTemp->getA()->as<CombinedProposition>();
	}
	else if (pTemp->getB()->is<CombinedProposition>())
	{
		pPrimaryChild = pTemp->getA();
		pCombinedChild = pTemp->getB()->as<CombinedProposition>();
	}

	if (pPrimaryChild == nullptr || pCombinedChild == nullptr)
	{
		return nullptr;
	}

	auto pLeftChild = pCombinedChild->getA();
	auto pRightChild = pCombinedChild->getB();

	if (pLeftChild->hasSameLogic(pPrimaryChild))
	{
		return pRightChild;
	}

	if (pRightChild->hasSameLogic(pPrimaryChild))
	{
		return pLeftChild;
	}

	return nullptr;
}

//////////////////////////////////////////////////////////////////////////
EquivalenceRule16::EquivalenceRule16()
{

}

EquivalenceRule16::~EquivalenceRule16()
{

}

Proposition* EquivalenceRule16::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<CombinedProposition>())
	{
		return nullptr;
	}

	CombinedProposition* pTemp = proposition->as<CombinedProposition>();

	Proposition* pPrimaryChild = nullptr;
	DisjunctiveProposition* pDisjunctiveChild = nullptr;

	if (pTemp->getA()->is<DisjunctiveProposition>())
	{
		pPrimaryChild = pTemp->getB();
		pDisjunctiveChild = pTemp->getA()->as<DisjunctiveProposition>();
	}
	else if (pTemp->getB()->is<DisjunctiveProposition>())
	{
		pPrimaryChild = pTemp->getA();
		pDisjunctiveChild = pTemp->getB()->as<DisjunctiveProposition>();
	}

	if (pPrimaryChild == nullptr || pDisjunctiveChild == nullptr)
	{
		return nullptr;
	}

	auto pLeftChild = pDisjunctiveChild->getA();
	auto pRightChild = pDisjunctiveChild->getB();

	if (pLeftChild->hasSameLogic(pPrimaryChild))
	{
		return pRightChild;
	}

	if (pRightChild->hasSameLogic(pPrimaryChild))
	{
		return pLeftChild;
	}

	return nullptr;
}
//////////////////////////////////////////////////////////////////////////


EquivalenceRule17::EquivalenceRule17()
{

}

EquivalenceRule17::~EquivalenceRule17()
{

}

Proposition* EquivalenceRule17::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<CombinedProposition>())
	{
		return nullptr;
	}

	CombinedProposition* pTemp = proposition->as<CombinedProposition>();
	if (pTemp->getA() == nullptr || pTemp->getB() == nullptr)
	{
		return nullptr;
	}

	Proposition* pPrimaryChild = nullptr;
	NegativeProposition* pNegativeChild = nullptr;

	if (pTemp->getA()->is<NegativeProposition>())
	{
		pNegativeChild = pTemp->getA()->as<NegativeProposition>();
		pPrimaryChild = pTemp->getB();
	}
	else if (pTemp->getB()->is<NegativeProposition>())
	{
		pNegativeChild = pTemp->getB()->as<NegativeProposition>();
		pPrimaryChild = pTemp->getA();
	}
	if (pPrimaryChild == nullptr || pPrimaryChild == nullptr)
	{
		return nullptr;
	}

	if (pPrimaryChild->hasSameLogic(pNegativeChild->getA()))
	{
		return Proposition::create<ContradictoryProposition>();
	}

	return nullptr;
}
//////////////////////////////////////////////////////////////////////////


EquivalenceRule18::EquivalenceRule18()
{

}

EquivalenceRule18::~EquivalenceRule18()
{

}

Proposition* EquivalenceRule18::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<DisjunctiveProposition>())
	{
		return nullptr;
	}

	DisjunctiveProposition* pTemp = proposition->as<DisjunctiveProposition>();
	if (pTemp->getA() == nullptr || pTemp->getB() == nullptr)
	{
		return nullptr;
	}

	Proposition* pPrimaryChild = nullptr;
	NegativeProposition* pNegativeChild = nullptr;

	if (pTemp->getA()->is<NegativeProposition>())
	{
		pNegativeChild = pTemp->getA()->as<NegativeProposition>();
		pPrimaryChild = pTemp->getB();
	}
	else if (pTemp->getB()->is<NegativeProposition>())
	{
		pNegativeChild = pTemp->getB()->as<NegativeProposition>();
		pPrimaryChild = pTemp->getA();
	}
	if (pPrimaryChild == nullptr || pPrimaryChild == nullptr)
	{
		return nullptr;
	}

	if (pPrimaryChild->hasSameLogic(pNegativeChild->getA()))
	{
		return Proposition::create<TautologyProposition>();
	}

	return nullptr;
}
//////////////////////////////////////////////////////////////////////////
EquivalenceRule19::EquivalenceRule19()
{

}

EquivalenceRule19::~EquivalenceRule19()
{

}

Proposition* EquivalenceRule19::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<ImplicateProposition>())
	{
		return nullptr;
	}

	ImplicateProposition* pTemp = proposition->as<ImplicateProposition>();
	if (pTemp->getA() == nullptr || pTemp->getB() == nullptr)
	{
		return nullptr;
	}

	NegativeProposition* p1 = Proposition::create<NegativeProposition>();
	p1->setA(pTemp->getA());

	DisjunctiveProposition* p0 = Proposition::create<DisjunctiveProposition>();
	p0->setA(p1);
	p0->setB(pTemp->getB());
	return p0;
}
//////////////////////////////////////////////////////////////////////////
EquivalenceRule20::EquivalenceRule20()
{

}

EquivalenceRule20::~EquivalenceRule20()
{

}

Proposition* EquivalenceRule20::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<ImplicateProposition>())
	{
		return nullptr;
	}

	ImplicateProposition* pTemp = proposition->as<ImplicateProposition>();
	if (pTemp->getA() == nullptr || pTemp->getB() == nullptr)
	{
		return nullptr;
	}

	NegativeProposition* p1 = Proposition::create<NegativeProposition>();
	p1->setA(pTemp->getB());

	NegativeProposition* p2 = Proposition::create<NegativeProposition>();
	p2->setA(pTemp->getA());

	ImplicateProposition* p0 = Proposition::create<ImplicateProposition>();
	p0->setA(p1);
	p0->setB(p2);

	return p0;
}
//////////////////////////////////////////////////////////////////////////

EquivalenceRule21::EquivalenceRule21()
{

}

EquivalenceRule21::~EquivalenceRule21()
{

}

Proposition* EquivalenceRule21::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<DisjunctiveProposition>())
	{
		return nullptr;
	}

	DisjunctiveProposition* pTemp = proposition->as<DisjunctiveProposition>();
	if (pTemp->getA() == nullptr || pTemp->getB() == nullptr)
	{
		return nullptr;
	}

	NegativeProposition* p1 = Proposition::create<NegativeProposition>();
	p1->setA(pTemp->getA());

	ImplicateProposition* p0 = Proposition::create<ImplicateProposition>();
	p0->setA(p1);
	p0->setB(pTemp->getB());

	return p0;
}
//////////////////////////////////////////////////////////////////////////
EquivalenceRule22::EquivalenceRule22()
{

}

EquivalenceRule22::~EquivalenceRule22()
{

}

Proposition* EquivalenceRule22::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<CombinedProposition>())
	{
		return nullptr;
	}

	CombinedProposition* pTemp = proposition->as<CombinedProposition>();
	if (pTemp->getA() == nullptr || pTemp->getB() == nullptr)
	{
		return nullptr;
	}

	NegativeProposition* p1 = Proposition::create<NegativeProposition>();
	p1->setA(pTemp->getB());

	ImplicateProposition* p2 = Proposition::create<ImplicateProposition>();
	p2->setA(pTemp->getA());
	p2->setB(p1);

	NegativeProposition* p0 = Proposition::create<NegativeProposition>();
	p0->setA(p2);

	return p0;
}
//////////////////////////////////////////////////////////////////////////
EquivalenceRule23::EquivalenceRule23()
{

}

EquivalenceRule23::~EquivalenceRule23()
{

}

Proposition* EquivalenceRule23::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<NegativeProposition>())
	{
		return nullptr;
	}

	NegativeProposition* pTemp = proposition->as<NegativeProposition>();
	if (pTemp->getA() == nullptr)
	{
		return nullptr;
	}

	if (!pTemp->getA()->is<ImplicateProposition>())
	{
		return nullptr;
	}

	ImplicateProposition* pChildTemp = pTemp->getA()->as<ImplicateProposition>();
	if (pChildTemp->getA() == nullptr || pChildTemp->getB() == nullptr)
	{
		return nullptr;
	}

	NegativeProposition* p1 = Proposition::create<NegativeProposition>();
	p1->setA(pChildTemp->getB());

	CombinedProposition* p0 = Proposition::create<CombinedProposition>();
	p0->setA(pChildTemp->getA());
	p0->setA(p1);

	return p0;
}

//////////////////////////////////////////////////////////////////////////
EquivalenceRule24::EquivalenceRule24()
{

}

EquivalenceRule24::~EquivalenceRule24()
{

}

Proposition* EquivalenceRule24::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<CombinedProposition>())
	{
		return nullptr;
	}

	CombinedProposition* pTemp = proposition->as<CombinedProposition>();
	if (pTemp->getA() == nullptr || pTemp->getB() == nullptr)
	{
		return nullptr;
	}

	ImplicateProposition* pLeftChild = pTemp->getA()->as<ImplicateProposition>();
	ImplicateProposition* pRightChild = pTemp->getB()->as<ImplicateProposition>();
	if (pLeftChild == nullptr || pRightChild == nullptr)
	{
		return nullptr;
	}

	if (!pLeftChild->getA()->hasSameLogic(pRightChild->getA()))
	{
		return nullptr;
	}

	CombinedProposition* p1 = Proposition::create<CombinedProposition>();
	p1->setA(pLeftChild->getB());
	p1->setB(pRightChild->getB());

	ImplicateProposition* p0 = Proposition::create<ImplicateProposition>();
	p0->setA(pLeftChild->getA());
	p0->setB(p1);

	return p0;
}

//////////////////////////////////////////////////////////////////////////
EquivalenceRule25::EquivalenceRule25()
{

}

EquivalenceRule25::~EquivalenceRule25()
{

}

Proposition* EquivalenceRule25::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<CombinedProposition>())
	{
		return nullptr;
	}

	CombinedProposition* pTemp = proposition->as<CombinedProposition>();
	if (pTemp->getA() == nullptr || pTemp->getB() == nullptr)
	{
		return nullptr;
	}

	ImplicateProposition* pLeftChild = pTemp->getA()->as<ImplicateProposition>();
	ImplicateProposition* pRightChild = pTemp->getB()->as<ImplicateProposition>();
	if (pLeftChild == nullptr || pRightChild == nullptr)
	{
		return nullptr;
	}

	if (!pLeftChild->getB()->hasSameLogic(pRightChild->getB()))
	{
		return nullptr;
	}

	DisjunctiveProposition* p1 = Proposition::create<DisjunctiveProposition>();
	p1->setA(pLeftChild->getA());
	p1->setB(pRightChild->getA());

	ImplicateProposition* p0 = Proposition::create<ImplicateProposition>();
	p0->setA(p1);
	p0->setB(pLeftChild->getB());

	return p0;
}

//////////////////////////////////////////////////////////////////////////

EquivalenceRule26::EquivalenceRule26()
{

}

EquivalenceRule26::~EquivalenceRule26()
{

}

Proposition* EquivalenceRule26::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<DisjunctiveProposition>())
	{
		return nullptr;
	}

	DisjunctiveProposition* pTemp = proposition->as<DisjunctiveProposition>();
	if (pTemp->getA() == nullptr || pTemp->getB() == nullptr)
	{
		return nullptr;
	}

	ImplicateProposition* pLeftChild = pTemp->getA()->as<ImplicateProposition>();
	ImplicateProposition* pRightChild = pTemp->getB()->as<ImplicateProposition>();
	if (pLeftChild == nullptr || pRightChild == nullptr)
	{
		return nullptr;
	}

	if (!pLeftChild->getA()->hasSameLogic(pRightChild->getA()))
	{
		return nullptr;
	}

	DisjunctiveProposition* p1 = Proposition::create<DisjunctiveProposition>();
	p1->setA(pLeftChild->getB());
	p1->setB(pRightChild->getB());

	ImplicateProposition* p0 = Proposition::create<ImplicateProposition>();
	p0->setA(pLeftChild->getA());
	p0->setB(p1);

	return p0;
}

//////////////////////////////////////////////////////////////////////////

EquivalenceRule27::EquivalenceRule27()
{

}

EquivalenceRule27::~EquivalenceRule27()
{

}

Proposition* EquivalenceRule27::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<DisjunctiveProposition>())
	{
		return nullptr;
	}

	DisjunctiveProposition* pTemp = proposition->as<DisjunctiveProposition>();
	if (pTemp->getA() == nullptr || pTemp->getB() == nullptr)
	{
		return nullptr;
	}

	ImplicateProposition* pLeftChild = pTemp->getA()->as<ImplicateProposition>();
	ImplicateProposition* pRightChild = pTemp->getB()->as<ImplicateProposition>();
	if (pLeftChild == nullptr || pRightChild == nullptr)
	{
		return nullptr;
	}

	if (!pLeftChild->getB()->hasSameLogic(pRightChild->getB()))
	{
		return nullptr;
	}

	CombinedProposition* p1 = Proposition::create<CombinedProposition>();
	p1->setA(pLeftChild->getA());
	p1->setB(pRightChild->getA());

	ImplicateProposition* p0 = Proposition::create<ImplicateProposition>();
	p0->setA(p1);
	p0->setB(pLeftChild->getB());

	return p0;
}
//////////////////////////////////////////////////////////////////////////
EquivalenceRule28::EquivalenceRule28()
{

}

EquivalenceRule28::~EquivalenceRule28()
{

}

Proposition* EquivalenceRule28::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<DoubleImplicateProposition>())
	{
		return nullptr;
	}

	DoubleImplicateProposition* pTemp = proposition->as<DoubleImplicateProposition>();
	if (pTemp->getA() == nullptr || pTemp->getB() == nullptr)
	{
		return nullptr;
	}

	ImplicateProposition* p1 = Proposition::create<ImplicateProposition>();
	p1->setA(pTemp->getA());
	p1->setB(pTemp->getB());

	ImplicateProposition* p2 = Proposition::create<ImplicateProposition>();
	p2->setA(pTemp->getB());
	p2->setB(pTemp->getA());

	CombinedProposition* p0 = Proposition::create<CombinedProposition>();
	p0->setA(p1);
	p0->setB(p2);

	return p0;
}

//////////////////////////////////////////////////////////////////////////
EquivalenceRule29::EquivalenceRule29()
{

}

EquivalenceRule29::~EquivalenceRule29()
{

}

Proposition* EquivalenceRule29::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<DoubleImplicateProposition>())
	{
		return nullptr;
	}

	DoubleImplicateProposition* pTemp = proposition->as<DoubleImplicateProposition>();
	if (pTemp->getA() == nullptr || pTemp->getB() == nullptr)
	{
		return nullptr;
	}

	NegativeProposition* p1 = Proposition::create<NegativeProposition>();
	p1->setA(pTemp->getA());

	NegativeProposition* p2 = Proposition::create<NegativeProposition>();
	p2->setA(pTemp->getB());

	DoubleImplicateProposition* p0 = Proposition::create<DoubleImplicateProposition>();
	p0->setA(p1);
	p0->setB(p2);

	return p0;
}
//////////////////////////////////////////////////////////////////////////
EquivalenceRule30::EquivalenceRule30()
{

}

EquivalenceRule30::~EquivalenceRule30()
{

}

Proposition* EquivalenceRule30::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<DoubleImplicateProposition>())
	{
		return nullptr;
	}

	DoubleImplicateProposition* pTemp = proposition->as<DoubleImplicateProposition>();
	if (pTemp->getA() == nullptr || pTemp->getB() == nullptr)
	{
		return nullptr;
	}

	CombinedProposition* p1 = Proposition::create<CombinedProposition>();
	p1->setA(pTemp->getA());
	p1->setA(pTemp->getB());

	NegativeProposition* p3 = Proposition::create<NegativeProposition>();
	p3->setA(pTemp->getA());
	NegativeProposition* p4 = Proposition::create<NegativeProposition>();
	p3->setA(pTemp->getB());

	CombinedProposition* p2 = Proposition::create<CombinedProposition>();
	p2->setA(p3);
	p2->setB(p4);

	DisjunctiveProposition* p0 = Proposition::create<DisjunctiveProposition>();
	p0->setA(p1);
	p0->setB(p2);

	return p0;
}
//////////////////////////////////////////////////////////////////////////

EquivalenceRule31::EquivalenceRule31()
{

}

EquivalenceRule31::~EquivalenceRule31()
{

}

Proposition* EquivalenceRule31::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<NegativeProposition>())
	{
		return nullptr;
	}

	NegativeProposition* pTemp = proposition->as<NegativeProposition>();
	if (pTemp->getA() == nullptr)
	{
		return nullptr;
	}

	if (!pTemp->getA()->is<DoubleImplicateProposition>())
	{
		return nullptr;
	}

	DoubleImplicateProposition* pChildTemp = pTemp->getA()->as<DoubleImplicateProposition>();
	if (pChildTemp->getA() == nullptr || pChildTemp->getB() == nullptr)
	{
		return nullptr;
	}

	NegativeProposition* p1 = Proposition::create<NegativeProposition>();
	p1->setA(pChildTemp->getB());

	DoubleImplicateProposition* p0 = Proposition::create<DoubleImplicateProposition>();
	p0->setA(pChildTemp->getA());
	p0->setB(p1);

	return p0;
}

//////////////////////////////////////////////////////////////////////////
EquivalenceRule32::EquivalenceRule32()
{

}

EquivalenceRule32::~EquivalenceRule32()
{

}

Proposition* EquivalenceRule32::GetEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	if (!proposition->is<DoubleImplicateProposition>())
	{
		return nullptr;
	}

	DoubleImplicateProposition* pTemp = proposition->as<DoubleImplicateProposition>();
	if (pTemp->getA() == nullptr || pTemp->getB() == nullptr)
	{
		return nullptr;
	}

	DoubleImplicateProposition* p0 = Proposition::create<DoubleImplicateProposition>();
	p0->setA(pTemp->getB());
	p0->setB(pTemp->getA());

	return p0;
}
