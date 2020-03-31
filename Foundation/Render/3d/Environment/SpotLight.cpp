#include "SpotLight.h"
#include "Graphic/import.h"

using namespace render;


SpotLight::SpotLight()
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

SpotLight::~SpotLight()
{

}

void SpotLight::draw()
{
	Light::draw();

	GLLight::setLightSpotDirection(getLightName(), _spotDirection);
	GLLight::setLightSpotExponent(getLightName(), _spotExponent);
	GLLight::setLightSpotCutOff(getLightName(), _spotCutOff);
	GLLight::setLightConstantAttenuation(getLightName(), _constantAttenuation);
	GLLight::setLightLinearAttenuation(getLightName(), _linearAttenuation);
	GLLight::setLightQuadraticAttenuation(getLightName(), _quadraticAttenuation);
}

void SpotLight::setExponent(float value)
{
	_spotExponent = value;
}

float SpotLight::getExponent()
{
	return _spotExponent;
}

void SpotLight::setCutOff(float value)
{
	_spotCutOff = value;
}

float SpotLight::getCutOff()
{
	return _spotCutOff;
}

void SpotLight::setDirection(float x, float y, float z)
{
	_spotDirection[0] = x;
	_spotDirection[1] = y;
	_spotDirection[2] = z;
}

const float* SpotLight::getDirection()
{
	return _spotDirection;
}

void SpotLight::setConstantAttenuation(float value)
{
	_constantAttenuation = value;
}

float SpotLight::getConstantAttenuation()
{
	return _constantAttenuation;
}

void SpotLight::setLinearAttenuation(float value)
{
	_linearAttenuation = value;
}

float SpotLight::getLinearAttenuation()
{
	return _linearAttenuation;
}

void SpotLight::setQuadraticAttenuation(float value)
{
	_quadraticAttenuation = value;
}

float SpotLight::getQuadraticAttenuation()
{
	return _quadraticAttenuation;
}
