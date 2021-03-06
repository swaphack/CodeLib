#include "Fog.h"
#include "Common/Tool/Tool.h"
#include "Graphic/import.h"
using namespace render;

Fog::Fog()
:_near(0.0f)
, _far(1.0f)
, _fogMode(FogMode::LINEAR)
, _fogEffect(HintMode::NICEST)
, _density(1.0f)
{

}

Fog::~Fog()
{

}

void Fog::onDraw()
{
	float nearValue = _near / Tool::getGLViewSize().getDepth();
	float farValue = _far / Tool::getGLViewSize().getDepth();

	GLState::enable(EnableMode::FOG);
	GLState::setFogHint(_fogEffect);
	GLFog::setFogMode(_fogMode);
	GLFog::setFogColor(_fogColor);
	GLFog::setFogDensity(_density);
	GLFog::setFogStart(nearValue);
	GLFog::setFogEnd(farValue);
}

float Fog::getNear() const
{
	return _near;
}

void Fog::setNear(float val)
{
	_near = val;
}

float Fog::getFar() const
{
	return _far;
}

void Fog::setFar(float val)
{
	_far = val;
}

FogMode Fog::getFogMode() const
{
	return _fogMode;
}

void Fog::setFogMode(FogMode val)
{
	_fogMode = val;
}

HintMode Fog::getFogEffect() const
{
	return _fogEffect;
}

void Fog::setFogEffect(HintMode val)
{
	_fogEffect = val;
}

float Fog::getDensity() const
{
	return _density;
}

void Fog::setDensity(float val)
{
	_density = val;
}

void render::Fog::setFogColor(const phy::Color4F& color)
{
	_fogColor = color;
}

const phy::Color4F& render::Fog::getFogColor() const
{
	return _fogColor;
}
