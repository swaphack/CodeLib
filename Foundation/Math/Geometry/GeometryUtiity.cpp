#include "GeometryUtiity.h"
#include "Basic/base.h"

bool math::GeometryUtiity::isInsideOfTriangle(const Vector2& center, const Vector2& direction, float angle, const Vector2& target)
{
	float radian = ANGLE_TO_RADIAN(angle);

	Vector2 offset = target - center;

	float cosa = Vector2::dot(offset, center) / (offset.getLength() * center.getLength());
	float cosd = cosf(radian);

	return cosa >= cosd;
}

bool math::GeometryUtiity::isInsideOfTriangle(const Vector2& center, const Vector2& direction, float angle, float radius, const Vector2& target)
{
	Vector2 offset = target - center;

	if (radius < offset.getLength())
	{
		return false;
	}

	return isInsideOfTriangle(center, direction, angle, target);
}

bool math::GeometryUtiity::isInsideOfTriangle(const Vector2& center, const Vector2& direction, float angle, float znear, float zfar, const Vector2& target)
{
	Vector2 offset = target - center;
	float len = offset.getLength();
	if (znear > len || len > zfar)
	{
		return false;
	}

	return isInsideOfTriangle(center, direction, angle, target);
}

bool math::GeometryUtiity::isInsideOfCone(const Vector3& center, const Vector3& direction, float angle, const Vector3& target)
{
	float radian = ANGLE_TO_RADIAN(angle);

	Vector3 offset = target - center;

	float cosa = Vector3::dot(offset, center) / (offset.getLength() * center.getLength());
	float cosd = cosf(radian);

	return cosa >= cosd;
}

bool math::GeometryUtiity::isInsideOfCone(const Vector3& center, const Vector3& direction, float angle, float radius, const Vector3& target)
{
	Vector3 offset = target - center;

	if (radius < offset.getLength())
	{
		return false;
	}

	return isInsideOfCone(center, direction, angle, target);
}

bool math::GeometryUtiity::isInsideOfCone(const Vector3& center, const Vector3& direction, float angle, float znear, float zfar, const Vector3& target)
{
	Vector3 offset = target - center;
	float len = offset.getLength();
	if (znear > len || len > zfar)
	{
		return false;
	}

	return isInsideOfCone(center, direction, angle, target);
}

bool math::GeometryUtiity::isInsideOfPyramid(const Vector3& center, const Vector3& direction, const Size& size, const Vector3& target)
{
	return false;
}

bool math::GeometryUtiity::isInsideOfPyramid(const Vector3& center, const Vector3& direction, const Size& size, float radius, const Vector3& target)
{
	return false;
}

bool math::GeometryUtiity::isInsideOfPyramid(const Vector3& center, const Vector3& direction, const Size& size, float znear, float zfar, const Vector3& target)
{
	return false;
}
