#include "Light.h"
#include "Graphic/GLAPI/import.h"

using namespace render;

Light::Light()
{
	_lightAmbient[0] = 0.0f;
	_lightAmbient[1] = 0.0f;
	_lightAmbient[2] = 0.0f;
	_lightAmbient[3] = 1.0f;

	_lightDiffuse[0] = 1.0f;
	_lightDiffuse[1] = 1.0f;
	_lightDiffuse[2] = 1.0f;
	_lightDiffuse[3] = 1.0f;

	_lightSpecular[0] = 1.0f;
	_lightSpecular[1] = 1.0f;
	_lightSpecular[2] = 1.0f;
	_lightSpecular[3] = 1.0f;

	_lightPosition[0] = 0.0f;
	_lightPosition[1] = 0.0f;
	_lightPosition[2] = 1.0f;
	_lightPosition[3] = 0.0f;

}

Light::~Light()
{

}

void Light::draw()
{
	GLLight::setLightAmbient(getLightName(), _lightAmbient);

	GLLight::setLightDiffuse(getLightName(), _lightDiffuse);

	GLLight::setLightSpecular(getLightName(), _lightSpecular);

	GLLight::setLightPosition(getLightName(), _lightPosition);

	GLState::enable(EnableModel::LIGHTING);
	GLState::enable((EnableModel)getLightName());
}

void Light::setAmbient(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	_lightAmbient[0] = red / COLOR_FLOAT_VALUE;
	_lightAmbient[1] = green / COLOR_FLOAT_VALUE;
	_lightAmbient[2] = blue / COLOR_FLOAT_VALUE;
	_lightAmbient[3] = alpha / COLOR_FLOAT_VALUE;
}

const float* Light::getAmbient()
{
	return _lightAmbient;
}

void Light::setDiffuse(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	_lightDiffuse[0] = red / COLOR_FLOAT_VALUE;
	_lightDiffuse[1] = green / COLOR_FLOAT_VALUE;
	_lightDiffuse[2] = blue / COLOR_FLOAT_VALUE;
	_lightDiffuse[3] = alpha / COLOR_FLOAT_VALUE;
}

const float* Light::getDiffuse()
{
	return _lightDiffuse;
}

void Light::setSpecular(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	_lightSpecular[0] = red / COLOR_FLOAT_VALUE;
	_lightSpecular[1] = green / COLOR_FLOAT_VALUE;
	_lightSpecular[2] = blue / COLOR_FLOAT_VALUE;
	_lightSpecular[3] = alpha / COLOR_FLOAT_VALUE;
}

const float* Light::getSpecular()
{
	return _lightSpecular;
}

void Light::onLightPositionChange()
{
	_lightPosition[0] = _obPosition.getX();
	_lightPosition[1] = _obPosition.getY();
	_lightPosition[2] = _obPosition.getZ();
}

bool Light::init()
{
	if (!Node::init())
	{
		return false;
	}

	_notify->addListen(ENP_SPACE, [&](){
		this->onLightPositionChange();
	});

	return true;
}
