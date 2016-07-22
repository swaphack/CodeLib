#include "Particle.h"

using namespace render;

ParticleProtocol::ParticleProtocol()
:_liftTime(0)
{

}

ParticleProtocol::~ParticleProtocol()
{

}

void ParticleProtocol::setSpeedAcceleration(float x, float y, float z)
{
	_speedAcceleration.x = x;
	_speedAcceleration.y = y;
	_speedAcceleration.z = z;
}

sys::Vector ParticleProtocol::getSpeedAccelertaion()
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
	_angleAcceleration.x = x;
	_angleAcceleration.y = y;
	_angleAcceleration.z = z;
}

sys::Vector ParticleProtocol::getAngleAcceleration()
{
	return _angleAcceleration;
}

void ParticleProtocol::setScaleAcceleration(float x, float y, float z)
{
	_scaleAcceleration.x = x;
	_scaleAcceleration.y = y;
	_scaleAcceleration.z = z;
}

sys::Vector ParticleProtocol::getScaleAcceleration()
{
	return _scaleAcceleration;
}

sys::Color4F ParticleProtocol::getColorAcceleration()
{
	return _colorAcceleration;
}

void ParticleProtocol::setLifeTime(float time)
{
	_liftTime = time;
}

float ParticleProtocol::getLifeTime()
{
	return _liftTime;
}