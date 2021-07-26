#include "MeshTriangle.h"
#include "MeshVertex.h"
#include "MeshEdge.h"
#include "PointSet.h"

alg::MeshTriangle::MeshTriangle()
{
	for (size_t i = 0; i < TRIANGLE_VERTEX_AND_EDGE_COUNT; i++)
	{
		_vertexes[i] = nullptr;
		_edges[i] = nullptr;
	}
}

alg::MeshTriangle::MeshTriangle(const math::Vector3& pointA, const math::Vector3& pointB, const math::Vector3& pointC)
{
	this->setVertexes(pointA, pointB, pointC);
}

alg::MeshTriangle::MeshTriangle(const MeshVertex* pVertexA, const MeshVertex* pVertexB, const MeshVertex* pVertexC)
{
	this->setVertexes(pVertexA, pVertexB, pVertexC);
}

alg::MeshTriangle::~MeshTriangle()
{
	for (auto item : _vertexes)
	{
		SAFE_RELEASE(item);
	}

	for (auto item : _edges)
	{
		SAFE_RELEASE(item);
	}
}

void alg::MeshTriangle::setVertexes(const math::Vector3& pointA, const math::Vector3& pointB, const math::Vector3& pointC)
{
	auto pVertexA = MeshVertex::create(pointA);
	auto pVertexB = MeshVertex::create(pointB);
	auto pVertexC = MeshVertex::create(pointC);

	this->setVertexes(pVertexA, pVertexB, pVertexC);
}

void alg::MeshTriangle::setVertexes(const MeshVertex* pVertexA, const MeshVertex* pVertexB, const MeshVertex* pVertexC)
{
	if (pVertexA == nullptr || pVertexB == nullptr || pVertexC == nullptr) return;

	auto pA = (MeshVertex*)pVertexA;
	auto pB = (MeshVertex*)pVertexB;
	auto pC = (MeshVertex*)pVertexC;

	SAFE_RETAIN(pA);
	SAFE_RETAIN(pB);
	SAFE_RETAIN(pC);

	for (auto item : _vertexes)
	{
		SAFE_RELEASE(item);
	}

	for (auto item : _edges)
	{
		SAFE_RELEASE(item);
	}

	_vertexes[0] = pA;
	_vertexes[1] = pB;
	_vertexes[2] = pC;

	auto pEdgeA = MeshEdge::create(_vertexes[0], _vertexes[1]);
	auto pEdgeB = MeshEdge::create(_vertexes[1], _vertexes[2]);
	auto pEdgeC = MeshEdge::create(_vertexes[2], _vertexes[0]);

	this->setEdges(pEdgeA, pEdgeB, pEdgeC);
}

void alg::MeshTriangle::setEdges(const MeshEdge* pEdgeA, const MeshEdge* pEdgeB, const MeshEdge* pEdgeC)
{
	auto pA = (MeshEdge*)pEdgeA;
	auto pB = (MeshEdge*)pEdgeB;
	auto pC = (MeshEdge*)pEdgeC;

	SAFE_RETAIN(pA);
	SAFE_RETAIN(pB);
	SAFE_RETAIN(pC);

	for (auto item : _edges)
	{
		SAFE_RELEASE(item);
	}

	_edges[0] = pA;
	_edges[1] = pB;
	_edges[2] = pC;
}

bool alg::MeshTriangle::containVertex(const MeshVertex* pVertex) const
{
	if (pVertex == nullptr) return false;

	for (size_t i = 0; i < TRIANGLE_VERTEX_AND_EDGE_COUNT; i++)
	{
		if (pVertex->equal(_vertexes[i])) return true;
	}
	return false;
}

bool alg::MeshTriangle::containEdge(const MeshEdge* pEdge) const
{
	for (size_t i = 0; i < TRIANGLE_VERTEX_AND_EDGE_COUNT; i++)
	{
		if (pEdge->equal(_edges[i])) return true;
	}
	return false;
}

const alg::MeshVertex* alg::MeshTriangle::getVertex(int index) const
{
	if (index < 0 || index >= TRIANGLE_VERTEX_AND_EDGE_COUNT) return nullptr;

	return _vertexes[index];
}

const alg::MeshEdge* alg::MeshTriangle::getEdge(int index) const
{
	if (index < 0 || index >= TRIANGLE_VERTEX_AND_EDGE_COUNT) return nullptr;

	return _edges[index];
}

bool alg::MeshTriangle::equal(const MeshTriangle& vertex)
{
	for (size_t i = 0; i < TRIANGLE_VERTEX_AND_EDGE_COUNT; i++)
	{
		if (!this->containVertex(vertex.getVertex(i)))
		{
			return false;
		}
	}
	return true;
}
