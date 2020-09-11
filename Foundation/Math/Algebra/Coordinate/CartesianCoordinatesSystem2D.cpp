#include "CartesianCoordinatesSystem2D.h"

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