#include "Light.h"

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
	Node::draw();
	if (getLightIndex() == ELI_NONE)
	{
		return;
	}

	glLightfv(getLightIndex(), GL_AMBIENT, _lightAmbient);

	glLightfv(getLightIndex(), GL_DIFFUSE, _lightDiffuse);

	glLightfv(getLightIndex(), GL_SPECULAR, _lightSpecular);

	glLightfv(getLightIndex(), GL_POSITION, _lightPosition);

	glEnable(GL_LIGHTING);

	glEnable(getLightIndex());
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

void Light::initSelf()
{
	Node::initSelf();

	_lightPosition[0] = _obPosition.getX();
	_lightPosition[1] = _obPosition.getY();
	_lightPosition[2] = _obPosition.getZ();
}