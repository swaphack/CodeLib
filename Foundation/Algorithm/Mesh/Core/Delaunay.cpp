#include "Delaunay.h"
#include "Mesh/Base/import.h"
#include "mathlib.h"

alg::Delaunay::Delaunay()
{
}
alg::Delaunay::~Delaunay()
{
	SAFE_DELETE(_pointSet);
}

std::vector<math::TrianglePoints> alg::Delaunay::createWithBowyerWatson(const std::vector<math::Vector3>& srcPoints)
{
	std::vector<math::TrianglePoints> triangles;
	if (srcPoints.size() < 3) return triangles;

	std::vector<math::Vector3> points = srcPoints;

	std::sort(points.begin(), points.end(), [](const math::Vector3& a, const math::Vector3& b) {
		return math::CompareVec3(a, b);
	});

	SAFE_DELETE(_pointSet);
	_pointSet = new PointSet(points);

	std::set<MeshTriangle*> meshTriangles;
	auto superTriangle = initSuperTriangle();
	if (superTriangle == nullptr) return triangles;
	meshTriangles.insert(superTriangle);

	generateTriangle(points, meshTriangles);


	std::set<std::string> keys;
	for (auto item : _pointSet->getTriangles())
	{
		for (size_t i = 0; i < 3; i++)
		{
			if (item.second->hasVertex(superTriangle->getVertex(i)))
			{
				continue;
			}
		}

		std::string key = PointSet::getKey(
			item.second->getPosition(0),
			item.second->getPosition(1),
			item.second->getPosition(2));
		auto it = keys.find(key);
		if (it == keys.end())
		{
			keys.insert(key);
			triangles.push_back(math::TrianglePoints(item.second->getOrderdPositions(false)));
		}
	}

	return triangles;
}

std::vector<math::TrianglePoints> alg::Delaunay::createWithBowyerWatson(const math::RectPoints& rect, const std::vector<math::Vector3>& srcPoints)
{
	std::vector<math::TrianglePoints> triangles;
	if (srcPoints.size() == 0) return triangles;

	std::vector<math::Vector3> points = srcPoints;

	std::sort(points.begin(), points.end(), [](const math::Vector3& a, const math::Vector3& b) {
		return math::CompareVec3(a, b);
	});

	SAFE_DELETE(_pointSet);
	_pointSet = new PointSet(points);
	_pointSet->createVertex(rect.getLeftBottom());
	_pointSet->createVertex(rect.getLeftTop());
	_pointSet->createVertex(rect.getRightBottom());
	_pointSet->createVertex(rect.getRightTop());

	std::set<MeshTriangle*> meshTriangles;
	auto rectTriangles = initRectTriangle(rect);
	if (rectTriangles.size() == 0) return triangles;
	for (auto item : rectTriangles)
	{
		meshTriangles.insert(item);
	}

	generateTriangle(points, meshTriangles);

	std::set<std::string> keys;
	for (auto item : _pointSet->getTriangles())
	{
		std::string key = PointSet::getKey(
			item.second->getPosition(0),
			item.second->getPosition(1),
			item.second->getPosition(2));
		auto it = keys.find(key);
		if (it == keys.end())
		{
			keys.insert(key);

			triangles.push_back(math::TrianglePoints(item.second->getOrderdPositions(false)));
		}
	}

	return triangles;
}

const alg::PointSet* alg::Delaunay::getPointSet() const
{
	return _pointSet;
}

alg::PointSet* alg::Delaunay::getPointSet()
{
	return _pointSet;
}

alg::MeshTriangle* alg::Delaunay::initSuperTriangle()
{
	if (_pointSet == nullptr || _pointSet->getPointCount() < 3) return nullptr;

	int pointCount = _pointSet->getPointCount();

	math::Vector3 leftDown = *_pointSet->getPosition(0);
	math::Vector3 rightUp = *_pointSet->getPosition(0);

	for (size_t i = 0; i < pointCount; i++)
	{
		auto point = _pointSet->getPosition(i);
		if (point->getX() < leftDown.getX()) leftDown.setX(point->getX());
		if (point->getY() < leftDown.getY()) leftDown.setY(point->getY());

		if (point->getX() > rightUp.getX()) rightUp.setX(point->getX());
		if (point->getY() > rightUp.getY()) rightUp.setY(point->getY());
	}

	float w = rightUp.getX() - leftDown.getX();
	float h = rightUp.getY() - leftDown.getY();

	math::Vector3 innerTriTop(leftDown.getX() + 0.5f * w, rightUp.getY());
	math::Vector3 innerTriLeft = leftDown;
	math::Vector3 innerTriRight(rightUp.getX(), leftDown.getY());

	math::Vector3 leftPoint0 = innerTriTop; leftPoint0.setX(leftPoint0.getX() - w);
	math::Vector3 leftPoint1= innerTriLeft; leftPoint1.setX(leftPoint1.getX() - w);

	math::Vector3 rightPoint0 = innerTriTop; rightPoint0.setX(rightPoint0.getX() + w);
	math::Vector3 rightPoint1 = innerTriRight; rightPoint1.setX(rightPoint1.getX() + w);

	math::Line3d leftLine(leftPoint0, leftPoint1);
	math::Line3d rightLine(rightPoint0, rightPoint1);

	math::Vector3 outTriTop;
	leftLine.getIntersectPoint(rightLine, outTriTop);

	math::Vector3 outTriLeft = 2 * leftPoint1 - leftPoint0;
	math::Vector3 outTriRight = 2 * rightPoint1 - rightPoint0;

	return _pointSet->createTriangle(outTriTop, outTriLeft, outTriRight);
}

std::vector<alg::MeshTriangle*> alg::Delaunay::initRectTriangle(const math::RectPoints& rect)
{
	std::vector<alg::MeshTriangle*> triangles;

	if (_pointSet == nullptr) return triangles;

	auto pTriangle0 = _pointSet->createTriangle(rect.getLeftBottom(), rect.getLeftTop(), rect.getRightTop());
	auto pTriangle1 = _pointSet->createTriangle(rect.getLeftBottom(), rect.getRightBottom(), rect.getRightTop());

	triangles.push_back(pTriangle0);
	triangles.push_back(pTriangle1);

	return triangles;
}

void alg::Delaunay::generateTriangle(const std::vector<math::Vector3>& points, std::set<MeshTriangle*>& meshTriangles)
{
	if (_pointSet == nullptr) return;

	int pointCount = points.size();
	for (size_t i = 0; i < pointCount; i++)
	{
		auto pVertex = _pointSet->createVertex(points[i]);
		if (!pVertex) continue;

		std::vector<MeshTriangle*> badTriangles;
		for (auto item : meshTriangles)
		{
			if (item->getCircumcircle().contains(points[i]))
			{
				badTriangles.push_back(item);
			}
		}

		std::map<MeshEdge*, int> badEdges;
		for (auto triangle : badTriangles)
		{
			for (auto edge : triangle->getEdges())
			{
				auto it = badEdges.find(edge);
				if (it != badEdges.end())
				{// ÒÆ³ý¹²±ß
					badEdges[edge] += 1;
				}
				else
				{// Ìí¼ÓÐÂ±ß
					badEdges.insert(std::make_pair(edge, 1));
				}
			}
		}

		int count = badTriangles.size() - 1;
		for (int j = count; j >=0; j--)
		{
			removeTriangle(meshTriangles, badTriangles, j);
		}

		for (auto item : badEdges)
		{
			if (item.second > 1) continue;
			if (item.first->getAdjacentTriangles().size() >= 2)
			{
				int a = 1;
			}
			auto pVertex0 = item.first->getVertex(0);
			auto pVertex1 = item.first->getVertex(1);
			if (pVertex == pVertex0 || pVertex == pVertex1)
			{
				continue;
			}
			if (!_pointSet->containTriangle(pVertex0, pVertex1, pVertex))
			{
				auto triangle = _pointSet->createTriangle(pVertex0, pVertex1, pVertex);
				meshTriangles.insert(triangle);
			}
		}
	}	
}

void alg::Delaunay::removeTriangle(
	std::set<MeshTriangle*>& meshTriangles, 
	std::vector<MeshTriangle*>& badTriangles, int index)
{
	if (index < 0 || index >= badTriangles.size()) return;
	auto triangle = badTriangles[index];
	if (triangle == nullptr) return;
	_pointSet->removeTriangle(triangle);
	auto it = std::find(meshTriangles.begin(), meshTriangles.end(), triangle);
	if (it != meshTriangles.end()) meshTriangles.erase(it);
}
