#include "DirectionLight.h"

render::DirectionLight::DirectionLight()
{
	_lightDirection[0] = 0.0f;
	_lightDirection[1] = 0.0f;
	_lightDirection[2] = 1.0f;
}

render::DirectionLight::~DirectionLight()
{

}

void render::DirectionLight::draw()
{
	Light::draw();
}

bool render::DirectionLight::init()
{
	if (!Light::init())
	{
		return false;
	}

	return true;
}

const float* render::DirectionLight::getDirection()
{
	return _lightDirection;
}

void render::DirectionLight::setDirection(const math::Vector3& direction)
{
	memcpy(_lightDirection, direction.getValue(), sizeof(_lightDirection));
}

void render::DirectionLight::setDirection(float x, float y, float z)
{
	_lightDirection[0] = x;
	_lightDirection[1] = y;
	_lightDirection[2] = z;
}

