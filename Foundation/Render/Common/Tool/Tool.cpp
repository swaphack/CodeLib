#include "Tool.h"
#include <cmath>

#define HALF_CIRCLE_ANGEL 180.0f

using namespace render;

sys::Volume Tool::GL_VIEW_SIZE = sys::Volume();

Dimensions Tool::E_DIMENSIONS = ED_NONE;

void Tool::setGLViewSize(float width, float height)
{
	GL_VIEW_SIZE.width = width;
	GL_VIEW_SIZE.height = height;

	GL_VIEW_SIZE.deep = width > height ? width : height;
}

const sys::Volume& Tool::getGLViewSize()
{
	return GL_VIEW_SIZE;
}

Dimensions Tool::getDimensions()
{
	return E_DIMENSIONS;
}

void Tool::setDimensions(Dimensions d)
{
	E_DIMENSIONS = d;
}

sys::Vector3 Tool::convertToRadian(const sys::Vector3& src)
{
	return sys::Vector3(src.x / HALF_CIRCLE_ANGEL * PI, src.y / HALF_CIRCLE_ANGEL * PI, src.z / HALF_CIRCLE_ANGEL * PI);
}

sys::Vector3 Tool::convertToAngle(const sys::Vector3& src)
{
	return sys::Vector3(src.x / PI * HALF_CIRCLE_ANGEL, src.y / PI * HALF_CIRCLE_ANGEL, src.z / PI * HALF_CIRCLE_ANGEL);
}

void Tool::convertToOGLPoisition(float x, float y, float z, sys::Vector3& dest)
{
	dest.x = x / Tool::getGLViewSize().width;
	dest.y = y / Tool::getGLViewSize().height;
	dest.z = z / Tool::getGLViewSize().deep;
}

sys::Vector3 Tool::convertToOGLPoisition(float x, float y, float z)
{
	return sys::Vector3(x / Tool::getGLViewSize().width, y / Tool::getGLViewSize().height, z / Tool::getGLViewSize().deep);
}

sys::Vector3 Tool::convertToOGLPoisition(const sys::Vector3& src)
{
	return sys::Vector3(src.x / Tool::getGLViewSize().width, src.y / Tool::getGLViewSize().height, src.z / Tool::getGLViewSize().deep);
}

void Tool::convertToOGLPoisition(const sys::Vector3& src, sys::Vector3& dest)
{
	dest.x = src.x / Tool::getGLViewSize().width;
	dest.y = src.y / Tool::getGLViewSize().height;
	dest.z = src.z / Tool::getGLViewSize().deep;
}

sys::Vector3 Tool::convertToWindowPosition(float x, float y, float z)
{
	return sys::Vector3(x * Tool::getGLViewSize().width, y * Tool::getGLViewSize().height, z * Tool::getGLViewSize().deep);
}

sys::Vector3 Tool::convertToWindowPosition(const sys::Vector3& src)
{
	return sys::Vector3(src.x * Tool::getGLViewSize().width, src.y * Tool::getGLViewSize().height, src.z * Tool::getGLViewSize().deep);
}

sys::Volume Tool::convertToOGLVolume(const sys::Volume& src)
{
	return sys::Volume(src.width / Tool::getGLViewSize().width * 2 - 1, src.height / Tool::getGLViewSize().height * 2 - 1, src.deep);
}

sys::Vector3 Tool::getRotationPosition(const sys::Vector3& vector, const sys::Vector3& rotation)
{
	float sinx, siny, sinz;
	float cosx, cosy, cosz;
	float ax, ay, az;

	ax = rotation.x * PI / HALF_CIRCLE_ANGEL;
	ay = rotation.y * PI / HALF_CIRCLE_ANGEL;
	az = rotation.z * PI / HALF_CIRCLE_ANGEL;

	sinx = sin(ax);
	siny = sin(ay);
	sinz = sin(az);

	cosx = cos(ax);
	cosy = cos(ay);
	cosz = cos(az);

	sys::Vector3 dest;

	dest.x = vector.x * (cosy * cosz - sinx * siny * sinz)
		- vector.y * cosx * sinz
		+ vector.z * (siny * cosz + sinx * cosy * sinz);

	dest.y = vector.x * (cosy * sinz + sinx * siny * cosz)
		+ vector.y * cosx * cosz
		+ vector.z * (siny * sinz - sinx * cosy * cosz);

	dest.z = vector.x * (-cosx* siny)
		+ vector.y * sinx
		+ vector.z * cosx * cosy;

	return dest;
}

void Tool::calNormal(const sys::Vector3& p1, const sys::Vector3& p2, const sys::Vector3& p3, sys::Vector3& normal)
{
	sys::Vector3 vc1, vc2;
	float a, b, c;
	float r;

	vc1.x = p2.x - p1.x; vc1.y = p2.y - p1.y; vc1.z = p2.z - p1.z;
	vc2.x = p3.x - p1.x; vc2.y = p3.y - p1.y; vc2.z = p3.z - p1.z;

	a = vc1.y * vc2.z - vc2.y * vc1.z;
	b = vc2.x * vc1.z - vc1.x * vc2.z;
	c = vc1.x * vc2.y - vc2.x * vc1.y;
	r = sqrt(a * a + b* b + c * c);

	normal.x = a / r;
	normal.y = b / r;
	normal.z = c / r;
}

void Tool::calRect(const sys::Vector3& position, const sys::Volume& volume, const sys::Vector3& anchor, RectangeVertex& rectVertex)
{
	float x = 0;
	float y = 0;

	// left down
	x = position.x - volume.width * anchor.x;
	y = position.y - volume.height * anchor.y;
	rectVertex.leftDown = Tool::convertToOGLPoisition(x, y, position.z);

	// right down
	x = position.x + volume.width * (1 - anchor.x);
	y = position.y - volume.height * anchor.y;
	rectVertex.rightDown = Tool::convertToOGLPoisition(x, y, position.z);

	// right up
	x = position.x + volume.width * (1 - anchor.x);
	y = position.y + volume.height * (1 - anchor.y);
	rectVertex.rightUp = Tool::convertToOGLPoisition(x, y, position.z);

	// left up
	x = position.x - volume.width * anchor.x;
	y = position.y + volume.height * (1 - anchor.y);
	rectVertex.leftUp = Tool::convertToOGLPoisition(x, y, position.z);
}

void Tool::calRealRect(const sys::Vector3& position, const sys::Volume& volume, const sys::Vector3& anchor, RectangeVertex& rectVertex)
{
	float x = 0;
	float y = 0;

	// left down
	x = position.x - volume.width * anchor.x;
	y = position.y - volume.height * anchor.y;
	rectVertex.leftDown.x = x;
	rectVertex.leftDown.y = y;
	rectVertex.leftDown.z = position.z;

	// right down
	x = position.x + volume.width * (1 - anchor.x);
	y = position.y - volume.height * anchor.y;
	rectVertex.rightDown.x = x;
	rectVertex.rightDown.y = y;
	rectVertex.rightDown.z = position.z;

	// right up
	x = position.x + volume.width * (1 - anchor.x);
	y = position.y + volume.height * (1 - anchor.y);
	rectVertex.rightUp.x = x;
	rectVertex.rightUp.y = y;
	rectVertex.rightUp.z = position.z;

	// left up
	x = position.x - volume.width * anchor.x;
	y = position.y + volume.height * (1 - anchor.y);
	rectVertex.leftUp.x = x;
	rectVertex.leftUp.y = y;
	rectVertex.leftUp.z = position.z;
}


