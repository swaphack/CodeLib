#include "PointSet.h"

#include "MeshVertex.h"
#include "MeshEdge.h"
#include "MeshTriangle.h"
#include "MeshPolygon.h"

alg::PointSet::PointSet()
{
}

alg::PointSet::~PointSet()
{
}

void alg::PointSet::setPoints(const std::vector<math::Vector3>& points)
{
	_vertices = points;
}

const math::Vector3* alg::PointSet::getPoint(int idx) const
{
	if (idx < 0 || idx >= _vertices.size()) return nullptr;
	return &_vertices[idx];
}

alg::MeshVertex* alg::PointSet::createVertex(int idx0)
{
	auto point = getPoint(idx0);
	if (point == nullptr) return nullptr;

	return createVertex(*point);
}

alg::MeshVertex* alg::PointSet::createVertex(const math::Vector3& point0)
{
	std::string key = point0.toString();
	auto it = _meshVertexes.find(key);
	if (it != _meshVertexes.end())
	{
		SAFE_RETAIN(it->second);
		return it->second;
	}

	auto item = new MeshVertex(point0);
	_meshVertexes[key] = item;

	return item;
}

void alg::PointSet::removeVertex(MeshVertex* pVertex)
{
	if (pVertex == nullptr)
	{
		return;
	}
	for (auto item : _meshVertexes)
	{
		if (item.second == pVertex)
		{
			if (pVertex->RetainCount == 1)
			{
				_meshVertexes.erase(item.first);
			}
			SAFE_RELEASE(pVertex);
			break;
		}
	}
}

alg::MeshEdge* alg::PointSet::createEdge(int idx0, int idx1)
{
	auto pointA = getPoint(idx0);
	auto pointB = getPoint(idx1);
	if (pointA == nullptr || pointB == nullptr) return nullptr;

	return createEdge(*pointA, *pointB);
}

alg::MeshEdge* alg::PointSet::createEdge(const math::Vector3& point0, const math::Vector3& point1)
{
	std::string key = point0.toString() + "-" + point1.toString();

	auto it = _meshEdges.find(key);
	if (it != _meshEdges.end())
	{
		SAFE_RETAIN(it->second);
		return it->second;
	}

	auto item = new MeshEdge(point0, point1);
	_meshEdges[key] = item;

	return item;
}

void alg::PointSet::removeEdge(MeshEdge* pEdge)
{
	if (pEdge == nullptr)
	{
		return;
	}
	for (auto item : _meshEdges)
	{
		if (item.second == pEdge)
		{
			if (pEdge->RetainCount == 1)
			{
				_meshEdges.erase(item.first);
			}
			SAFE_RELEASE(pEdge);
			break;
		}
	}
}

alg::MeshTriangle* alg::PointSet::createTriangle(int idx0, int idx1, int idx2)
{
	auto pointA = getPoint(idx0);
	auto pointB = getPoint(idx1);
	auto pointC = getPoint(idx2);
	if (pointA == nullptr || pointB == nullptr || pointC == nullptr) return nullptr;

	return createTriangle(*pointA, *pointB, *pointC);
}

alg::MeshTriangle* alg::PointSet::createTriangle(const math::Vector3& point0, const math::Vector3& point1, const math::Vector3& point2)
{
	std::string key = point0.toString() + "-" + point1.toString() + "-" + point2.toString();

	auto it = _meshTriangles.find(key);
	if (it != _meshTriangles.end())
	{
		SAFE_RETAIN(it->second);
		return it->second;
	}

	auto item = new MeshTriangle(point0, point1, point2);
	_meshTriangles[key] = item;

	return item;
}

void alg::PointSet::removeTriangle(MeshTriangle* pTriangle)
{
	if (pTriangle == nullptr)
	{
		return;
	}
	for (auto item : _meshTriangles)
	{
		if (item.second == pTriangle)
		{
			if (pTriangle->RetainCount == 1)
			{
				_meshTriangles.erase(item.first);
			}
			SAFE_RELEASE(pTriangle);
			break;
		}
	}
}

alg::MeshPolygon* alg::PointSet::createPolygon(const std::vector<int>& vecIndices)
{
	return nullptr;
}

alg::MeshPolygon* alg::PointSet::createPolygon(const std::vector<math::Vector3>& vecPoints)
{
	return nullptr;
}

void alg::PointSet::removePolygon(MeshPolygon* pPolygon)
{
	if (pPolygon == nullptr)
	{
		return;
	}
	for (auto item : _meshPolygons)
	{
		if (item.second == pPolygon)
		{
			_meshPolygons.erase(item.first);
			break;
		}
	}
}

void alg::PointSet::cleanup()
{
	for (auto item : _meshVertexes) delete item.second;
	for (auto item : _meshEdges) delete item.second;
	for (auto item : _meshTriangles) delete item.second;
	for (auto item : _meshPolygons) delete item.second;

	_vertices.clear();
	_meshVertexes.clear();
	_meshEdges.clear();
	_meshTriangles.clear();
	_meshPolygons.clear();
}
