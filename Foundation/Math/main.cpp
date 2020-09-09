#include "Algebra/import.h"
#include "Geometry/import.h"
#include "Discrete/PropositionLogic/import.h"
#include <iostream>

using namespace math;

template<int A, int B>
struct classA
{
	int getValue()
	{
		return A * A + B * B;
	}
};

template<int C>
struct classB : public classA <C, C>
{

};

void testMatrix()
{
	float value32[6] = {
		1, 2,
		3, 4,
		5, 6
	};
	Matrix<float, 3, 2> mat32(value32);

	float value23[6] = {
		1, 2, 3, 
		4, 5, 6
	};
	Matrix<float, 2, 3> mat23(value32);

	//Matrix<3, 3> mat33 = mat32 * mat23;
	float value33[9] = { 0 };
	//mat33.getValue(value33, 9);

	int a = 1;

	Matrix1x4 mat14;
	Matrix2x2 mat22;
	Matrix3x3 mat33;
	Matrix4x1 mat41;
	Matrix4x4 mat44;

	Vector2 vec2;
	Vector3 vec3;
	Vector4 vec4;

	vec2.setX(vec3.getX());

	Quaternion quaternion;

	Determinant2 det2;
	Determinant3 det3;
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
	int a = 1;
	math::CartesianCoordinatesSystem3D system;
	system.loadIdentity();

	math::Array2D<float, 2, 2> value(1.0f, 3.0f, 4.0f, 5.0f);
	return 0;
}