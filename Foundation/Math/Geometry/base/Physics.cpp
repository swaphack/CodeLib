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
	if (d == -1) 
	{
		return false;
	}
	else if (d == 0)
	{
		if (a > 0) return false;
	}

	return true;
}

bool math::Physics::raycast(const Ray& ray, const math::TrianglePoints& points, math::Vector3& point)
{

    math::Vector3 e1 = points[1] - points[0];
    math::Vector3 e2 = points[2] - points[1];

    //Begin calculating determinant - also used to calculate u parameter
    math::Vector3 p = math::Vector3::cross(ray.getDirection(), e2);
    //if determinant is near zero, ray lies in plane of triangle
    double det = math::Vector3::dot(e1, p);
    //NOT CULLING
    if (det > -EPSILON && det < EPSILON)
    {
        return false;
    }
    double inv_det = 1.f / det;

    //calculate distance from V1 to ray origin
    math::Vector3 t = ray.getSrcPoint() - points[0];

    //Calculate u parameter and test bound
    double u = math::Vector3::dot(t, p) * inv_det;
    //The intersection lies outside of the triangle
    if (u < 0.f || u > 1.f)
    {
        return false;
    }

    //Prepare to test v parameter
    math::Vector3 q = math::Vector3::cross(t, e1);
    //Calculate V parameter and test bound
    double v = math::Vector3::dot(ray.getDirection(), q) * inv_det;

    //The intersection lies outside of the triangle
    if (v < 0.f || u + v  > 1.f)
    {
        return false;
    }

    double k = math::Vector3::dot(e2, q) * inv_det;

    //ray intersection
    if (k > EPSILON)
    {
        point = ray.getSrcPoint() + ray.getDirection() * k;
        return true;
    }

    return false;
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

	const Vector3& srcPoint = ray.getSrcPoint();
	const Vector3& direction = ray.getDirection();

	a = -(plane.getParamA() * srcPoint.getX() + plane.getParamB() * srcPoint.getY() + plane.getParamC() * srcPoint.getZ() + plane.getParamD());
	b = plane.getParamA() * direction.getX() + plane.getParamB() * direction.getY() + plane.getParamC() * direction.getZ();

	if (b == 0) return 0;

	c = a / b;

	if (c < 0) return -1;

	return 1;
}
