#include "Tool.h"
#include "mathlib.h"
#include <cmath>

using namespace render;

math::Volume Tool::GL_VIEW_SIZE = math::Volume();

void Tool::setGLViewSize(float width, float height)
{
	GL_VIEW_SIZE.set(width, height, width > height ? width : height);
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

math::Vector3 Tool::convertToRadian(const math::Vector3& src)
{
	float x = ANGLE_TO_RADIAN(src.getX());
	float y = ANGLE_TO_RADIAN(src.getY());
	float z = ANGLE_TO_RADIAN(src.getZ());
	return math::Vector3(x, y, z);
}

void Tool::convertToRadian(const math::Vector3& src, math::Vector3& dest)
{
	float x = ANGLE_TO_RADIAN(src.getX());
	float y = ANGLE_TO_RADIAN(src.getY());
	float z = ANGLE_TO_RADIAN(src.getZ());

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
	math::Volume volume = Tool::getGLViewSize();

	dest.set(x / volume.getWidth(), y / volume.getHeight(), z / volume.getDepth());
}

math::Vector3 Tool::convertToOGLPoisition(float x, float y, float z)
{
	math::Volume volume = Tool::getGLViewSize();

	return math::Vector3(x / volume.getWidth(), y / volume.getHeight(), z / volume.getDepth());
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
	math::Volume volume = Tool::getGLViewSize();

	outPos[0] = inPos[0] / volume.getWidth();
	outPos[1] = inPos[1] / volume.getHeight();
	outPos[2] = inPos[2] / volume.getDepth();
}

math::Vector3 Tool::convertToWindowPosition(float x, float y, float z)
{
	math::Volume volume = Tool::getGLViewSize();

	return math::Vector3(x * volume.getWidth(), y * volume.getHeight(), z * volume.getDepth());
}

math::Vector3 Tool::convertToWindowPosition(const math::Vector3& src)
{
	return convertToWindowPosition(src.getX(), src.getY(), src.getZ());
}

math::Volume Tool::convertToOGLVolume(const math::Volume& src)
{
	math::Volume volume = Tool::getGLViewSize();

	return math::Volume(src.getWidth() / volume.getWidth() * 2 - 1, src.getHeight() / volume.getHeight() * 2 - 1, src.getDepth());
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

void Tool::calRect(const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor, RectVertex& rectVertex)
{
	float x = 0;
	float y = 0;

	// left down
	x = position.getX() - volume.getWidth() * anchor.getX();
	y = position.getY() - volume.getHeight() * anchor.getY();
	rectVertex.leftDown = Tool::convertToOGLPoisition(x, y, position.getZ());

	// right down
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() - volume.getHeight() * anchor.getY();
	rectVertex.rightDown = Tool::convertToOGLPoisition(x, y, position.getZ());

	// right up
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	rectVertex.rightUp = Tool::convertToOGLPoisition(x, y, position.getZ());

	// left up
	x = position.getX() - volume.getWidth() * anchor.getX();
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	rectVertex.leftUp = Tool::convertToOGLPoisition(x, y, position.getZ());
}

void Tool::calRealRect(const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor, RectVertex& rectVertex)
{
	float x = 0;
	float y = 0;

	// left down
	x = position.getX() - volume.getWidth() * anchor.getX();
	y = position.getY() - volume.getHeight() * anchor.getY();
	rectVertex.leftDown.setX(x);
	rectVertex.leftDown.setY(y);
	rectVertex.leftDown.setZ(position.getZ());

	// right down
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() - volume.getHeight() * anchor.getY();
	rectVertex.rightDown.setX(x);
	rectVertex.rightDown.setY(y);
	rectVertex.rightDown.setZ(position.getZ());

	// right up
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	rectVertex.rightUp.setX(x);
	rectVertex.rightUp.setY(y);
	rectVertex.rightUp.setZ(position.getZ());

	// left up
	x = position.getX() - volume.getWidth() * anchor.getX();
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	rectVertex.leftUp.setX(x);
	rectVertex.leftUp.setY(y);
	rectVertex.leftUp.setZ(position.getZ());
}

void Tool::calRealCube(const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor, CubeVertex& cube)
{
	math::Vector3 point;

	//------ front ------

	// left down
	float x = position.getX() - volume.getWidth() * anchor.getX();
	float y = position.getY() - volume.getHeight() * anchor.getY();
	float z = position.getZ() - volume.getDepth() * anchor.getZ();

	point = math::Vector3(x, y, z);
	cube.front.leftDown = point;
	cube.left.rightDown = point;
	cube.bottom.leftUp = point;

	// right down
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() - volume.getHeight() * anchor.getY();
	z = position.getZ() - volume.getDepth() * anchor.getZ();

	point = math::Vector3(x, y, z);
	cube.front.rightDown = point;
	cube.right.leftDown = point;
	cube.bottom.rightUp = point;

	// right up
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	z = position.getZ() - volume.getDepth() * anchor.getZ();

	point = math::Vector3(x, y, z);
	cube.front.rightUp = point;
	cube.right.leftUp = point;
	cube.top.rightDown = point;

	// left up
	x = position.getX() - volume.getWidth() * anchor.getX();
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	z = position.getZ() - volume.getDepth() * anchor.getZ();

	point = math::Vector3(x, y, z);
	cube.front.leftUp = point;
	cube.left.rightUp = point;
	cube.top.leftDown = point;

	//------ back ------

	// left down
	x = position.getX() - volume.getWidth() * anchor.getX();
	y = position.getY() - volume.getHeight() * anchor.getY();
	z = position.getZ() + volume.getDepth() * (1 - anchor.getZ());

	point = math::Vector3(x, y, z);
	cube.back.rightDown = point;
	cube.left.leftDown = point;
	cube.bottom.leftDown = point;

	// right down
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() - volume.getHeight() * anchor.getY();
	z = position.getZ() + volume.getDepth() * (1 - anchor.getZ());

	point = math::Vector3(x, y, z);
	cube.back.leftDown = point;
	cube.right.rightDown = point;
	cube.bottom.rightDown = point;

	// right up
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	z = position.getZ() + volume.getDepth() * (1 - anchor.getZ());

	point = math::Vector3(x, y, z);
	cube.back.leftUp = point;
	cube.top.rightUp = point;
	cube.right.rightUp = point;

	// left up
	x = position.getX() - volume.getWidth() * anchor.getX();
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	z = position.getZ() + volume.getDepth() * (1 - anchor.getZ());

	point = math::Vector3(x, y, z);
	cube.back.rightUp = point;
	cube.left.leftUp = point;
	cube.top.leftUp = point;
}


