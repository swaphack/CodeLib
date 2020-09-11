#include "CartesianCoordinatesSystem4D.h"

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