#include "Physics.h"

bool math::Physics::raycast(const Ray& ray, const BoundingBox& box)
{
	return box.hitRay(ray);
}

bool math::Physics::raycast(const Ray& ray, const Plane& plane)
{
	float a = 0;
	float b = 0;
	float c = 0;

	int d = getRayPosition(ray, plane, a, b, c);
	if (d == -1) return false;
	else if (d == 0)
	{
		if (a > 0) return false;
	}

	return true;
}

bool math::Physics::raycast(const Ray& ray, const std::vector<math::Vector3>& planePoints)
{
	if (planePoints.size() < 3)
	{
		return false;
	}

	Plane plane(planePoints[0], planePoints[1], planePoints[2]);
	math::Vector3 normal = plane.getNormal();

	float dmin = INT_MIN;
	float dmax = INT_MAX;

	for (size_t i = 0; i < planePoints.size() - 2; i++)
	{
		math::Vector3 p0 = planePoints[0 + i];
		math::Vector3 p1 = planePoints[1 + i];
		math::Vector3 p3 = p0 + normal;

		Plane newPlane(p0, p1, p3);

		float a = 0;
		float b = 0;
		float c = 0;
		int ret = getRayPosition(ray, newPlane, a, b, c);

		if (b > 0 && c < dmax)
		{
			dmax = c;
		}
		if (b < 0 && c > dmin)
		{
			dmin = c;
		}
		if (dmin > dmax)
		{
			return false;
		}
	}

	return true;
}

math::Vector3 math::Physics::reflect(const math::Vector3& light, const math::Vector3& normal)
{
	return 2 * math::Vector3::dot(light, normal) * normal - light;
}

int math::Physics::getRayPosition(const Ray& ray, const Plane& plane, float& a, float& b, float& c)
{
	a = 0;
	b = 0;
	c = 0;

	const Vector3& srcPoint = ray.getPoint();
	const Vector3& direction = ray.getDirection();

	a = -(plane.getParamA() * srcPoint.getX() + plane.getParamB() * srcPoint.getY() + plane.getParamC() * srcPoint.getZ() + plane.getParamD());
	b = plane.getParamA() * direction.getX() + plane.getParamB() * direction.getY() + plane.getParamC() * direction.getZ();

	if (b == 0) return 0;

	c = a / b;

	if (c < 0) return -1;

	return 1;
}
