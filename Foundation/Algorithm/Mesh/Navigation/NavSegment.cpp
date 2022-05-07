#include "NavSegment.h"
#include "NavPoly.h"

alg::mesh::NavSegment::NavSegment()
{
}

alg::mesh::NavSegment::NavSegment(const math::Vector3& src, const math::Vector3& dest)
:src(src), dest(dest)
{
	tan = getAngle();
}

alg::mesh::NavSegment::~NavSegment()
{
}

float alg::mesh::NavSegment::getAngle() const
{ 
	return atan2f(dest.getY() - src.getY(), dest.getX() - src.getX());
}

int alg::mesh::NavSegment::getPolygonCount() const 
{ 
	return polygons.size(); 
}

void alg::mesh::NavSegment::addPolygon(const NavPoly* poly)
{
	if (poly == nullptr) return;
	polygons.insert((NavPoly*)poly);
}

bool alg::mesh::NavSegment::equals(const NavSegment& segment) const
{
	return (segment.src == src && segment.dest == dest)
		|| (segment.src == dest && segment.dest == src);
}
