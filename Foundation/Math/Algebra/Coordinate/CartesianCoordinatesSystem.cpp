#include "CartesianCoordinatesSystem.h"
#include "Algebra/Determinant/Determinant.h"

math::CartesianCoordinatesSystem2D::CartesianCoordinatesSystem2D()
{
	this->loadIdentity();
}

math::CartesianCoordinatesSystem2D::~CartesianCoordinatesSystem2D()
{

}

void math::CartesianCoordinatesSystem2D::loadIdentity()
{
	_systemMatrix.reset();
	_systemMatrix[0] = 1;
	_systemMatrix[3] = 1;
}

//////////////////////////////////////////////////////////////////////////


math::CartesianCoordinatesSystem3D::CartesianCoordinatesSystem3D()
{
	this->loadIdentity();
}

math::CartesianCoordinatesSystem3D::~CartesianCoordinatesSystem3D()
{

}

void math::CartesianCoordinatesSystem3D::loadIdentity()
{
	_systemMatrix.reset();
	_systemMatrix[0] = 1;
	_systemMatrix[4] = 1;
	_systemMatrix[8] = 1;
}

math::CartesianCoordinatesSystem3D math::CartesianCoordinatesSystem3D::create(const Vector3& point, Axis3D eAxis, const Vector3& vector)
{
	math::CartesianCoordinatesSystem3D system;
	if (Vector3(0, 0) == vector)
	{
		return system;
	}
	
	float d = fabs(vector.getX()) + fabs(vector.getX());

	Vector3 va = vector;
	Vector3 vb;
	Vector3 vc;

	if (d > 0)
	{
		d = sqrt(va.getX() * va.getX() + va.getY() * va.getY());
		vb.setX(-va.getY() / d);
		vb.setY(va.getX() / d);
		vb.setZ(0);
	}
	else
	{
		vb.setX(1.0f);
		vb.setY(0);
		vb.setZ(0);

	}

	Array2D<float, 2, 2> valX(va.getY(), va.getZ(), vb.getY(), vb.getZ());
	Array2D<float, 2, 2> valY(va.getX(), va.getZ(), vb.getX(), vb.getZ());
	Array2D<float, 2, 2> valZ(va.getX(), va.getY(), vb.getX(), vb.getY());

	vc.setX(getDetMagnitude(valX));
	vc.setY(getDetMagnitude(valY));
	vc.setZ(getDetMagnitude(valZ));

	return system;
}

//////////////////////////////////////////////////////////////////////////

math::CartesianCoordinatesSystem4D::CartesianCoordinatesSystem4D()
{
	this->loadIdentity();
}

math::CartesianCoordinatesSystem4D::~CartesianCoordinatesSystem4D()
{

}

void math::CartesianCoordinatesSystem4D::loadIdentity()
{
	_systemMatrix.reset();
	_systemMatrix[0] = 1;
	_systemMatrix[5] = 1;
	_systemMatrix[10] = 1;
	_systemMatrix[15] = 1;
}
