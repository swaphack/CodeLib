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
	testMatrix();
}

void TestMathNode::testMath()
{
	math::CartesianCoordinateSystem3D system;
	system.loadIdentity();

	math::Array2D<float, 2, 2> value(1.0f, 3.0f, 4.0f, 5.0f);

	int a = 1;
}

void TestMathNode::testMatrix()
{
	float data2x2[4] = {
		1, 2,
		-1, -3
	};


	math::Matrix2x2 mat22(data2x2);
	PRINT("src:\n%s\n", mat22.toString().c_str());
	math::Matrix<float, 2, 2> inverse22 = mat22.getInverse();
	PRINT("transpose:\n%s\n", inverse22.toString().c_str());
	math::Matrix<float, 2, 2> mul22 = mat22 * inverse22;
	PRINT("mul:\n%s\n", mul22.toString().c_str());

	//math::Matrix<float, 2, 2> inverse221 = mat22.getInverseMatrix();
	//math::Matrix<float, 2, 2> mul221 = mat22 * inverse221;
	//PRINT("mul:\n%s\n", mul221.toString().c_str());

	float data3x3[9] = {
		1, 2, 3,
		3, 2, 1,
		1, 4, 5
	};


	math::Matrix3x3 mat33(data3x3);
	PRINT("src:\n%s\n", mat33.toString().c_str());
	math::Matrix<float, 3, 3> inverse33 = mat33.getInverse();
	PRINT("transpose:\n%s\n", inverse33.toString().c_str());

	math::Matrix<float, 3, 3> mul33 = mat33 * inverse33;
	PRINT("mul:\n%s\n", mul33.toString().c_str());
}

