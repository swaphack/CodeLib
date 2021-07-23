#include "MeshEdge.h"
#include "MeshTriangle.h"
#include "PointSet.h"

alg::MeshEdge::MeshEdge(const math::Vector3& pointA, const math::Vector3& pointB)
{
	auto pVertexA = new MeshVertex(pointA);
	auto pVertexB = new MeshVertex(pointB);

	this->setVertexes(pVertexA, pVertexB);
}

alg::MeshEdge::MeshEdge(const MeshVertex* pVertexA, const MeshVertex* pVertexB)
{
	this->setVertexes((MeshVertex*)pVertexA, (MeshVertex*)pVertexB);
}

alg::MeshEdge::MeshEdge(PointSet* pointSet, const math::Vector3& pointA, const math::Vector3& pointB)
{
	ASSERT(pointSet != nullptr);
	this->setPointSet(pointSet);
	auto pVertexA = pointSet->createVertex(pointA);
	auto pVertexB = pointSet->createVertex(pointB);

	this->setVertexes(pVertexA, pVertexB);
}

alg::MeshEdge::MeshEdge(PointSet* pointSet, int idx0, int idx1)
{
	ASSERT(pointSet != nullptr);
	this->setPointSet(pointSet);
	auto pVertexA = pointSet->createVertex(idx0);
	auto pVertexB = pointSet->createVertex(idx1);

	this->setVertexes(pVertexA, pVertexB);
}

alg::MeshEdge::~MeshEdge()
{
	for (auto item : _vertexes)
	{
		SAFE_RELEASE(item);
	}
}

void alg::MeshEdge::setVertexes(MeshVertex* pVertexA, MeshVertex* pVertexB)
{
	if (pVertexA == nullptr || pVertexB == nullptr) return;

	SAFE_RETAIN(pVertexA);
	SAFE_RETAIN(pVertexB);

	for (auto item : _vertexes)
	{
		SAFE_RELEASE(item);
	}

	_vertexes[0] = (MeshVertex*)pVertexA;
	_vertexes[1] = (MeshVertex*)pVertexB;

	std::sort(_vertexes.begin(), _vertexes.end(), [](const MeshVertex* a, const MeshVertex* b) {
		return math::CompareVec3(a->getPosition(), b->getPosition());
	});
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
