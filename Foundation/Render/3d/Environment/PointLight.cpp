#include "PointLight.h"
#include "Graphic/import.h"

render::PointLight::PointLight()
{
	_constantAttenuation = 1.0f;
	_linearAttenuation = 0.0f;
	_quadraticAttenuation = 0.0f;
}

render::PointLight::~PointLight()
{

}

void render::PointLight::draw()
{
	Light::draw();

	GLLight::setLightConstantAttenuation(getLightName(), _constantAttenuation);
	GLLight::setLightLinearAttenuation(getLightName(), _linearAttenuation);
	GLLight::setLightQuadraticAttenuation(getLightName(), _quadraticAttenuation);
}

void render::PointLight::setConstantAttenuation(float value)
{
	_constantAttenuation = value;
}

float render::PointLight::getConstantAttenuation()
{
	return _constantAttenuation;
}

void render::PointLight::setLinearAttenuation(float value)
{
	_linearAttenuation = value;
}

float render::PointLight::getLinearAttenuation()
{
	return _linearAttenuation;
}

void render::PointLight::setQuadraticAttenuation(float value)
{
	_quadraticAttenuation = value;
}

float render::PointLight::getQuadraticAttenuation()
{
	return _quadraticAttenuation;
}

