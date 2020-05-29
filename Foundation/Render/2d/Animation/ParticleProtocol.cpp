#include "ParticleProtocol.h"

using namespace render;

ParticleProtocol::ParticleProtocol()
:_lifeTime(0)
{

}

ParticleProtocol::~ParticleProtocol()
{

}

void ParticleProtocol::setSpeedAcceleration(float x, float y, float z)
{
	_speedAcceleration.set(x,y,z);
}

math::Vector3 ParticleProtocol::getSpeedAccelertaion()
{
	return _speedAcceleration;
}

void ParticleProtocol::setColorAcceleration(float red, float green, float blue, float alpha)
{
	_colorAcceleration.red = red;
	_colorAcceleration.green = green;
	_colorAcceleration.blue = blue;
	_colorAcceleration.alpha = alpha;
}

void ParticleProtocol::setAngleAcceleration(float x, float y, float z)
{
	_angleAcceleration.set(x, y, z);
}

math::Vector3 ParticleProtocol::getAngleAcceleration()
{
	return _angleAcceleration;
}

void ParticleProtocol::setScaleAcceleration(float x, float y, float z)
{
	_scaleAcceleration.set(x,y,z);
}

math::Vector3 ParticleProtocol::getScaleAcceleration()
{
	return _scaleAcceleration;
}

sys::Color4F ParticleProtocol::getColorAcceleration()
{
	return _colorAcceleration;
}

void ParticleProtocol::setLifeTime(float time)
{
	_lifeTime = time;
}

float ParticleProtocol::getLifeTime()
{
	return _lifeTime;
}