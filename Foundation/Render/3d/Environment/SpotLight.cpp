#include "SpotLight.h"
#include "Graphic/import.h"

using namespace render;


SpotLight::SpotLight()
{
	_spotExponent = 0.0f;
	_spotCutOff = 180.0;

	_lightDirection[0] = 0.0f;
	_lightDirection[1] = 0.0f;
	_lightDirection[2] = 1.0f;
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

bool render::SpotLight::init()
{
	if (!PointLight::init())
	{
		return false;
	}

	addNotifyListener(NodeNotifyType::SPACE, [this]() {
		math::Quaternion q = math::Quaternion::rotate(getRotation());
		_lightDirection[0] = q.getX() / q.getW();
		_lightDirection[1] = q.getY() / q.getW();
		_lightDirection[2] = q.getZ() / q.getW();
	});

	return true;
}

const float* render::SpotLight::getDirection()
{
	return _lightDirection;
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