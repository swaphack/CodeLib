#include "NavPoly.h"

alg::mesh::NavPoly::NavPoly()
{
}

alg::mesh::NavPoly::~NavPoly()
{
}

bool alg::mesh::NavPoly::initWithPoints(const std::vector<math::Vector3>& points)
{
	if (!math::GeometryUtiity::isConvexPolygon(points)) return false;
	_polygon.setPoints(points);

	_edges.clear();
	int count = points.size();
	for (int i = 0; i < count; i++)
	{
		NavSegment edge(points[i], points[(i + 1) % count]);
		edge.polygons.insert(this);
		_edges.push_back(edge);
	}
	return true;
}

bool alg::mesh::NavPoly::initWithPolygon(const math::Polygon& polygon)
{
	return initWithPoints(polygon.getPoints());
}

const math::Polygon& alg::mesh::NavPoly::getPolygon() const
{
	return _polygon;
}

const std::vector<alg::mesh::NavSegment>& alg::mesh::NavPoly::getEdges() const
{
	return _edges;
}

bool alg::mesh::NavPoly::isNeighborWithSimpleCheck(const NavPoly& poly, NavSegment& segment)
{
	if (!_polygon.getBoundingBox().isOverlap(poly.getPolygon().getBoundingBox())) return false;

	for (auto& e1 : _edges)
	{
		for (auto& e2 : poly.getEdges())
		{
			if (e1.equals(e2))
			{
				e1.addPolygon(&poly);
				((NavSegment*)&e2)->addPolygon(this);
				segment = e1;
				return true;
			}
		}
	}
	return false;
}

bool alg::mesh::NavPoly::isNeighbor(const NavPoly& poly, NavSegment& segment)
{
	if (!_polygon.getBoundingBox().isOverlap(poly.getPolygon().getBoundingBox())) return false;

	for (auto& e1 : _edges)
	{

	}

	return false;
}

bool alg::mesh::NavPoly::addNeighbor(const NavPoly& poly)
{
	return false;
}
