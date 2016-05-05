#include "CtrlSpotLight.h"

using namespace render;


CtrlSpotLight::CtrlSpotLight()
{
	_spotExponent = 0.0f;
	_spotCutOff = 180.0;
	_spotDirection[0] = 0.0f;
	_spotDirection[1] = 0.0f;
	_spotDirection[2] = -1.0f;

	_constantAttenuation = 1.0f;
	_linearAttenuation = 0.0f;
	_quadraticAttenuation = 0.0f;
}

CtrlSpotLight::~CtrlSpotLight()
{

}

void CtrlSpotLight::draw()
{
	CtrlLight::draw();

	glLightfv(getLightIndex(), GL_SPOT_DIRECTION, _spotDirection);
	glLightfv(getLightIndex(), GL_SPOT_EXPONENT, &_spotExponent);
	glLightfv(getLightIndex(), GL_SPOT_CUTOFF, &_spotCutOff);
	glLightfv(getLightIndex(), GL_CONSTANT_ATTENUATION, &_constantAttenuation);
	glLightfv(getLightIndex(), GL_LINEAR_ATTENUATION, &_linearAttenuation);
	glLightfv(getLightIndex(), GL_QUADRATIC_ATTENUATION, &_quadraticAttenuation);
}

void CtrlSpotLight::setExponent(float value)
{
	_spotExponent = value;
}

float CtrlSpotLight::getExponent()
{
	return _spotExponent;
}

void CtrlSpotLight::setCutOff(float value)
{
	_spotCutOff = value;
}

float CtrlSpotLight::getCutOff()
{
	return _spotCutOff;
}

void CtrlSpotLight::setDirection(float x, float y, float z)
{
	_spotDirection[0] = x;
	_spotDirection[1] = y;
	_spotDirection[2] = z;
}

const float* CtrlSpotLight::getDirection()
{
	return _spotDirection;
}

void CtrlSpotLight::setConstantAttenuation(float value)
{
	_constantAttenuation = value;
}

float CtrlSpotLight::getConstantAttenuation()
{
	return _constantAttenuation;
}

void CtrlSpotLight::setLinearAttenuation(float value)
{
	_linearAttenuation = value;
}

float CtrlSpotLight::getLinearAttenuation()
{
	return _linearAttenuation;
}

void CtrlSpotLight::setQuadraticAttenuation(float value)
{
	_quadraticAttenuation = value;
}

float CtrlSpotLight::getQuadraticAttenuation()
{
	return _quadraticAttenuation;
}
