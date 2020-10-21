#include "CartesianCoordinateSystem4D.h"

math::CartesianCoordinateSystem4D::CartesianCoordinateSystem4D()
{
	this->loadIdentity();
}

math::CartesianCoordinateSystem4D::~CartesianCoordinateSystem4D()
{

}

void math::CartesianCoordinateSystem4D::loadIdentity()
{
	_systemMatrix.reset();
	_systemMatrix[0] = 1;
	_systemMatrix[5] = 1;
	_systemMatrix[10] = 1;
	_systemMatrix[15] = 1;
}