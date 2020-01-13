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
	auto a = Proposition::create<PrimaryProposition>(1, PropositionResult::TRUE);
	auto b = Proposition::create<PrimaryProposition>(2, PropositionResult::FALSE);
	auto c = Proposition::create<DisjunctiveProposition>(a, b);
	auto d = Proposition::create<NegativeProposition>(c);

	auto rule = new EquivalenceRule();
	rule->init();

	auto result = rule->getEquivalenceProposition(d);

	int sdfs = 0;
}


int main(int argc, char** argv)
{
	testInference();

	return 0;
}