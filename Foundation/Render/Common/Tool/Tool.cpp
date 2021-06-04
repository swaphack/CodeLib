#include "Tool.h"
#include "mathlib.h"
#include <cmath>

using namespace render;

math::Volume Tool::GL_VIEW_SIZE = math::Volume();

void Tool::setGLViewSize(float width, float height)
{
	float max = width <= height ? width : height;
	GL_VIEW_SIZE.set(width, height, max);
}

const math::Volume& Tool::getGLViewSize()
{
	return GL_VIEW_SIZE;
}

float Tool::getGLViewWidth()
{
	return GL_VIEW_SIZE.getWidth();
}

float Tool::getGLViewHeight()
{
	return GL_VIEW_SIZE.getHeight();
}

float render::Tool::getHorizontalProjectDistance(float angle)
{
	float radin = ANGLE_TO_RADIAN(angle);
	float tanR = tanf(radin);
	if (tanR == 0) return 0;
	return 1.0f / tanR;
}

float render::Tool::getVerticalAngle(float projDistance, float wDivh)
{
	if (projDistance == 0) return 0;
	return 2 * atanf(wDivh / projDistance);
}

float render::Tool::getLinearInterpolation(float a, float b, float t)
{
	return a*t + b*(1-t);
}

math::Vector3 render::Tool::getSphericalLinearInterpolation(const math::Vector3& src, const math::Vector3& dest, float t)
{
	math::Vector3 v1;
	math::Vector3 v2;

	v1 = math::Vector3::normalize(src);
	v2 = math::Vector3::normalize(dest);

	float sinR = math::Vector3::sinValue(v1, v2);
	float radian = math::Vector3::getRadian(v1, v2);

	if (sinR == 0) return src;

	return sinf((1.0f - t) * radian) / sinR * src + sinf(t * radian) / sinR * dest;
}

math::Quaternion render::Tool::getSphericalLinearInterpolation(const math::Quaternion& src, const math::Quaternion& dest, float t)
{
	math::Quaternion v1;
	math::Quaternion v2;

	v1 = math::Quaternion::normalize(src);
	v2 = math::Quaternion::normalize(dest);

	if (math::Quaternion::dot(v1, v2) < 0)
	{
		v2 = -1 * v2;
	}

	math::Quaternion qd = v1 - v2;

	float radian = qd.radian();

	float sinR = sinf(radian);

	if (sinR == 0) return src;

	return sinf((1.0f - t) * radian) / sinR * src + sinf(t * radian) / sinR * dest;
}

math::Vector3 Tool::convertToRadian(const math::Vector3& src)
{
	float x = ANGLE_TO_RADIAN(src.getX());
	float y = ANGLE_TO_RADIAN(src.getY());
	float z = ANGLE_TO_RADIAN(src.getZ());
	return math::Vector3(x, y, z);
}

void Tool::convertToRadian(const math::Vector3& src, math::Vector3& dest)
{
	float x = src.getX();
	float y = src.getY();
	float z = src.getZ();

	ADJUST_DURATION_VALUE_RANGE(x, 0, 360, 360);
	ADJUST_DURATION_VALUE_RANGE(y, 0, 360, 360);
	ADJUST_DURATION_VALUE_RANGE(z, 0, 360, 360);

	x = ANGLE_TO_RADIAN(x);
	y = ANGLE_TO_RADIAN(y);
	z = ANGLE_TO_RADIAN(z);

	dest.set(x, y, z);
}

math::Vector3 Tool::convertToAngle(const math::Vector3& src)
{
	float x = RADIAN_TO_ANGLE(src.getX());
	float y = RADIAN_TO_ANGLE(src.getY());
	float z = RADIAN_TO_ANGLE(src.getZ());

	return math::Vector3(x,y,z);
}

void Tool::convertToAngle(const math::Vector3& src, math::Vector3& dest)
{
	float x = RADIAN_TO_ANGLE(src.getX());
	float y = RADIAN_TO_ANGLE(src.getY());
	float z = RADIAN_TO_ANGLE(src.getZ());

	dest.set(x, y, z);
}

void Tool::convertToOGLPoisition(float x, float y, float z, math::Vector3& dest)
{
	const math::Volume& volume = GL_VIEW_SIZE;

	dest.set(x / volume.getDepth(), y / volume.getDepth(), z / volume.getDepth());
}

math::Vector3 Tool::convertToOGLPoisition(float x, float y, float z)
{
	const math::Volume& volume = GL_VIEW_SIZE;

	return math::Vector3(x / volume.getDepth(), y / volume.getDepth(), z / volume.getDepth());
}

math::Vector3 Tool::convertToOGLPoisition(const math::Vector3& src)
{
	return convertToOGLPoisition(src.getX(), src.getY(), src.getZ());
}

void Tool::convertToOGLPoisition(const math::Vector3& src, math::Vector3& dest)
{
	convertToOGLPoisition(src.getX(), src.getY(), src.getZ(), dest);
}

void Tool::convertToOGLPoisition(float* inPos, float* outPos)
{
 	const math::Volume& volume = GL_VIEW_SIZE;

	outPos[0] = inPos[0] / volume.getDepth();
	outPos[1] = inPos[1] / volume.getDepth();
	outPos[2] = inPos[2] / volume.getDepth();
}

math::Vector3 Tool::convertToWindowPosition(float x, float y, float z)
{
	const math::Volume& volume = GL_VIEW_SIZE;

	return math::Vector3(x * volume.getDepth(), y * volume.getDepth(), z * volume.getDepth());
}

math::Vector3 Tool::convertToWindowPosition(const math::Vector3& src)
{
	return convertToWindowPosition(src.getX(), src.getY(), src.getZ());
}

math::Volume Tool::convertToOGLVolume(const math::Volume& src)
{
	const math::Volume& volume = GL_VIEW_SIZE;

	return math::Volume(src.getWidth() / volume.getDepth() * 2 - 1, src.getHeight() / volume.getDepth() * 2 - 1, src.getDepth());
}

math::Vector3 Tool::getRotationPosition(const math::Vector3& vector, const math::Vector3& rotation)
{
	float sinx, siny, sinz;
	float cosx, cosy, cosz;
	float ax, ay, az;

	ax = ANGLE_TO_RADIAN(rotation.getX());
	ay = ANGLE_TO_RADIAN(rotation.getY());
	az = ANGLE_TO_RADIAN(rotation.getZ());

	sinx = sin(ax);
	siny = sin(ay);
	sinz = sin(az);

	cosx = cos(ax);
	cosy = cos(ay);
	cosz = cos(az);

	float x = vector.getX() * (cosy * cosz - sinx * siny * sinz)
		- vector.getY() * cosx * sinz
		+ vector.getZ() * (siny * cosz + sinx * cosy * sinz);

	float y = vector.getX() * (cosy * sinz + sinx * siny * cosz)
		+ vector.getY() * cosx * cosz
		+ vector.getZ() * (siny * sinz - sinx * cosy * cosz);

	float z = vector.getX() * (-cosx* siny)
		+ vector.getY() * sinx
		+ vector.getZ() * cosx * cosy;

	return math::Vector3(x,y,z);
}

void Tool::calNormal(const math::Vector3& p1, const math::Vector3& p2, const math::Vector3& p3, math::Vector3& normal)
{
	float a, b, c;
	float r;

	float x1 = p2.getX() - p1.getX(); 
	float y1 = p2.getY() - p1.getY(); 
	float z1 = p2.getZ() - p1.getZ();

	float x2 = p3.getX() - p1.getX(); 
	float y2 = p3.getY() - p1.getY(); 
	float z2 = p3.getZ() - p1.getZ();

	a = y1 * z2 - y2 * z1;
	b = x2 * z1 - x1 * z2;
	c = x1 * y2 - x2 * y1;
	r = sqrt(a * a + b* b + c * c);

	assert(r != 0);

	normal.set(a / r, b / r, c / r);
}

void Tool::calRect(const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor, RectPoints& rectVertex)
{
	float x = 0;
	float y = 0;

	// left down
	x = position.getX() - volume.getWidth() * anchor.getX();
	y = position.getY() - volume.getHeight() * anchor.getY();
	rectVertex.leftDown = math::Vector3(x, y, position.getZ());

	// right down
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() - volume.getHeight() * anchor.getY();
	rectVertex.rightDown = math::Vector3(x, y, position.getZ());

	// right up
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	rectVertex.rightUp = math::Vector3(x, y, position.getZ());

	// left up
	x = position.getX() - volume.getWidth() * anchor.getX();
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	rectVertex.leftUp = math::Vector3(x, y, position.getZ());
}

void Tool::calCube(const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor, CubePoints& cube)
{
	math::Vector3 point;

	//------ front ------

	// left down
	float x = position.getX() - volume.getWidth() * anchor.getX();
	float y = position.getY() - volume.getHeight() * anchor.getY();
	float z = position.getZ() + volume.getDepth() * anchor.getZ();

	point = math::Vector3(x, y, z);
	cube.setFrontLeftDownPosition(point);

	// right down
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() - volume.getHeight() * anchor.getY();
	z = position.getZ() + volume.getDepth() * anchor.getZ();

	point = math::Vector3(x, y, z);
	cube.setFrontRightDownPosition(point);

	// right up
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	z = position.getZ() + volume.getDepth() * anchor.getZ();

	point = math::Vector3(x, y, z);
	cube.setFrontRightUpPosition(point);

	// left up
	x = position.getX() - volume.getWidth() * anchor.getX();
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	z = position.getZ() + volume.getDepth() * anchor.getZ();

	point = math::Vector3(x, y, z);
	cube.setFrontLeftUpPosition(point);

	//------ back ------

	// left down
	x = position.getX() - volume.getWidth() * anchor.getX();
	y = position.getY() - volume.getHeight() * anchor.getY();
	z = position.getZ() - volume.getDepth() * (1 - anchor.getZ());

	point = math::Vector3(x, y, z);
	cube.setBackLeftDownPosition(point);

	// right down
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() - volume.getHeight() * anchor.getY();
	z = position.getZ() - volume.getDepth() * (1 - anchor.getZ());

	point = math::Vector3(x, y, z);
	cube.setBackRightDownPosition(point);

	// right up
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	z = position.getZ() - volume.getDepth() * (1 - anchor.getZ());

	point = math::Vector3(x, y, z);
	cube.setBackRightUpPosition(point);

	// left up
	x = position.getX() - volume.getWidth() * anchor.getX();
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	z = position.getZ() - volume.getDepth() * (1 - anchor.getZ());

	point = math::Vector3(x, y, z);
	cube.setBackLeftUpPosition(point);
}


