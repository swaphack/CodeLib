#include "Algebra/Matrix.h"
#include "Geometry/base/Matrix22.h"
#include "Discrete/PropositionLogic/import.h"
#include <iostream>

using namespace math;

void testMatrix()
{
	float value32[6] = {
		1, 2,
		3, 4,
		5, 6
	};
	Matrix mat32(value32, 3, 2);

	float value23[6] = {
		1, 2, 3, 
		4, 5, 6
	};
	Matrix mat23(value32, 2, 3);

	Matrix mat33 = mat32 * mat23;
	float value33[9] = { 0 };
	mat33.getValue(value33, 9);

	int a = 1;
}

void testInference()
{
	// !(a->b)
	auto a = Proposition::create<PrimaryProposition>(1, PropositionResult::TRUE);
	auto b = Proposition::create<PrimaryProposition>(2, PropositionResult::TRUE);

	auto c = Proposition::create<ImplicateProposition>(a, b);
	auto d = Proposition::create<NegativeProposition>(c);

	auto rule = new EquivalenceRule();
	rule->init();

	auto result = rule->getEquivalenceProposition(d);

	int sdfs = 0;
}


int main(int argc, char** argv)
{
	testMatrix();

	return 0;
}