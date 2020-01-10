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
	PrimaryProposition a(PropositionResult::TRUE);
	a.setIdentify(1);

	PrimaryProposition b(PropositionResult::FALSE);
	b.setIdentify(2);

	DisjunctiveProposition c(&a, &b);
	c.setIdentify(3);

	int dfd = 1;
}


int main(int argc, char** argv)
{
	testInference();

	return 0;
}