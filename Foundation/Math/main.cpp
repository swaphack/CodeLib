#include "Algebra/Matrix.h"
#include "Algebra/Vector3.h"

#include <iostream>

using namespace math;

int main(int argc, char** argv)
{
	Vector3 src(1, 1, 1);

	Vector3 offsetPosition(0, 1, 0);
	Vector3 offsetScale(0.5f, 1.0f, 0.0f);

	Vector3 dest0 = src.tranlate(offsetPosition);
	Vector3 dest1 = src.scale(offsetScale);

	return 0;
}