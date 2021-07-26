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
	this->cleanup();
}

alg::PointSet* alg::PointSet::create(int count, int width, int height)
{
	if (count <= 0 || width <= 0 || height <= 0) return nullptr;

	std::vector<math::Vector3> points;
	for (size_t i = 0; i < count; i++)
	{
		math::Vector3 point(sys::Random::getNumber(width), sys::Random::getNumber(height));
		points.push_back(point);
	}

	auto item = CREATE_OBJECT(PointSet);
	item->setPoints(points);

	return item;
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

	auto item = CREATE_OBJECT(MeshVertex);
	item->setPosition(point0);
	SAFE_RETAIN(item);

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
			_meshVertexes.erase(item.first);
			SAFE_RELEASE(pVertex);
			break;
		}
	}
}

alg::MeshEdge* alg::PointSet::createEdge(int idx0, int idx1)
{
	auto pVertex0 = createVertex(idx0);
	auto pVertex1 = createVertex(idx1);

	if (pVertex0 == nullptr || pVertex1 == nullptr) 
		return nullptr;

	return createEdge(pVertex0, pVertex1);
}

alg::MeshEdge* alg::PointSet::createEdge(const math::Vector3& point0, const math::Vector3& point1)
{
	auto pVertex0 = createVertex(point0);
	auto pVertex1 = createVertex(point1);

	return createEdge(pVertex0, pVertex1);
}

alg::MeshEdge* alg::PointSet::createEdge(const MeshVertex* pVertex0, const MeshVertex* pVertex1)
{
	if (pVertex0 == nullptr || pVertex1 == nullptr)
	{
		return nullptr;
	}

	std::string key = pVertex0->getPosition().toString() + "-" + pVertex1->getPosition().toString();

	auto it = _meshEdges.find(key);
	if (it != _meshEdges.end())
	{
		SAFE_RETAIN(it->second);
		return it->second;
	}

	auto item = CREATE_OBJECT(MeshEdge);
	item->setVertexes(pVertex0, pVertex1);
	SAFE_RETAIN(item);
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
	std::vector<math::Vector3> points;
	for (auto item : vecIndices)
	{
		auto point = getPoint(item);
		if (point != nullptr)
		{
			points.push_back(*point);
		}
	}
	return createPolygon(points);
}

alg::MeshPolygon* alg::PointSet::createPolygon(const std::vector<math::Vector3>& vecPoints)
{
	std::string key;
	for (auto item : vecPoints)
	{
		key += item.toString() + ",";
	}

	if (key.size() > 0)
	{
		key = key.substr(0, key.size() - 1);
	}

	auto it = _meshPolygons.find(key);
	if (it != _meshPolygons.end())
	{
		SAFE_RETAIN(it->second);
		return it->second;
	}

	auto item = new MeshPolygon(vecPoints);
	_meshPolygons[key] = item;

	return item;
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
	for (auto item : _meshVertexes) SAFE_RELEASE(item.second);
	for (auto item : _meshEdges) SAFE_RELEASE(item.second);
	for (auto item : _meshTriangles) SAFE_RELEASE(item.second);
	for (auto item : _meshPolygons) SAFE_RELEASE(item.second);

	_vertices.clear();
	_meshVertexes.clear();
	_meshEdges.clear();
	_meshTriangles.clear();
	_meshPolygons.clear();
}
