#include "NodeProtocol.h"

using namespace render;

//////////////////////////////////////////////////////////////////////////
SpaceProtocol::SpaceProtocol()
{
	this->setPosition(0, 0, 0);
	this->setScale(1, 1, 1);
	this->setRotation(0, 0, 0);
}

SpaceProtocol::~SpaceProtocol()
{

}

void SpaceProtocol::setPosition(float x, float y)
{
	_position.set(x, y);
	onSpaceChange();
}

void SpaceProtocol::setPosition(float x, float y, float z)
{
	_position.set(x, y, z);
	onSpaceChange();
}

void SpaceProtocol::setPosition(const math::Vector3& position)
{
	_position = position;
	onSpaceChange();
}

void SpaceProtocol::setPosition(const math::Vector2& position)
{
	_position = position;

	onSpaceChange();
}

const math::Vector3& SpaceProtocol::getPosition() const
{
	return _position;
}

void SpaceProtocol::setScale(float x, float y, float z)
{
	_scale.set(x, y, z);
	onSpaceChange();
}

void SpaceProtocol::setScale(const math::Vector3& scale)
{
	_scale = scale;
	onSpaceChange();
}

void SpaceProtocol::setScale(float scale)
{
	_scale.set(scale, scale, scale);
	onSpaceChange();
}

const math::Vector3& SpaceProtocol::getScale() const
{
	return _scale;
}

void SpaceProtocol::setRotation(float x, float y, float z)
{
	_rotation.set(x, y, z);
	onSpaceChange();
}

void SpaceProtocol::setRotation(const math::Vector3& rotation)
{
	_rotation = rotation;
	onSpaceChange();
}

const math::Vector3& SpaceProtocol::getRotation() const
{
	return _rotation;
}

void SpaceProtocol::setPositionX(float x)
{
	_position.setX(x);
	onSpaceChange();
}

void SpaceProtocol::setPositionY(float y)
{
	_position.setY(y);
	onSpaceChange();
}

void SpaceProtocol::setPositionZ(float z)
{
	_position.setZ(z);
	onSpaceChange();
}

float SpaceProtocol::getPositionX() const
{
	return _position.getX();
}

float SpaceProtocol::getPositionY() const
{
	return _position.getY();
}

float SpaceProtocol::getPositionZ() const
{
	return _position.getZ();
}

void SpaceProtocol::setScaleX(float x)
{
	_scale.setX(x);
	onSpaceChange();
}

void SpaceProtocol::setScaleY(float y)
{
	_scale.setY(y);
	onSpaceChange();
}

void SpaceProtocol::setScaleZ(float z)
{
	_scale.setZ(z);
	onSpaceChange();
}

float SpaceProtocol::getScaleX() const
{
	return _scale.getX();
}

float SpaceProtocol::getScaleY() const
{
	return _scale.getY();
}

float SpaceProtocol::getScaleZ() const
{
	return _scale.getZ();
}

void SpaceProtocol::setRotationX(float x)
{
	_rotation.setX(x);
	onSpaceChange();
}

void SpaceProtocol::setRotationY(float y)
{
	_rotation.setY(y);
	onSpaceChange();
}

void SpaceProtocol::setRotationZ(float z)
{
	_rotation.setZ(z);
	onSpaceChange();
}

float SpaceProtocol::getRotationX() const
{
	return _rotation.getX();
}

float SpaceProtocol::getRotationY() const
{
	return _rotation.getY();
}

float SpaceProtocol::getRotationZ() const
{
	return _rotation.getZ();
}

//////////////////////////////////////////////////////////////////////////
BodyProtocol::BodyProtocol()
{
	this->setAnchorPoint(0.5, 0.5, 0.5);
	this->setVolume(0, 0, 0);
}

BodyProtocol::~BodyProtocol()
{

}

void BodyProtocol::setAnchorPoint(float x, float y, float z)
{
	_anchor.set(x, y, z);
	onBodyChange();
}

void BodyProtocol::setAnchorPoint(float x, float y)
{
	_anchor.set(x, y);
	onBodyChange();
}

void BodyProtocol::setAnchorPoint(const math::Vector3& anchor)
{
	_anchor = anchor;
	onBodyChange();
}

void BodyProtocol::setAnchorPoint(const math::Vector2& anchor)
{
	_anchor = anchor;
	onBodyChange();

}

const math::Vector3& BodyProtocol::getAnchorPoint()
{
	return _anchor;
}

void BodyProtocol::setVolume(float w, float h, float d)
{
	_volume.set(w, h, d);
	onBodyChange();
}

void BodyProtocol::setVolume(float w, float h)
{
	_volume.set(w, h);
	onBodyChange();
}

void BodyProtocol::setVolume(const math::Volume& volume)
{
	_volume = volume;
	onBodyChange();
}

void BodyProtocol::setVolume(const math::Size& size)
{
	_volume.set(size.getWidth(), size.getHeight());
	onBodyChange();
}

const math::Volume& BodyProtocol::getVolume()
{
	return _volume;
}

void BodyProtocol::setWidth(float w)
{
	_volume.setWidth(w);
	onBodyChange();
}

void BodyProtocol::setHeight(float h)
{
	_volume.setHeight(h);
	onBodyChange();
}

void BodyProtocol::setDepth(float d)
{
	_volume.setDepth(d);
	onBodyChange();
}

float BodyProtocol::getWidth()
{
	return _volume.getWidth();
}

float BodyProtocol::getHeight()
{
	return _volume.getHeight();
}

float BodyProtocol::getDepth()
{
	return _volume.getDepth();
}

math::Size BodyProtocol::getSize()
{
	return math::Size(_volume.getWidth(), _volume.getWidth());
}

float render::BodyProtocol::getAnchorPointX()
{
	return _anchor.getX();
}

float render::BodyProtocol::getAnchorPointY()
{
	return _anchor.getY();
}

float render::BodyProtocol::getAnchorPointZ()
{
	return _anchor.getZ();
}