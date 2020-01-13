#include "Algebra/Matrix.h"
#include "Geometry/base/Matrix22.h"
#include "Discrete/PropositionLogic/import.h"
#include <iostream>

using namespace math;

void testMatrix()
{
	Matrix22 mat = Matrix22(
		1, 5,
		6, 7);
	printf("%s", mat.toString().c_str());
}

void testInference()
{
	PrimaryProposition* a = Proposition::createProposition<PrimaryProposition>();
	a->setResult(PropositionResult::TRUE);
	a->setLogicID(1);

	PrimaryProposition* b = Proposition::createProposition<PrimaryProposition>();
	b->setResult(PropositionResult::FALSE);
	b->setLogicID(2);

	DisjunctiveProposition* c = Proposition::createProposition<DisjunctiveProposition>();
	c->setA(a);
	c->setB(b);

	NegativeProposition* d = Proposition::createProposition<NegativeProposition>();
	d->setA(c);


	EquivalenceRule* rule = new EquivalenceRule();
	rule->init();

	auto result = rule->getEquivalenceProposition(d);

	int sdfs = 0;
}


int main(int argc, char** argv)
{
	testInference();

	return 0;
}