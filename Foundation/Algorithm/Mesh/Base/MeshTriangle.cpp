#include "MeshTriangle.h"
#include "MeshVertex.h"
#include "MeshEdge.h"
#include "PointSet.h"

alg::mesh::MeshTriangle::MeshTriangle()
{
	for (size_t i = 0; i < TRIANGLE_VERTEX_AND_EDGE_COUNT; i++)
	{
		_vertexes[i] = nullptr;
		_edges[i] = nullptr;
	}
}

alg::mesh::MeshTriangle::MeshTriangle(PointSet* pointSet, const math::Vector3& pointA, const math::Vector3& pointB, const math::Vector3& pointC)
{
	this->setVertexes(pointSet, pointA, pointB, pointC);
}

alg::mesh::MeshTriangle::MeshTriangle(const MeshVertex* pVertexA, const MeshVertex* pVertexB, const MeshVertex* pVertexC)
{
	this->setVertexes(pVertexA, pVertexB, pVertexC);
}

alg::mesh::MeshTriangle::~MeshTriangle()
{
}

void alg::mesh::MeshTriangle::setVertexes(PointSet* pointSet, const math::Vector3& pointA, const math::Vector3& pointB, const math::Vector3& pointC)
{
	if (pointSet == nullptr) return;
	this->setPointSet(pointSet);
	auto pVertexA = pointSet->createVertex(pointA);
	auto pVertexB = pointSet->createVertex(pointB);
	auto pVertexC = pointSet->createVertex(pointC);

	this->setVertexes(pVertexA, pVertexB, pVertexC);
}

void alg::mesh::MeshTriangle::setVertexes(const MeshVertex* pVertexA, const MeshVertex* pVertexB, const MeshVertex* pVertexC)
{
	if (pVertexA == nullptr || pVertexB == nullptr || pVertexC == nullptr
		|| pVertexA->getPointSet() == nullptr || pVertexB->getPointSet() == nullptr || pVertexC->getPointSet() == nullptr) 
		return;

	this->setVertex(0, pVertexA);
	this->setVertex(1, pVertexB);
	this->setVertex(2, pVertexC);

	auto position = math::TrianglePoints::getCircumcenter2d(_vertexes[0]->getPosition(), _vertexes[1]->getPosition(), _vertexes[2]->getPosition());

	_circumcircle = math::Circle(position, (position - _vertexes[0]->getPosition()).getMagnitude());
	_normal = math::TrianglePoints::getNormal(_vertexes[0]->getPosition(), _vertexes[1]->getPosition(), _vertexes[2]->getPosition());


	auto pEdgeA = pVertexA->getPointSet()->createEdge(_vertexes[0], _vertexes[1]);
	auto pEdgeB = pVertexA->getPointSet()->createEdge(_vertexes[1], _vertexes[2]);
	auto pEdgeC = pVertexA->getPointSet()->createEdge(_vertexes[2], _vertexes[0]);

	this->setEdges(pEdgeA, pEdgeB, pEdgeC);
}

void alg::mesh::MeshTriangle::setEdges(const MeshEdge* pEdgeA, const MeshEdge* pEdgeB, const MeshEdge* pEdgeC)
{
	this->setEdge(0, pEdgeA);
	this->setEdge(1, pEdgeB);
	this->setEdge(2, pEdgeC);
}

void alg::mesh::MeshTriangle::setVertex(int index, const MeshVertex* pVertex)
{
	if (index < 0 || index >= TRIANGLE_VERTEX_AND_EDGE_COUNT) return;

	auto vertex = (MeshVertex*)pVertex;
	
	if (_vertexes[index])
	{
		_vertexes[index]->removeAdjacentTriangle(this);
		SAFE_RELEASE(_vertexes[index]);
		_vertexes[index] = nullptr;
	}

	if (vertex)
	{
		vertex->addAdjacentTriangle(this);
		SAFE_RETAIN(vertex);
		_vertexes[index] = vertex;
	}
}

int alg::mesh::MeshTriangle::getIndexOfVertex(const MeshVertex* pVertex) const
{
	if (pVertex == nullptr) return -1;
	for (size_t i = 0; i < TRIANGLE_VERTEX_AND_EDGE_COUNT; i++)
	{
		if (pVertex == _vertexes[i]) return i;
	}
	return -1;
}

bool alg::mesh::MeshTriangle::hasVertex(const MeshVertex* pVertex) const
{
	if (pVertex == nullptr) return false;

	for (size_t i = 0; i < TRIANGLE_VERTEX_AND_EDGE_COUNT; i++)
	{
		if (pVertex->equal(_vertexes[i])) return true;
	}
	return false;
}

void alg::mesh::MeshTriangle::setEdge(int index, const MeshEdge* pEdge)
{
	if (index < 0 || index >= TRIANGLE_VERTEX_AND_EDGE_COUNT) return;

	auto edge = (MeshEdge*)pEdge;

	if (edge)
	{
		if (edge->getAdjacentTriangles().size() >= 2)
		{
			PRINT("ERROR : Edge Adjacent Triangles Count >= 2");
		}
	}

	if (_edges[index])
	{
		_edges[index]->removeAdjacentTriangle(this);
		SAFE_RELEASE(_edges[index]);
		if (_edges[index]->getAdjacentTriangles().size() == 0)
		{
			_pointSet->removeEdge(_edges[index]);
		}
		_edges[index] = nullptr;
	}

	if (edge)
	{
		edge->addAdjacentTriangle(this);
		SAFE_RETAIN(edge);
		_edges[index] = edge;
	}
}

int alg::mesh::MeshTriangle::getIndexOfEdge(const MeshEdge* pEdge) const
{
	if (pEdge == nullptr) return -1;
	for (size_t i = 0; i < TRIANGLE_VERTEX_AND_EDGE_COUNT; i++)
	{
		if (pEdge == _edges[i]) return i;
	}
	return -1;
}

bool alg::mesh::MeshTriangle::containEdge(const MeshEdge* pEdge) const
{
	for (size_t i = 0; i < TRIANGLE_VERTEX_AND_EDGE_COUNT; i++)
	{
		if (pEdge->equal(_edges[i])) return true;
	}
	return false;
}

const alg::mesh::MeshVertex* alg::mesh::MeshTriangle::getVertex(int index) const
{
	if (index < 0 || index >= TRIANGLE_VERTEX_AND_EDGE_COUNT) return nullptr;

	return _vertexes[index];
}

alg::mesh::MeshVertex* alg::mesh::MeshTriangle::getVertex(int index)
{
	if (index < 0 || index >= TRIANGLE_VERTEX_AND_EDGE_COUNT) return nullptr;

	return _vertexes[index];
}

math::Vector3 alg::mesh::MeshTriangle::getPosition(int index)  const
{
	auto pVertex = getVertex(index);
	if (pVertex == nullptr) return math::Vector3();
	return pVertex->getPosition();
}

std::array<alg::mesh::MeshVertex*, TRIANGLE_VERTEX_AND_EDGE_COUNT>& alg::mesh::MeshTriangle::getVertexes()
{
	return _vertexes;
}

const std::array<alg::mesh::MeshVertex*, TRIANGLE_VERTEX_AND_EDGE_COUNT>& alg::mesh::MeshTriangle::getVertexes() const
{
	return _vertexes;
}

std::vector<alg::mesh::MeshVertex*> alg::mesh::MeshTriangle::getOrderVertexes(const MeshVertex* pFirstVertex, bool bClockWise) const
{
	std::vector<MeshVertex*> vertexes;
	if (pFirstVertex == nullptr) pFirstVertex = getVertex(0);
	int index0 = this->getIndexOfVertex(pFirstVertex);
	if (index0 == -1) return vertexes;

	int index1 = (index0 + 1) % TRIANGLE_VERTEX_AND_EDGE_COUNT;
	int index2 = (index0 + 2) % TRIANGLE_VERTEX_AND_EDGE_COUNT;

	std::vector<int> vecCWOrder;
	std::vector<int> vecCCWOrder;
	std::vector<int> vecOrder;

	bool bClockWiseOrder = math::GeometryUtiity::isClockWise(pFirstVertex->getPosition(), this->getPosition(index1), this->getPosition(index2));
	if (bClockWiseOrder)
	{
		vecCWOrder.push_back(index0); vecCWOrder.push_back(index1); vecCWOrder.push_back(index2);
		vecCCWOrder.push_back(index0); vecCCWOrder.push_back(index2); vecCCWOrder.push_back(index1);
	}
	else
	{
		vecCWOrder.push_back(index0); vecCWOrder.push_back(index2); vecCWOrder.push_back(index1);
		vecCCWOrder.push_back(index0); vecCCWOrder.push_back(index1); vecCCWOrder.push_back(index2);
	}

	vecOrder = bClockWise ? vecCWOrder : vecCCWOrder;

	for (auto index : vecOrder)
	{
		vertexes.push_back((alg::mesh::MeshVertex*)this->getVertex(index));
	}
	
	return vertexes;
}

std::vector<math::Vector3> alg::mesh::MeshTriangle::getOrderdPositions(bool bClockWise) const
{
	bool bClockWiseOrder = math::GeometryUtiity::isClockWise(this->getPosition(0), this->getPosition(1), this->getPosition(2));

	std::vector<math::Vector3> cwIndices;
	std::vector<math::Vector3> ccwIndices;

	if (bClockWiseOrder)
	{
		cwIndices.push_back(this->getPosition(0)); cwIndices.push_back(this->getPosition(1)); cwIndices.push_back(this->getPosition(2));
		ccwIndices.push_back(this->getPosition(0)); ccwIndices.push_back(this->getPosition(2)); ccwIndices.push_back(this->getPosition(1));
	}
	else
	{
		ccwIndices.push_back(this->getPosition(0)); ccwIndices.push_back(this->getPosition(1)); ccwIndices.push_back(this->getPosition(2));
		cwIndices.push_back(this->getPosition(0)); cwIndices.push_back(this->getPosition(2)); cwIndices.push_back(this->getPosition(1));
	}
	
	return bClockWise ? cwIndices : ccwIndices;
}

const alg::mesh::MeshEdge* alg::mesh::MeshTriangle::getEdge(int index) const
{
	if (index < 0 || index >= TRIANGLE_VERTEX_AND_EDGE_COUNT) return nullptr;

	return _edges[index];
}

alg::mesh::MeshEdge* alg::mesh::MeshTriangle::getEdge(int index)
{

	if (index < 0 || index >= TRIANGLE_VERTEX_AND_EDGE_COUNT) return nullptr;

	return _edges[index];
}

const alg::mesh::MeshEdge* alg::mesh::MeshTriangle::getEdgeByVertex(int vertexIndex0, int vertexIndex1) const
{
	auto vertex0 = getVertex(vertexIndex0);
	auto vertex1 = getVertex(vertexIndex1);

	if (vertex0 == nullptr || vertex1 == nullptr)
		return nullptr;

	for (size_t i = 0; i < TRIANGLE_VERTEX_AND_EDGE_COUNT; i++)
	{
		auto pEdge = getEdge(i);
		if (pEdge == nullptr) continue;

		if (pEdge->hasVertex(vertex0) && pEdge->hasVertex(vertex1))
		{
			return pEdge;
		}
	}

	return nullptr;
}

alg::mesh::MeshEdge* alg::mesh::MeshTriangle::getEdgeByVertex(int vertexIndex0, int vertexIndex1)
{
	auto vertex0 = getVertex(vertexIndex0);
	auto vertex1 = getVertex(vertexIndex1);

	if (vertex0 == nullptr || vertex1 == nullptr)
		return nullptr;

	for (size_t i = 0; i < TRIANGLE_VERTEX_AND_EDGE_COUNT; i++)
	{
		auto pEdge = getEdge(i);
		if (pEdge == nullptr) continue;
		
		if (pEdge->hasVertex(vertex0) && pEdge->hasVertex(vertex1))
		{
			return pEdge;
		}
	}

	return nullptr;
}

std::array<alg::mesh::MeshEdge*, TRIANGLE_VERTEX_AND_EDGE_COUNT>& alg::mesh::MeshTriangle::getEdges()
{
	return _edges;
}

const std::array<alg::mesh::MeshEdge*, TRIANGLE_VERTEX_AND_EDGE_COUNT>& alg::mesh::MeshTriangle::getEdges() const
{
	return _edges;
}

bool alg::mesh::MeshTriangle::intersects(const alg::mesh::MeshTriangle* triangle) const
{
	if (triangle == nullptr) return false;

	for (auto item : _edges)
	{
		if (triangle->intersects(item))
		{
			return true;
		}
	}

	return false;
}

bool alg::mesh::MeshTriangle::intersects(const alg::mesh::MeshEdge* edge) const
{
	if (edge == nullptr) return false;
	for (auto item : _edges)
	{
		if (item->intersects(edge))
		{
			return true;
		}
	}

	return false;
}

const math::Circle& alg::mesh::MeshTriangle::getCircumcircle() const
{
	return _circumcircle;
}

const math::Vector3& alg::mesh::MeshTriangle::getNormal() const
{
	return _normal;
}

const alg::mesh::MeshEdge* alg::mesh::MeshTriangle::getSharedEdgeWith(const MeshTriangle* triangle) const
{
	if (triangle == nullptr) return false;
	std::vector<int> vecIndices;
	for (size_t i = 0; i < TRIANGLE_VERTEX_AND_EDGE_COUNT; i++)
	{
		if (this->hasVertex(triangle->getVertex(i)))
		{
			vecIndices.push_back(i);
		}
	}
	bool containEdge = vecIndices.size() == 2;
	if (containEdge)
	{
		return triangle->getEdgeByVertex(vecIndices[0], vecIndices[1]);
	}

	return nullptr;
}

bool alg::mesh::MeshTriangle::hasSharedEdgeWith(const MeshTriangle* triangle) const
{
	if (triangle == nullptr) return false;
	std::vector<int> vecIndices;
	for (size_t i = 0; i < TRIANGLE_VERTEX_AND_EDGE_COUNT; i++)
	{
		if (this->hasVertex(triangle->getVertex(i)))
		{
			vecIndices.push_back(i);
		}
	}

	return vecIndices.size() == 2;
}

void alg::mesh::MeshTriangle::decompose()
{
	for (int i = 0; i < TRIANGLE_VERTEX_AND_EDGE_COUNT; i++)
	{
		setEdge(i, nullptr);
	}

	for (int i = 0; i < TRIANGLE_VERTEX_AND_EDGE_COUNT; i++)
	{
		setVertex(i, nullptr);
	}
}

std::set<alg::mesh::MeshTriangle*> alg::mesh::MeshTriangle::getSharedEdgeTriangles()
{
	std::set<MeshTriangle*> neighbors;

	for (auto edge : this->getEdges())
	{
		for (auto triangle : edge->getAdjacentTriangles())
		{
			if (this != triangle)
			{
				neighbors.insert(triangle);
			}
		}
	}

	for (auto vertex : this->getVertexes())
	{
		for (auto triangle : vertex->getAdjacentTriangles())
		{
			if (this != triangle && this->hasSharedEdgeWith(triangle))
			{
				neighbors.insert(triangle);
			}
		}
	}
	return neighbors;
}

bool alg::mesh::MeshTriangle::equal(const MeshTriangle& vertex)
{
	for (size_t i = 0; i < TRIANGLE_VERTEX_AND_EDGE_COUNT; i++)
	{
		if (!this->hasVertex(vertex.getVertex(i)))
		{
			return false;
		}
	}
	return true;
}
