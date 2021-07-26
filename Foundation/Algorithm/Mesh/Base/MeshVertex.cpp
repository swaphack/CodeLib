#include "MeshVertex.h"
#include "MeshEdge.h"

alg::MeshVertex::MeshVertex()
{
}

alg::MeshVertex::MeshVertex(const math::Vector3& position)
{
	_position = position;
}

alg::MeshVertex::~MeshVertex()
{
	for (auto item : _sharedPointEdges)
	{
		SAFE_RELEASE(item);
	}
}

alg::MeshVertex* alg::MeshVertex::create(const math::Vector3& position)
{
	auto pVertex = CREATE_OBJECT(MeshVertex);
	pVertex->setPosition(position);
	return pVertex;
}

void alg::MeshVertex::setPosition(const math::Vector3& position)
{
	_position = position;
}

const math::Vector3& alg::MeshVertex::getPosition() const
{
	return _position;
}

void alg::MeshVertex::addSharedPointEdge(MeshEdge* edge)
{
	if (edge == nullptr)
	{
		return;
	}
	SAFE_RETAIN(edge);
	_sharedPointEdges.insert(edge);
}

void alg::MeshVertex::removeSharedPointEdge(MeshEdge* edge)
{
	if (edge == nullptr)
	{
		return;
	}
	SAFE_RELEASE(edge);
	_sharedPointEdges.erase(edge);
}

const std::set<alg::MeshEdge*>& alg::MeshVertex::getSharedPointEdges() const
{
	return _sharedPointEdges;
}

std::set<alg::MeshEdge*>& alg::MeshVertex::getSharedPointEdges()
{
	return _sharedPointEdges;
}

bool alg::MeshVertex::equal(const MeshVertex& vertex) const
{
	return this->getPosition() == vertex.getPosition();
}

bool alg::MeshVertex::equal(const MeshVertex* pVertex) const
{
	if (pVertex == nullptr) return false;
	return this->getPosition() == pVertex->getPosition();
}
