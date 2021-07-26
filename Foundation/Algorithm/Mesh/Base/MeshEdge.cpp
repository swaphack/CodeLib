#include "MeshEdge.h"
#include "MeshTriangle.h"
#include "PointSet.h"

alg::MeshEdge::MeshEdge()
{
	for (size_t i = 0; i < EDGE_VERTEX_COUNT; i++)
	{
		_vertexes[i] = nullptr;
	}
}

alg::MeshEdge::MeshEdge(const math::Vector3& pointA, const math::Vector3& pointB)
{
	auto pVertexA = MeshVertex::create(pointA);
	auto pVertexB = MeshVertex::create(pointB);

	this->setVertexes(pVertexA, pVertexB);
}

alg::MeshEdge::MeshEdge(const MeshVertex* pVertexA, const MeshVertex* pVertexB)
{
	this->setVertexes(pVertexA, pVertexB);
}

alg::MeshEdge::~MeshEdge()
{
	for (auto item : _vertexes)
	{
		SAFE_RELEASE(item);
	}
}

alg::MeshEdge* alg::MeshEdge::create(const math::Vector3& pointA, const math::Vector3& pointB)
{
	auto item = CREATE_OBJECT(MeshEdge);
	item->setVertexes(pointA, pointB);
	return item;
}

alg::MeshEdge* alg::MeshEdge::create(const MeshVertex* pVertexA, const MeshVertex* pVertexB)
{
	auto item = CREATE_OBJECT(MeshEdge);
	item->setVertexes(pVertexA, pVertexB);
	return item;
}

void alg::MeshEdge::setVertexes(const math::Vector3& pointA, const math::Vector3& pointB)
{
	MeshVertex* pVertexA = MeshVertex::create(pointA);
	MeshVertex* pVertexB = MeshVertex::create(pointB);

	this->setVertexes(pVertexA, pVertexB);
}

void alg::MeshEdge::setVertexes(const MeshVertex* pVertexA, const MeshVertex* pVertexB)
{
	if (pVertexA == nullptr || pVertexB == nullptr) return;

	auto pA = (MeshVertex*)pVertexA;
	auto pB = (MeshVertex*)pVertexB;

	SAFE_RETAIN(pA);
	SAFE_RETAIN(pB);

	for (auto item : _vertexes)
	{
		SAFE_RELEASE(item);
	}

	_vertexes[0] = pA;
	_vertexes[1] = pB;
}

bool alg::MeshEdge::containVertex(const MeshVertex* pVertex) const
{
	if (pVertex == nullptr) return false;

	for (size_t i = 0; i < EDGE_VERTEX_COUNT; i++)
	{
		if (pVertex->equal(_vertexes[i])) return true;
	}
	return false;
}

const alg::MeshVertex* alg::MeshEdge::getVertex(int index) const
{
	if (index < 0 || index >= EDGE_VERTEX_COUNT) return nullptr;

	return _vertexes[index];
}

void alg::MeshEdge::addSharedPointTriangle(MeshTriangle* edge)
{
	if (edge == nullptr)
	{
		return;
	}
	SAFE_RETAIN(edge);
	_sharedEdgeTriangles.insert(edge);
}

void alg::MeshEdge::removeSharedPointTriangle(MeshTriangle* edge)
{
	if (edge == nullptr)
	{
		return;
	}
	SAFE_RELEASE(edge);
	_sharedEdgeTriangles.erase(edge);
}

const std::set<alg::MeshTriangle*>& alg::MeshEdge::getSharedEdgeTriangles() const
{
	return _sharedEdgeTriangles;
}

std::set<alg::MeshTriangle*>& alg::MeshEdge::getSharedEdgeTriangles()
{
	return _sharedEdgeTriangles;
}

bool alg::MeshEdge::equal(const MeshEdge* pEdge) const
{
	for (size_t i = 0; i < EDGE_VERTEX_COUNT; i++)
	{
		if (!this->containVertex(pEdge->getVertex(i)))
		{
			return false;
		}
	}
	return true;
}
