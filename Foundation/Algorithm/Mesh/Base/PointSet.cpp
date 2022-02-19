#include "PointSet.h"

#include "MeshVertex.h"
#include "MeshEdge.h"
#include "MeshTriangle.h"
#include "MeshPolygon.h"

alg::mesh::PointSet::PointSet()
{
}

alg::mesh::PointSet::PointSet(const std::vector<math::Vector3>& points)
{
	this->setPoints(points);
}

alg::mesh::PointSet::~PointSet()
{
	this->cleanup();
}

alg::mesh::PointSet* alg::mesh::PointSet::create(int count, int width, int height)
{
	if (count <= 0 || width <= 0 || height <= 0) return nullptr;

	std::vector<math::Vector3> points;
	for (size_t i = 0; i < count; i++)
	{
		math::Vector3 point(sys::Random::getNumber(width), sys::Random::getNumber(height));
		points.push_back(point);
	}

	auto item = CREATE_OBJECT(PointSet);
	SAFE_RETAIN(item);
	item->setPoints(points);

	return item;
}

void alg::mesh::PointSet::setPoints(const std::vector<math::Vector3>& points)
{
	for (auto item : points)
	{
		this->createVertex(item);
	}
}

const math::Vector3* alg::mesh::PointSet::getPosition(int idx) const
{
	if (idx < 0 || idx >= _vertices.size()) return nullptr;
	return &_vertices[idx];
}

int alg::mesh::PointSet::getPointCount() const
{
	return _vertices.size();
}

alg::mesh::MeshVertex* alg::mesh::PointSet::createVertex(int idx0)
{
	auto point = getPosition(idx0);
	if (point == nullptr) return nullptr;

	return createVertex(*point);
}

alg::mesh::MeshVertex* alg::mesh::PointSet::createVertex(const math::Vector3& point0)
{
	std::string key = point0.toString();

	auto it = _meshVertexes.find(key);
	if (it != _meshVertexes.end())
	{
		SAFE_RETAIN(it->second);
		return it->second;
	}

	auto item = CREATE_OBJECT(MeshVertex);
	SAFE_RETAIN(item);
	item->setKey(key);
	item->setPointSet(this);
	item->setPosition(point0);
	_vertices.push_back(point0);
	_meshVertexes[key] = item;

	return item;
}

void alg::mesh::PointSet::removeVertex(MeshVertex* pVertex)
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

const std::map<std::string, alg::mesh::MeshVertex*>& alg::mesh::PointSet::getVertexes() const
{
	return _meshVertexes;
}

alg::mesh::MeshEdge* alg::mesh::PointSet::createEdge(int idx0, int idx1)
{
	auto pVertex0 = createVertex(idx0);
	auto pVertex1 = createVertex(idx1);

	if (pVertex0 == nullptr || pVertex1 == nullptr) 
		return nullptr;

	return createEdge(pVertex0, pVertex1);
}

alg::mesh::MeshEdge* alg::mesh::PointSet::createEdge(const math::Vector3& point0, const math::Vector3& point1)
{
	auto pVertex0 = createVertex(point0);
	auto pVertex1 = createVertex(point1);

	return createEdge(pVertex0, pVertex1);
}

alg::mesh::MeshEdge* alg::mesh::PointSet::createEdge(const MeshVertex* pVertex0, const MeshVertex* pVertex1)
{
	if (pVertex0 == nullptr || pVertex1 == nullptr)
	{
		return nullptr;
	}

	std::string key = getKey(pVertex0, pVertex1);

	auto it = _meshEdges.find(key);
	if (it != _meshEdges.end())
	{
		SAFE_RETAIN(it->second);
		return it->second;
	}

	auto item = CREATE_OBJECT(MeshEdge);
	SAFE_RETAIN(item);
	item->setKey(key);
	item->setPointSet(this);
	item->setVertexes(pVertex0, pVertex1);
	_meshEdges[key] = item;

	return item;
}

void alg::mesh::PointSet::removeEdge(MeshEdge* pEdge)
{
	if (pEdge == nullptr)
	{
		return;
	}
	
	auto key = getKey(pEdge->getVertex(0), pEdge->getVertex(1));
	auto it = _meshEdges.find(key);
	if (it != _meshEdges.end())
	{
		_meshEdges.erase(it);
		SAFE_RELEASE(pEdge);
	}
	else
	{
		PRINT("Error: no exist edge %s", key.c_str());
	}
}

alg::mesh::MeshTriangle* alg::mesh::PointSet::createTriangle(int idx0, int idx1, int idx2)
{
	auto pVertexA = createVertex(idx0);
	auto pVertexB = createVertex(idx1);
	auto pVertexC = createVertex(idx2);
	if (pVertexA == nullptr || pVertexB == nullptr || pVertexC == nullptr) return nullptr;

	return createTriangle(pVertexA, pVertexB, pVertexC);
}

alg::mesh::MeshTriangle* alg::mesh::PointSet::createTriangle(const math::Vector3& point0, const math::Vector3& point1, const math::Vector3& point2)
{
	auto pVertexA = createVertex(point0);
	auto pVertexB = createVertex(point1);
	auto pVertexC = createVertex(point2);
	if (pVertexA == nullptr || pVertexB == nullptr || pVertexC == nullptr) return nullptr;

	return createTriangle(pVertexA, pVertexB, pVertexC);
}

alg::mesh::MeshTriangle* alg::mesh::PointSet::createTriangle(const MeshVertex* pVertex0, const MeshVertex* pVertex1, const MeshVertex* pVertex2)
{
	if (pVertex0 == nullptr || pVertex1 == nullptr || pVertex2 == nullptr) return nullptr;


	std::string key = getKey(pVertex0, pVertex1, pVertex2);

	auto it = _meshTriangles.find(key);
	if (it != _meshTriangles.end())
	{
		SAFE_RETAIN(it->second);
		return it->second;
	}

	auto item = CREATE_OBJECT(MeshTriangle);
	SAFE_RETAIN(item);
	item->setKey(key);
	item->setPointSet(this);
	item->setVertexes(pVertex0, pVertex1, pVertex2);
	_meshTriangles[key] = item;

	return item;
}

alg::mesh::MeshTriangle* alg::mesh::PointSet::createTriangle(const std::vector<MeshVertex*>& vertexes)
{
	if (vertexes.size() < 3) return nullptr;

	return createTriangle(vertexes[0], vertexes[1], vertexes[2]);
}

void alg::mesh::PointSet::removeTriangle(MeshTriangle* pTriangle)
{
	if (pTriangle == nullptr)
	{
		return;
	}
	auto key = getKey(pTriangle->getVertex(0), pTriangle->getVertex(1), pTriangle->getVertex(2));
	pTriangle->decompose();
	auto it = _meshTriangles.find(key);
	if (it != _meshTriangles.end())
	{
		SAFE_RELEASE(pTriangle);
		_meshTriangles.erase(it);
	}
	else
	{
		PRINT("Error: no exist triangle %s", key.c_str());
	}
}

const std::map<std::string, alg::mesh::MeshTriangle*>& alg::mesh::PointSet::getTriangles() const
{
	return _meshTriangles;
}

bool alg::mesh::PointSet::containTriangle(const math::Vector3& point0, const math::Vector3& point1, const math::Vector3& point2) const
{
	auto key = getKey(point0, point1, point2);

	auto it = _meshTriangles.find(key);
	return it != _meshTriangles.end();
}

bool alg::mesh::PointSet::containTriangle(const MeshVertex* vertex0, const MeshVertex* vertex1, const MeshVertex* vertex2) const
{
	if (vertex0 == nullptr || vertex1 == nullptr || vertex2 == nullptr)
		return false;

	auto key = getKey(vertex0, vertex1, vertex2);

	auto it = _meshTriangles.find(key);
	return it != _meshTriangles.end();
}

alg::mesh::MeshPolygon* alg::mesh::PointSet::createPolygon(const std::vector<int>& vecIndices)
{
	std::vector<alg::mesh::MeshVertex*> vertexes;
	for (auto item : vecIndices)
	{
		auto point = createVertex(item);
		if (point != nullptr)
		{
			vertexes.push_back(point);
		}
	}
	return createPolygon(vertexes);
}

alg::mesh::MeshPolygon* alg::mesh::PointSet::createPolygon(const std::vector<math::Vector3>& vecPoints)
{
	std::vector<alg::mesh::MeshVertex*> vertexes;
	for (auto item : vecPoints)
	{
		auto point = createVertex(item);
		if (point != nullptr)
		{
			vertexes.push_back(point);
		}
	}
	return createPolygon(vertexes);
}

alg::mesh::MeshPolygon* alg::mesh::PointSet::createPolygon(const std::vector<MeshVertex* >& vecVertexes)
{
	std::string key = getKey(vecVertexes);

	auto it = _meshPolygons.find(key);
	if (it != _meshPolygons.end())
	{
		SAFE_RETAIN(it->second);
		return it->second;
	}

	auto item = CREATE_OBJECT(MeshPolygon);
	SAFE_RETAIN(item);
	item->setKey(key);
	item->setPointSet(this);
	item->setVertexes(vecVertexes);
	_meshPolygons[key] = item;

	return item;
}

void alg::mesh::PointSet::removePolygon(MeshPolygon* pPolygon)
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

void alg::mesh::PointSet::cleanup()
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

std::string alg::mesh::PointSet::getKey(const MeshVertex* pVertex)
{
	std::vector<MeshVertex*> vecVertex;
	if (pVertex) vecVertex.push_back((MeshVertex*)pVertex);
	return getKey(vecVertex);
}

std::string alg::mesh::PointSet::getKey(const MeshVertex* pVertex0, const MeshVertex* pVertex1)
{
	std::vector<MeshVertex*> vecVertex;
	if (pVertex0) vecVertex.push_back((MeshVertex*)pVertex0);
	if (pVertex1) vecVertex.push_back((MeshVertex*)pVertex1);
	return getKey(vecVertex);
}

std::string alg::mesh::PointSet::getKey(const MeshVertex* pVertex0, const MeshVertex* pVertex1, const MeshVertex* pVertex2)
{
	std::vector<MeshVertex*> vecVertex;
	if (pVertex0) vecVertex.push_back((MeshVertex*)pVertex0);
	if (pVertex1) vecVertex.push_back((MeshVertex*)pVertex1);
	if (pVertex2) vecVertex.push_back((MeshVertex*)pVertex2);
	return getKey(vecVertex);
}

std::string alg::mesh::PointSet::getKey(const std::vector<MeshVertex*>& vecVertex)
{
	std::vector<math::Vector3> vecPoint;
	for (auto item : vecVertex)
	{
		if (item)
		{
			vecPoint.push_back(item->getPosition());
		}
	}

	return getKey(vecPoint);
}

std::string alg::mesh::PointSet::getKey(const math::Vector3& point)
{
	std::vector<math::Vector3> vecPoint;
	vecPoint.push_back(point);
	return getKey(vecPoint);
}

std::string alg::mesh::PointSet::getKey(const math::Vector3& point0, const math::Vector3& point1)
{
	std::vector<math::Vector3> vecPoint;
	vecPoint.push_back(point0);
	vecPoint.push_back(point1);
	return getKey(vecPoint);
}

std::string alg::mesh::PointSet::getKey(const math::Vector3& point0, const math::Vector3& point1, const math::Vector3& point2)
{
	std::vector<math::Vector3> vecPoint;
	vecPoint.push_back(point0);
	vecPoint.push_back(point1);
	vecPoint.push_back(point2);
	return getKey(vecPoint);
}

std::string alg::mesh::PointSet::getKey(const std::vector<math::Vector3>& points)
{
	std::vector<std::string> data;
	for (auto item : points)
	{
		std::string value = item.toString();
		if (!value.empty())
		{
			data.push_back(value);
		}
	}
	std::sort(data.begin(), data.end(), [](const std::string& a, const std::string& b) { return a < b; });

	std::string key;
	for (size_t i = 0; i < data.size(); i++)
	{
		key += data[i] + "-";
	}

	if (key.size() > 0)
	{
		key = key.substr(0, key.size() - 1);
	}

	return key;
}
