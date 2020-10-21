#include "CartesianCoordinateSystem2D.h"

math::CartesianCoordinateSystem2D::CartesianCoordinateSystem2D()
{
	this->loadIdentity();
}

math::CartesianCoordinateSystem2D::~CartesianCoordinateSystem2D()
{

}

void math::CartesianCoordinateSystem2D::loadIdentity()
{
	_systemMatrix.reset();
	_systemMatrix[0] = 1;
	_systemMatrix[3] = 1;
}