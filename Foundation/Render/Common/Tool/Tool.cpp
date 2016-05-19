#include "Tool.h"
#include <cmath>

using namespace render;

sys::Volume Tool::GL_VIEW_SIZE = sys::Volume();

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

sys::Vector Tool::convertToRadian(const sys::Vector& src)
{
	return sys::Vector(src.x / (float)180 * PI, src.y / (float)180 * PI, src.z / (float)180 * PI);
}

sys::Vector Tool::convertToAngle(const sys::Vector& src)
{
	return sys::Vector(src.x / PI * (float)180, src.y / PI * (float)180, src.z / PI * (float)180);
}

void Tool::convertToOGLPoisition(float x, float y, float z, sys::Vector& dest)
{
	dest.x = x / Tool::getGLViewSize().width;
	dest.y = y / Tool::getGLViewSize().height;
	dest.z = z / Tool::getGLViewSize().deep;
}

sys::Vector Tool::convertToOGLPoisition(float x, float y, float z)
{
	return sys::Vector(x / Tool::getGLViewSize().width, y / Tool::getGLViewSize().height, z / Tool::getGLViewSize().deep);
}

sys::Vector Tool::convertToOGLPoisition(const sys::Vector& src)
{
	return sys::Vector(src.x / Tool::getGLViewSize().width, src.y / Tool::getGLViewSize().height, src.z / Tool::getGLViewSize().deep);
}

void Tool::convertToOGLPoisition(const sys::Vector& src, sys::Vector& dest)
{
	dest.x = src.x / Tool::getGLViewSize().width;
	dest.y = src.y / Tool::getGLViewSize().height;
	dest.z = src.z / Tool::getGLViewSize().deep;
}

sys::Vector Tool::convertToWindowPosition(float x, float y, float z)
{
	return sys::Vector(x * Tool::getGLViewSize().width, y * Tool::getGLViewSize().height, z * Tool::getGLViewSize().deep);
}

sys::Vector Tool::convertToWindowPosition(const sys::Vector& src)
{
	return sys::Vector(src.x * Tool::getGLViewSize().width, src.y * Tool::getGLViewSize().height, src.z * Tool::getGLViewSize().deep);
}

sys::Volume Tool::convertToOGLVolume(const sys::Volume& src)
{
	return sys::Volume(src.width / Tool::getGLViewSize().width * 2 - 1, src.height / Tool::getGLViewSize().height * 2 - 1, src.deep);
}

sys::Vector Tool::getPosition(const sys::Vector& vector, const sys::Vector& rotation)
{
	float sinx, siny, sinz;
	float cosx, cosy, cosz;
	float ax, ay, az;

	ax = rotation.x * PI / 180;
	ay = rotation.y * PI / 180;
	az = rotation.z * PI / 180;

	sinx = sin(ax);
	siny = sin(ay);
	sinz = sin(az);

	cosx = cos(ax);
	cosy = cos(ay);
	cosz = cos(az);

	sys::Vector dest;

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