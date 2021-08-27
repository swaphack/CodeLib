#include "GeometryUtiity.h"
#include "Basic/base.h"
#include "2d/import.h"
#include <algorithm>

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

bool math::GeometryUtiity::isStandardPolygon(const std::vector<math::Vector3>& polygon)
{
	if (polygon.size() < 3)
	{
		return false;
	}

	int32_t lineCount = polygon.size();
	PointAndLinePosition2DType lastDirection = PointAndLinePosition2DType::NONE;
	for (int32_t i = 0; i < lineCount; i++)
	{
		Vector2 v0 = polygon[i % lineCount];
		Vector2 v1 = polygon[(i + 1) % lineCount];
		Vector2 v2 = polygon[(i + 1) % lineCount];
		Line2d line(v0, v1);
		PointAndLinePosition2DType eType = line.getPointPositionType(v2);
		if (eType == PointAndLinePosition2DType::INCLUDE)
		{
			return false;
		}

		if (lastDirection != PointAndLinePosition2DType::NONE)
		{
			if (lastDirection != eType)
			{
				return false;
			}
		}
		else
		{
			lastDirection = eType;
		}
	}

	return true;
}

bool math::GeometryUtiity::isConvexPolygon(const std::vector<math::Vector3>& polygon)
{
	if (!isStandardPolygon(polygon))
	{
		return false;
	}

	int32_t lineCount = polygon.size();
	PointAndLinePosition2DType lastDirection = PointAndLinePosition2DType::NONE;
	for (int32_t i = 0; i < lineCount; i++)
	{
		Vector2 v0 = polygon[i % lineCount];
		Vector2 v1 = polygon[(i + 1) % lineCount];
		Vector2 v2 = polygon[(i + 1) % lineCount];
		Line2d line(v0, v1);
		PointAndLinePosition2DType eType = line.getPointPositionType(v2);
		if (eType == PointAndLinePosition2DType::INCLUDE)
		{
			return false;
		}

		if (lastDirection != PointAndLinePosition2DType::NONE)
		{
			if (lastDirection != eType)
			{
				return false;
			}
		}
		else
		{
			lastDirection = eType;
		}
	}

	return true;
}

bool math::GeometryUtiity::createConvexPolygon(const std::vector<math::Vector3>& inPoints, std::vector<math::Vector3>& outPoints)
{
	if (inPoints.size() < 3)
	{
		return false;
	}

	std::vector<math::Vector3> points = inPoints;

	std::sort(points.begin(), points.end(), [](const math::Vector2& a, const math::Vector2& b) {
		if (a.getX() == b.getX())
		{
			return a.getY() > b.getY();
		}
		else
		{
			return a.getX() < b.getX();
		}

		});

	auto upList = std::vector<math::Vector3>();
	upList.push_back(points[0]);
	upList.push_back(points[1]);

	for (int i = 2; i < points.size(); i++)
	{
		upList.push_back(points[i]);
		while (upList.size() >= 3)
		{
			auto a = upList[upList.size() - 3];
			auto b = upList[upList.size() - 2];
			auto c = upList[upList.size() - 1];

			if (Vector2::getPointPosition(c, a, b) != 1)
			{
				upList.erase(upList.begin() + upList.size() - 2);
			}
			else
			{
				break;
			}
		}
	}

	auto lowerList = std::vector<math::Vector3>();
	lowerList.push_back(points[points.size() - 1]);
	lowerList.push_back(points[points.size() - 2]);

	for (int i = points.size() - 3; i >= 0; i--)
	{
		lowerList.push_back(points[i]);
		while (lowerList.size() >= 3)
		{
			auto a = lowerList[lowerList.size() - 3];
			auto b = lowerList[lowerList.size() - 2];
			auto c = lowerList[lowerList.size() - 1];
			if (Vector2::getPointPosition(c, a, b) != 1)
			{
				lowerList.erase(lowerList.begin() + lowerList.size() - 2);
			}
			else
			{
				break;
			}
		}
	}

	lowerList.erase(lowerList.begin());
	lowerList.erase(lowerList.begin() + lowerList.size() - 1);

	outPoints.insert(outPoints.end(), upList.begin(), upList.end());
	outPoints.insert(outPoints.end(), lowerList.begin(), lowerList.end());

	return outPoints.size() > 3;
}

bool math::GeometryUtiity::isStandardSurface(const std::vector<math::Vector3>& surface)
{
	if (surface.size() < 3)
	{
		return false;
	}

	int32_t lineCount = surface.size();
	for (int32_t i = 0; i < lineCount; i++)
	{
		// 邻边的向量
		Vector3 l0 = surface[(i + 1) % lineCount] - surface[i % lineCount];
		Vector3 l1 = surface[(i + 2) % lineCount] - surface[(i + 1) % lineCount];
		Vector3 l2 = surface[(i + 3) % lineCount] - surface[(i + 2) % lineCount];
		// 两向量所在平面的法向量
		Vector3 n0 = Vector3::cross(l0, l1);
		Vector3 n1 = Vector3::cross(l1, l2);
		if (Vector3::dot(n0, n1) != 0)
		{ // 法向量不共线
			return false;
		}
		if (n0.getX() * n1.getX() < 0)
		{// 法向量不同向
			return false;
		}
	}

	return true;
}

bool math::GeometryUtiity::isConvexSurface(const std::vector<math::Vector3>& surface)
{
	if (!isStandardSurface(surface))
	{
		return false;
	}
	/*
	int32_t lineCount = surface.getLength() - 2;
	int32_t lastDirection = -1;
	for (int32_t i = 0; i < lineCount; i++)
	{
	Vector3 l0 = surface[(i + 1) % lineCount] - surface[i % lineCount];
	Vector3 l1 = surface[(i + 2) % lineCount] - surface[(i + 1) % lineCount];

	int32_t direction = Vector3::direction(l1, l0);
	if (lastDirection == -1)
	{
	lastDirection = direction;
	}
	else if (direction != lastDirection)
	{
	return false;
	}
	}

	return true;
	*/
	return false;
}

bool math::GeometryUtiity::isCoplanarSurface(const std::vector<math::Vector3>& surface, const Vector3& point)
{
	if (!isStandardSurface(surface))
	{
		return false;
	}
	// 邻边的向量
	Vector3 l0 = surface[1] - surface[0];
	Vector3 l1 = surface[2] - surface[1];
	Vector3 l2 = point - surface[2];
	// 法向量
	Vector3 n0 = Vector3::cross(l0, l1);
	Vector3 n1 = Vector3::cross(l1, l2);
	if (Vector3::dot(n0, n1) != 0)
	{ // 法向量不共线
		return false;
	}
	if (n0.getX() * n1.getX() < 0)
	{// 法向量不同向
		return false;
	}

	return true;
}

bool math::GeometryUtiity::canSurfaceMakeCoplanar(const Vector3& point0, const Vector3& point1, const Vector3& point2, const Vector3& point3)
{
	// 邻边的向量
	Vector3 l0 = point1 - point0;
	Vector3 l1 = point2 - point1;
	Vector3 l2 = point3 - point2;

	if (Vector3::isThreePointsCollinear(point0, point1, point2))
	{ // 相邻共线，构成不了平面
		return false;
	}

	// 法向量
	Vector3 n0 = Vector3::cross(l0, l1);
	Vector3 n1 = Vector3::cross(l1, l2);
	if (Vector3::dot(n0, n1) != 0)
	{ // 法向量不共线
		return false;
	}
	if (n0.getX() * n1.getX() < 0)
	{// 法向量不同向
		return false;
	}

	return true;
}

std::vector<math::Vector3> math::GeometryUtiity::projectSurfaceOnXOY(const std::vector<math::Vector3>& surface)
{
	int32_t count = surface.size();
	std::vector<math::Vector3> points;
	points.resize(count);

	for (int32_t i = 0; i < count; i++)
	{
		float x = surface[i].getX();
		float y = surface[i].getY();
		points[i].setX(x);
		points[i].setY(y);
	}
	return points;
}

std::vector<math::Vector3> math::GeometryUtiity::projectSurfaceOnYOZ(const std::vector<math::Vector3>& surface)
{
	int32_t count = surface.size();
	std::vector<math::Vector3> points;
	points.resize(count);
	for (int32_t i = 0; i < count; i++)
	{
		float x = surface[i].getX();
		float y = surface[i].getY();
		points[i].setX(x);
		points[i].setY(y);
	}

	return points;
}

std::vector<math::Vector3> math::GeometryUtiity::projectSurfaceOnXOZ(const std::vector<math::Vector3>& surface)
{
	int32_t count = surface.size();
	std::vector<math::Vector3> points;
	points.resize(count);
	for (int32_t i = 0; i < count; i++)
	{
		float x = surface[i].getX();
		float y = surface[i].getZ();

		points[i].setX(x);
		points[i].setY(y);
	}
	return points;
}

bool math::GeometryUtiity::isClockWise(const Vector2& point0, const Vector2& point1, const Vector2& point2)
{
	math::Vector2 dir0 = point1 - point0;
	math::Vector2 dir1 = point2 - point0;
	return math::Vector2::cross(dir0, dir1) < 0;
}

bool math::GeometryUtiity::isCounterClockWise(const Vector2& point0, const Vector2& point1, const Vector2& point2)
{
	math::Vector2 dir0 = point1 - point0;
	math::Vector2 dir1 = point2 - point0;
	return math::Vector2::cross(dir0, dir1) > 0;
}