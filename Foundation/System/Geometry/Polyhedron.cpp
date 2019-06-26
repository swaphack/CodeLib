#include "Polyhedron.h"
#include "Surface.h"
#include "Polygon.h"
using namespace sys;

Polyhedron::Polyhedron(Surface* surfaces, int32 count)
:surfaces(nullptr)
{
	if (surfaces == nullptr || count < 4)
	{
		return;
	}

	this->surfaces = new Surface[count];
	this->count = count;

	for (int32 i = 0; i < count; i++)
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

bool Polyhedron::contiains(const Vector3& point32)
{
	if (surfaces == nullptr || count < 4)
	{
		return false;
	}

	Polygon pxoy;
	Polygon pyoz;
	Polygon pxoz;

	Vector2 pxy(point32.x, point32.y);
	Vector2 pyz(point32.y, point32.z);
	Vector2 pxz(point32.x, point32.z);

	for (int32 i = 0; i < count; i++)
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

bool Polyhedron::int32ersects(const Polyhedron& polyhedron)
{
	return false;
}