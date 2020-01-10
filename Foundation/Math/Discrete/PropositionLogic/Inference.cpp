#include "Inference.h"

using namespace math;

Inference::Inference()
{

}

Inference::~Inference()
{

}

CompoundProposition* Inference::createNegativeProposition(Proposition* a)
{
	NegativeProposition* np = this->createNode<NegativeProposition>();
	np->setA(a);
	return np;
}

CompoundProposition* Inference::createDisjunctiveProposition(Proposition* a, Proposition* b)
{
	DisjunctiveProposition* np = this->createNode<DisjunctiveProposition>();
	np->setA(a);
	np->setB(b);
	return np;
}

CompoundProposition* Inference::createCombinedProposition(Proposition* a, Proposition* b)
{
	CombinedProposition* np = this->createNode<CombinedProposition>();
	np->setA(a);
	np->setB(b);
	return np;
}
