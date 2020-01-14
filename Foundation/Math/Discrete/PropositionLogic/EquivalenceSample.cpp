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

Proposition* EquivalenceSample::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample0::EquivalenceSample0()
{

}

EquivalenceSample0::~EquivalenceSample0()
{

}

Proposition* EquivalenceSample0::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample1::EquivalenceSample1()
{

}

EquivalenceSample1::~EquivalenceSample1()
{

}

Proposition* EquivalenceSample1::getEquivalenceProposition(CompoundProposition* proposition)
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

EquivalenceSample2::EquivalenceSample2()
{

}

EquivalenceSample2::~EquivalenceSample2()
{

}

Proposition* EquivalenceSample2::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample3::EquivalenceSample3()
{

}

EquivalenceSample3::~EquivalenceSample3()
{

}

Proposition* EquivalenceSample3::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample4::EquivalenceSample4()
{

}

EquivalenceSample4::~EquivalenceSample4()
{

}

Proposition* EquivalenceSample4::getEquivalenceProposition(CompoundProposition* proposition)
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

EquivalenceSample5::EquivalenceSample5()
{

}

EquivalenceSample5::~EquivalenceSample5()
{

}

Proposition* EquivalenceSample5::getEquivalenceProposition(CompoundProposition* proposition)
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

EquivalenceSample6::EquivalenceSample6()
{

}

EquivalenceSample6::~EquivalenceSample6()
{

}

Proposition* EquivalenceSample6::getEquivalenceProposition(CompoundProposition* proposition)
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


EquivalenceSample7::EquivalenceSample7()
{

}

EquivalenceSample7::~EquivalenceSample7()
{

}

Proposition* EquivalenceSample7::getEquivalenceProposition(CompoundProposition* proposition)
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


EquivalenceSample8::EquivalenceSample8()
{

}

EquivalenceSample8::~EquivalenceSample8()
{

}

Proposition* EquivalenceSample8::getEquivalenceProposition(CompoundProposition* proposition)
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

EquivalenceSample9::EquivalenceSample9()
{

}

EquivalenceSample9::~EquivalenceSample9()
{

}

Proposition* EquivalenceSample9::getEquivalenceProposition(CompoundProposition* proposition)
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

EquivalenceSample33::EquivalenceSample33()
{

}

EquivalenceSample33::~EquivalenceSample33()
{

}

Proposition* EquivalenceSample33::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample10::EquivalenceSample10()
{

}

EquivalenceSample10::~EquivalenceSample10()
{

}

Proposition* EquivalenceSample10::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample34::EquivalenceSample34()
{

}

EquivalenceSample34::~EquivalenceSample34()
{

}

Proposition* EquivalenceSample34::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample11::EquivalenceSample11()
{

}

EquivalenceSample11::~EquivalenceSample11()
{

}

Proposition* EquivalenceSample11::getEquivalenceProposition(CompoundProposition* proposition)
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


EquivalenceSample12::EquivalenceSample12()
{

}

EquivalenceSample12::~EquivalenceSample12()
{

}

Proposition* EquivalenceSample12::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample13::EquivalenceSample13()
{

}

EquivalenceSample13::~EquivalenceSample13()
{

}

Proposition* EquivalenceSample13::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample14::EquivalenceSample14()
{

}

EquivalenceSample14::~EquivalenceSample14()
{

}

Proposition* EquivalenceSample14::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample15::EquivalenceSample15()
{

}

EquivalenceSample15::~EquivalenceSample15()
{

}

Proposition* EquivalenceSample15::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample16::EquivalenceSample16()
{

}

EquivalenceSample16::~EquivalenceSample16()
{

}

Proposition* EquivalenceSample16::getEquivalenceProposition(CompoundProposition* proposition)
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


EquivalenceSample17::EquivalenceSample17()
{

}

EquivalenceSample17::~EquivalenceSample17()
{

}

Proposition* EquivalenceSample17::getEquivalenceProposition(CompoundProposition* proposition)
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


EquivalenceSample18::EquivalenceSample18()
{

}

EquivalenceSample18::~EquivalenceSample18()
{

}

Proposition* EquivalenceSample18::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample19::EquivalenceSample19()
{

}

EquivalenceSample19::~EquivalenceSample19()
{

}

Proposition* EquivalenceSample19::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample20::EquivalenceSample20()
{

}

EquivalenceSample20::~EquivalenceSample20()
{

}

Proposition* EquivalenceSample20::getEquivalenceProposition(CompoundProposition* proposition)
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

EquivalenceSample21::EquivalenceSample21()
{

}

EquivalenceSample21::~EquivalenceSample21()
{

}

Proposition* EquivalenceSample21::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample22::EquivalenceSample22()
{

}

EquivalenceSample22::~EquivalenceSample22()
{

}

Proposition* EquivalenceSample22::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample23::EquivalenceSample23()
{

}

EquivalenceSample23::~EquivalenceSample23()
{

}

Proposition* EquivalenceSample23::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample24::EquivalenceSample24()
{

}

EquivalenceSample24::~EquivalenceSample24()
{

}

Proposition* EquivalenceSample24::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample25::EquivalenceSample25()
{

}

EquivalenceSample25::~EquivalenceSample25()
{

}

Proposition* EquivalenceSample25::getEquivalenceProposition(CompoundProposition* proposition)
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

EquivalenceSample26::EquivalenceSample26()
{

}

EquivalenceSample26::~EquivalenceSample26()
{

}

Proposition* EquivalenceSample26::getEquivalenceProposition(CompoundProposition* proposition)
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

EquivalenceSample27::EquivalenceSample27()
{

}

EquivalenceSample27::~EquivalenceSample27()
{

}

Proposition* EquivalenceSample27::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample28::EquivalenceSample28()
{

}

EquivalenceSample28::~EquivalenceSample28()
{

}

Proposition* EquivalenceSample28::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample29::EquivalenceSample29()
{

}

EquivalenceSample29::~EquivalenceSample29()
{

}

Proposition* EquivalenceSample29::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample30::EquivalenceSample30()
{

}

EquivalenceSample30::~EquivalenceSample30()
{

}

Proposition* EquivalenceSample30::getEquivalenceProposition(CompoundProposition* proposition)
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

EquivalenceSample31::EquivalenceSample31()
{

}

EquivalenceSample31::~EquivalenceSample31()
{

}

Proposition* EquivalenceSample31::getEquivalenceProposition(CompoundProposition* proposition)
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
EquivalenceSample32::EquivalenceSample32()
{

}

EquivalenceSample32::~EquivalenceSample32()
{

}

Proposition* EquivalenceSample32::getEquivalenceProposition(CompoundProposition* proposition)
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
