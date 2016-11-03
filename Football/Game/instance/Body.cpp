#include "Body.h"

using namespace game;


Body::Body()
{

}

Body::~Body()
{

}

void Body::setLength(float value)
{
	m_vVolume.Y = value;
}

float Body::getLength() const
{
	return m_vVolume.Y;
}

void Body::setWidth(float value)
{
	m_vVolume.X = value;
}

float Body::getWidth() const
{
	return m_vVolume.X;
}

void Body::setHeight(float value)
{
	m_vVolume.Z = value;
}

float Body::getHeight() const
{
	return m_vVolume.Z;
}

void Body::setPositionX(float value)
{
	m_vPosition.X = value;
}

float Body::getPositionX() const
{
	return m_vPosition.X;
}

void Body::setPositionY(float value)
{
	m_vPosition.Y = value;
}

float Body::getPositionY() const
{
	return m_vPosition.Y;
}

void Body::setPositionZ(float value)
{
	m_vPosition.Z = value;
}

float Body::getPositionZ() const
{
	return m_vPosition.Z;
}

bool Body::intersectBody(const IBody* pBody) const
{
	// 后面补充
	return false;
}

const Vector& Body::getPosition() const
{
	return m_vPosition;
}

void Body::lookAt(const Vector& point)
{
	// 后面补充
}
