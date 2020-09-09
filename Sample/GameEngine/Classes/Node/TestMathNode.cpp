#include "TestMathNode.h"
#include "mathlib.h"

TestMathNode::TestMathNode()
{

}

TestMathNode::~TestMathNode()
{

}

void TestMathNode::initNodes()
{
	testMath();
}

void TestMathNode::testMath()
{
	math::CartesianCoordinatesSystem3D system;
	system.loadIdentity();

	math::Array2D<float, 2, 2> value(1.0f, 3.0f, 4.0f, 5.0f);

	int a = 1;
}

