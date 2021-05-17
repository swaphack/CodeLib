#include "Light.h"
#include "Graphic/GLAPI/import.h"
#include "Environment.h"
#include "PostProcessing/ShadowMapping.h"
#include "mathlib.h"

using namespace render;

Light::Light()
{
	_lightAmbient[0] = 0.5f;
	_lightAmbient[1] = 0.5f;
	_lightAmbient[2] = 0.5f;
	_lightAmbient[3] = 1.0f;

	_lightDiffuse[0] = 1.0f;
	_lightDiffuse[1] = 1.0f;
	_lightDiffuse[2] = 1.0f;
	_lightDiffuse[3] = 1.0f;

	_lightSpecular[0] = 1.0f;
	_lightSpecular[1] = 1.0f;
	_lightSpecular[2] = 1.0f;
	_lightSpecular[3] = 1.0f;

	_lightColor[0] = 1.0f;
	_lightColor[1] = 1.0f;
	_lightColor[2] = 1.0f;
	_lightColor[3] = 1.0f;

	

	G_ENVIRONMENT->addLight(this);
}

Light::~Light()
{
	G_ENVIRONMENT->removeLight(this);
}

void Light::draw()
{
	GLState::enable(EnableMode::LIGHTING);

	GLState::enable((EnableMode)getLightName());

	GLLight::setLightAmbient(getLightName(), _lightAmbient);

	GLLight::setLightDiffuse(getLightName(), _lightDiffuse);

	GLLight::setLightSpecular(getLightName(), _lightSpecular);

	GLLight::setLightPosition(getLightName(), _worldMatrix.getPosition().getValue());
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

bool Light::init()
{
	if (!Node::init())
	{
		return false;
	}

	return true;
}

LightName render::Light::getLightName()
{
	return (LightName)((int)LightName::LIGHT0 + _lightIndex);
}

void render::Light::setLightIndex(int index)
{
	ASSERT(index >= 0 || index <= getLightMaxCount());
	_lightIndex = index;
}

int render::Light::getLightIndex()
{
	return _lightIndex;
}

int render::Light::getLightMaxCount()
{
	return (int)LightName::LIGHT7 - (int)LightName::LIGHT0;
}

void render::Light::setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	_lightColor[0] = red / COLOR_FLOAT_VALUE;
	_lightColor[1] = green / COLOR_FLOAT_VALUE;
	_lightColor[2] = blue / COLOR_FLOAT_VALUE;
	_lightColor[3] = alpha / COLOR_FLOAT_VALUE;
}

const float* render::Light::getColor()
{
	return _lightColor;
}
