#include "Polyhedron.h"
#include "Surface.h"
#include "Geometry/2d/Polygon.h"
using namespace math;

Polyhedron::Polyhedron(Surface* _surfaces, int32_t _count)
:_surfaces(nullptr)
{
	if (_surfaces == nullptr || _count < 4)
	{
		return;
	}

	this->_surfaces = new Surface[_count];
	this->_count = _count;

	for (int32_t i = 0; i < _count; i++)
	{
		this->_surfaces[i] = _surfaces[i];
	}
}

Polyhedron::~Polyhedron()
{
	if (_surfaces != nullptr)
	{
		delete[] _surfaces;
	}
}

bool Polyhedron::contiains(const Vector3& point)
{
	if (_surfaces == nullptr || _count < 4)
	{
		return false;
	}

	Polygon pxoy;
	Polygon pyoz;
	Polygon pxoz;

	Vector2 pxy(point.getX(), point.getY());
	Vector2 pyz(point.getY(), point.getZ());
	Vector2 pxz(point.getX(), point.getZ());

	for (int32_t i = 0; i < _count; i++)
	{
		pxoy = Surface::projectOnXOY(_surfaces[i]);
		pyoz = Surface::projectOnYOZ(_surfaces[i]);
		pxoz = Surface::projectOnXOZ(_surfaces[i]);

		if (pxoy.contains(pxy) || pyoz.contains(pyz) || pyoz.contains(pxz))
		{
			return true;
		}
	}

	return false;
}

bool Polyhedron::intersects(const Polyhedron& polyhedron)
{
	return false;
}