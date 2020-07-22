#include "SpotLight.h"
#include "Graphic/import.h"

using namespace render;


SpotLight::SpotLight()
{
	_spotExponent = 0.0f;
	_spotCutOff = 180.0;
}

SpotLight::~SpotLight()
{

}

void SpotLight::draw()
{
	PointLight::draw();

	GLLight::setLightSpotDirection(getLightName(), _lightDirection);
	GLLight::setLightSpotExponent(getLightName(), _spotExponent);
	GLLight::setLightSpotCutOff(getLightName(), _spotCutOff);
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