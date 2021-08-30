#pragma once

#include "TestNode.h"

class TestAlgNode : public TestNode
{
public:
	TestAlgNode();
	virtual ~TestAlgNode();
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
};