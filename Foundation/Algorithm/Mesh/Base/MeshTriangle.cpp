#include "MeshTriangle.h"
#include "MeshVertex.h"
#include "MeshEdge.h"
#include "PointSet.h"

alg::MeshTriangle::MeshTriangle(const math::Vector3& pointA, const math::Vector3& pointB, const math::Vector3& pointC)
{
	auto pVertexA = new MeshVertex(pointA);
	auto pVertexB = new MeshVertex(pointB);
	auto pVertexC = new MeshVertex(pointC);

	this->setVertexes(pVertexA, pVertexB, pVertexC);
}

alg::MeshTriangle::MeshTriangle(PointSet* pointSet, const math::Vector3& pointA, const math::Vector3& pointB, const math::Vector3& pointC)
{
	ASSERT(pointSet != nullptr);
	this->setPointSet(pointSet);

	auto pVertexA = pointSet->createVertex(pointA);
	auto pVertexB = pointSet->createVertex(pointB);
	auto pVertexC = pointSet->createVertex(pointC);

	this->setVertexes(pVertexA, pVertexB, pVertexC);
}

alg::MeshTriangle::MeshTriangle(PointSet* pointSet, int idx0, int idx1, int idx2)
{
	ASSERT(pointSet != nullptr);
	this->setPointSet(pointSet);

	auto pVertexA = pointSet->createVertex(idx0);
	auto pVertexB = pointSet->createVertex(idx1);
	auto pVertexC = pointSet->createVertex(idx2);

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

void alg::MeshTriangle::setVertexes(MeshVertex* pVertexA, MeshVertex* pVertexB, MeshVertex* pVertexC)
{
	if (pVertexA == nullptr || pVertexB == nullptr || pVertexC == nullptr) return;

	SAFE_RETAIN(pVertexA);
	SAFE_RETAIN(pVertexB);
	SAFE_RETAIN(pVertexC);

	for (auto item : _vertexes)
	{
		SAFE_RELEASE(item);
	}

	for (auto item : _edges)
	{
		SAFE_RELEASE(item);
	}

	_vertexes[0] = pVertexA;
	_vertexes[1] = pVertexB;
	_vertexes[2] = pVertexC;

	std::sort(_vertexes.begin(), _vertexes.end(), [](const MeshVertex* a, const MeshVertex* b) {
		return math::CompareVec3(a->getPosition(), b->getPosition());
	});

	if (getPointSet() != nullptr)
	{
		auto pEdgeA = getPointSet()->createEdge(_vertexes[0]->getPosition(), _vertexes[1]->getPosition());
		auto pEdgeB = getPointSet()->createEdge(_vertexes[1]->getPosition(), _vertexes[2]->getPosition());
		auto pEdgeC = getPointSet()->createEdge(_vertexes[2]->getPosition(), _vertexes[0]->getPosition());

		this->setEdges(pEdgeA, pEdgeB, pEdgeC);
	}
	else
	{
		auto pEdgeA = new MeshEdge(_vertexes[0]->getPosition(), _vertexes[1]->getPosition());
		auto pEdgeB = new MeshEdge(_vertexes[1]->getPosition(), _vertexes[2]->getPosition());
		auto pEdgeC = new MeshEdge(_vertexes[2]->getPosition(), _vertexes[0]->getPosition());

		this->setEdges(pEdgeA, pEdgeB, pEdgeC);
	}
}

void alg::MeshTriangle::setEdges(MeshEdge* pEdgeA, MeshEdge* pEdgeB, MeshEdge* pEdgeC)
{
	_edges[0] = pEdgeA;
	_edges[1] = pEdgeB;
	_edges[2] = pEdgeC;
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
