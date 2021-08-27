#include "MeshVertex.h"
#include "MeshEdge.h"
#include "MeshTriangle.h"

alg::MeshVertex::MeshVertex()
{
}

alg::MeshVertex::MeshVertex(const math::Vector3& position)
{
	_position = position;
}

alg::MeshVertex::~MeshVertex()
{
	for (auto item : _adjacentEdges)
	{
		SAFE_RELEASE(item);
	}

	for (auto item : _adjacentTriangles)
	{
		SAFE_RELEASE(item);
	}
}

void alg::MeshVertex::setPosition(const math::Vector3& position)
{
	_position = position;
}

const math::Vector3& alg::MeshVertex::getPosition() const
{
	return _position;
}

void alg::MeshVertex::addAdjacentEdge(MeshEdge* edge)
{
	if (edge == nullptr)
	{
		return;
	}
	SAFE_RETAIN(edge);
	_adjacentEdges.insert(edge);
}

void alg::MeshVertex::removeAdjacentEdge(MeshEdge* edge)
{
	if (edge == nullptr)
	{
		return;
	}
	SAFE_RELEASE(edge);
	_adjacentEdges.erase(edge);
}

const std::set<alg::MeshEdge*>& alg::MeshVertex::getAdjacentEdges() const
{
	return _adjacentEdges;
}

std::set<alg::MeshEdge*>& alg::MeshVertex::getAdjacentEdges()
{
	return _adjacentEdges;
}

void alg::MeshVertex::addAdjacentTriangle(MeshTriangle* triangle)
{
	if (triangle == nullptr)
	{
		return;
	}
	SAFE_RETAIN(triangle);
	_adjacentTriangles.insert(triangle);
}

void alg::MeshVertex::removeAdjacentTriangle(MeshTriangle* triangle)
{
	if (triangle == nullptr)
	{
		return;
	}
	SAFE_RELEASE(triangle);
	_adjacentTriangles.erase(triangle);
}

const std::set<alg::MeshTriangle*>& alg::MeshVertex::getAdjacentTriangles() const
{
	return _adjacentTriangles;
}

std::set<alg::MeshTriangle*>& alg::MeshVertex::getAdjacentTriangles()
{
	return _adjacentTriangles;
}

bool alg::MeshVertex::isAdjacentTriangleIntersect() const
{
	if (_adjacentEdges.size() > 0)
	{
		for (auto edge : _adjacentEdges)
		{
			if (edge->isAdjacentTriangleIntersect())
			{
				return true;
			}
		}
	}
	
	if (_adjacentTriangles.size() > 0)
	{
		std::set<MeshEdge*> edges;
		for (auto triangle : _adjacentTriangles)
		{
			for (auto edge : triangle->getEdges())
			{
				if (edge->hasVertex(this))
				{
					edges.insert(edge);
				}
			}
		}

		for (auto edge : edges)
		{
			if (edge->isAdjacentTriangleIntersect())
			{
				return true;
			}
		}
	}

	return false;
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
