#include "Coordinates.h"

using namespace math;


Coordinates::Coordinates()
:_rotationX(0)
, _rotationY(0)
, _rotationZ(0)
, _angelX(0)
, _angelY(0)
, _angelZ(0)
{

}

Coordinates::~Coordinates()
{

}

void Coordinates::setRotationX(float rotation)
{
	_rotationX = rotation;
}

float Coordinates::getRotaionX()
{
	return _rotationX;
}

void Coordinates::setRotationY(float rotation)
{
	_rotationY = rotation;
}

float Coordinates::getRotaionY()
{
	return _rotationY;
}

void Coordinates::setRotationZ(float rotation)
{
	_rotationZ = rotation;
}

float Coordinates::getRotaionZ()
{
	return _rotationZ;
}

void Coordinates::setAngleX(float angle)
{
	_angelX = angle;
}

float Coordinates::getAngleX()
{
	return _angelX;
}

void Coordinates::setAngleY(float angle)
{
	_angelY = angle;
}

float Coordinates::getAngleY()
{
	return _angelY;
}

void Coordinates::setAngleZ(float angle)
{
	_angelZ = angle;
}

float Coordinates::getAngleZ()
{
	return _angelZ;
}
