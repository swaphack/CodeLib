#include "Polyhedron.h"
#include "Surface.h"
#include "Polygon.h"
using namespace sys;

Polyhedron::Polyhedron(Surface* surfaces, int count)
:surfaces(nullptr)
{
	if (surfaces == nullptr || count < 4)
	{
		return;
	}

	this->surfaces = new Surface[count];
	this->count = count;

	for (int i = 0; i < count; i++)
	{
		this->surfaces[i] = surfaces[i];
	}
}

Polyhedron::~Polyhedron()
{
	if (surfaces != nullptr)
	{
		delete[] surfaces;
	}
}

bool Polyhedron::contiains(const Vector3& point)
{
	if (surfaces == nullptr || count < 4)
	{
		return false;
	}

	Polygon pxoy;
	Polygon pyoz;
	Polygon pxoz;

	Vector2 pxy(point.x, point.y);
	Vector2 pyz(point.y, point.z);
	Vector2 pxz(point.x, point.z);

	for (int i = 0; i < count; i++)
	{
		pxoy = Surface::projectOnXOY(surfaces[i]);
		pyoz = Surface::projectOnYOZ(surfaces[i]);
		pxoz = Surface::projectOnXOZ(surfaces[i]);

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