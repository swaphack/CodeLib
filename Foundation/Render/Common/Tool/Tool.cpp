#include "Tool.h"
#include "mathlib.h"
#include <cmath>

using namespace render;

math::Size Tool::GL_VIEW_SIZE = math::Size();

void Tool::setViewSize(float width, float height)
{
	float max = width <= height ? width : height;
	GL_VIEW_SIZE.set(width, height);
}

const math::Size& Tool::getViewSize()
{
	return GL_VIEW_SIZE;
}

float Tool::getViewWidth()
{
	return GL_VIEW_SIZE.getWidth();
}

float Tool::getViewHeight()
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
	return a * t + b * (1 - t);
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

	return math::Vector3(x, y, z);
}

void Tool::convertToAngle(const math::Vector3& src, math::Vector3& dest)
{
	float x = RADIAN_TO_ANGLE(src.getX());
	float y = RADIAN_TO_ANGLE(src.getY());
	float z = RADIAN_TO_ANGLE(src.getZ());

	dest.set(x, y, z);
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
	r = sqrt(a * a + b * b + c * c);

	assert(r != 0);

	normal.set(a / r, b / r, c / r);
}


