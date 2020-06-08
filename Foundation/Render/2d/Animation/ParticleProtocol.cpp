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
	onPariticleChange();
}

const math::Vector3& ParticleProtocol::getSpeedAccelertaion()const
{
	return _speedAcceleration;
}

void ParticleProtocol::setColorAcceleration(float red, float green, float blue, float alpha)
{
	_colorAcceleration.red = red;
	_colorAcceleration.green = green;
	_colorAcceleration.blue = blue;
	_colorAcceleration.alpha = alpha;
	onPariticleChange();
}

void ParticleProtocol::setAngleAcceleration(float x, float y, float z)
{
	_angleAcceleration.set(x, y, z);
	onPariticleChange();
}

const math::Vector3& ParticleProtocol::getAngleAcceleration() const
{
	return _angleAcceleration;
}

void ParticleProtocol::setScaleAcceleration(float x, float y, float z)
{
	_scaleAcceleration.set(x,y,z);
	onPariticleChange();
}

const math::Vector3& ParticleProtocol::getScaleAcceleration() const
{
	return _scaleAcceleration;
}

const sys::Color4F& ParticleProtocol::getColorAcceleration() const
{
	return _colorAcceleration;
}

void ParticleProtocol::setLifeTime(float time)
{
	_lifeTime = time;
	onPariticleChange();
}

float ParticleProtocol::getLifeTime()
{
	return _lifeTime;
}

void render::ParticleProtocol::onPariticleChange()
{

}
