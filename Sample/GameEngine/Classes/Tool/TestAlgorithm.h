#pragma once

#include "../Env/TestNode.h"

class TestAlgorithm : public TestNode
{
public:
	TestAlgorithm();
	virtual ~TestAlgorithm();
protected:
	virtual void initNodes();
protected:
	void testRayMapFindPath();

	void testMeshMapFindPath();

	void testWFCCreateMap();

	void testDelaunay();
private:
	void drawTriangles(const std::vector<math::TrianglePoints>& vecTrianglePoints);
	void drawPolygons(const std::vector<math::Polygon>& vecPolygons);
	void drawPolygon(const math::Polygon& polygon);

	void drawSegments(const std::vector<math::LineSegment2d>& vecSegments);
};