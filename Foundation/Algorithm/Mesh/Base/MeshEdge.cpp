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

alg::MeshEdge::MeshEdge(PointSet* pointSet, const math::Vector3& pointA, const math::Vector3& pointB)
{
	this->setVertexes(pointSet, pointA, pointB);
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

	for (auto item : _adjacentTriangles)
	{
		SAFE_RELEASE(item);
	}
}

void alg::MeshEdge::setVertexes(PointSet* pointSet, const math::Vector3& pointA, const math::Vector3& pointB)
{
	if (pointSet == nullptr) return;
	this->setPointSet(pointSet);
	auto pVertexA = pointSet->createVertex(pointA);
	auto pVertexB = pointSet->createVertex(pointB);

	this->setVertexes(pVertexA, pVertexB);
}

void alg::MeshEdge::setVertexes(const MeshVertex* pVertexA, const MeshVertex* pVertexB)
{
	if (pVertexA == nullptr || pVertexB == nullptr) return;

	this->setVertex(0, pVertexA);
	this->setVertex(1, pVertexB);

	_lineSegment.setSrc(pVertexA->getPosition());
	_lineSegment.setDest(pVertexB->getPosition());
}

void alg::MeshEdge::setVertex(int index, const MeshVertex* pVertex)
{
	if (index < 0 || index >= EDGE_VERTEX_COUNT) return;

	auto vertex = (MeshVertex*)pVertex;

	if (_vertexes[index])
	{
		SAFE_RELEASE(_vertexes[index]);
		_vertexes[index] = nullptr;
	}

	if (vertex)
	{
		SAFE_RETAIN(vertex);
		_vertexes[index] = vertex;
	}
}

bool alg::MeshEdge::hasVertex(const MeshVertex* pVertex) const
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

alg::MeshVertex* alg::MeshEdge::getVertex(int index)
{
	if (index < 0 || index >= EDGE_VERTEX_COUNT) return nullptr;

	return _vertexes[index];
}

math::Vector3 alg::MeshEdge::getPosition(int index) const
{
	auto pVertex = getVertex(index);
	if (pVertex == nullptr) return math::Vector3();
	return pVertex->getPosition();
}

math::Vector3 alg::MeshEdge::getDirection(const MeshVertex* destPoint)
{
	if (_vertexes[0] == nullptr || _vertexes[1] == nullptr || destPoint == nullptr)
	{
		return math::Vector3();
	}

	if (_vertexes[0]->equal(destPoint))
	{
		return _vertexes[0]->getPosition() - _vertexes[1]->getPosition();
	}
	else if (_vertexes[1]->equal(destPoint))
	{
		return _vertexes[1]->getPosition() - _vertexes[0]->getPosition();
	}

	return math::Vector3();
}

const math::LineSegment3d& alg::MeshEdge::getLineSegment() const
{
	return _lineSegment;
}

bool alg::MeshEdge::intersects(const MeshEdge* edge) const 
{
	if (edge == nullptr) return false;
	math::Vector3 point;
	return _lineSegment.intersects(edge->getLineSegment(), point);
}

bool alg::MeshEdge::isAdjacentTriangleIntersect() const
{
	if (_adjacentTriangles.size() > 2)
	{
		return true;
	}
	if (_adjacentTriangles.size() <= 1)
	{
		return false;
	}

	// 如果共边三角形的第三个顶点在同一面，认为相交

	std::vector<math::Vector3> thirdPoints;

	for (auto triangle : _adjacentTriangles)
	{
		for (auto vertex : triangle->getVertexes())
		{
			if (vertex != getVertex(0) && vertex != getVertex(1))
			{
				thirdPoints.push_back(vertex->getPosition());
			}
		}
	}

	int nClockWiseState = 0;
	int nCounterClockWiseState = 0;

	for (auto point : thirdPoints)
	{
		bool ret = math::GeometryUtiity::isClockWise(
			_vertexes[0]->getPosition(), _vertexes[1]->getPosition(), point);

		ret ? nClockWiseState++ : nCounterClockWiseState++;
	}

	return nClockWiseState == nCounterClockWiseState;
}

void alg::MeshEdge::addAdjacentTriangle(const MeshTriangle* triangle)
{
	if (triangle == nullptr)
	{
		return;
	}
	auto pTriangle = (MeshTriangle*)triangle;
	SAFE_RETAIN(pTriangle);

	if (_adjacentTriangles.size() >= 2)
	{
		PRINT("Error: Adjacent Triangles count >= 2");
	}

	for (auto triangle : _adjacentTriangles)
	{
		if (!_pointSet->containTriangle(
			triangle->getVertex(0), 
			triangle->getVertex(1),
			triangle->getVertex(2)))
		{
			PRINT("Error: PointSet exist Adjacent Triangle");
		}
	}

	auto it = _adjacentTriangles.find(pTriangle);
	if (it == _adjacentTriangles.end())
	{
		_adjacentTriangles.insert(pTriangle);
	}
	else
	{
		PRINT("Error: exist same Adjacent Triangles");
	}
}

void alg::MeshEdge::removeAdjacentTriangle(const MeshTriangle* triangle)
{
	if (triangle == nullptr)
	{
		return;
	}
	for (auto triangle : _adjacentTriangles)
	{
		if (!_pointSet->containTriangle(
			triangle->getVertex(0),
			triangle->getVertex(1),
			triangle->getVertex(2)))
		{
			PRINT("Error: PointSet exist Adjacent Triangle");
		}
	}
	if (_adjacentTriangles.size() >= 3)
	{
		PRINT("Error: Adjacent Triangles count >= 3");
	}
	auto pTriangle = (MeshTriangle*)triangle;
	SAFE_RELEASE(pTriangle);
	auto it = _adjacentTriangles.find(pTriangle);
	if (it != _adjacentTriangles.end())
	{
		_adjacentTriangles.erase(it);
	}
	else
	{
		PRINT("Error: not exist Adjacent Triangles");
	}
}

const std::set<alg::MeshTriangle*>& alg::MeshEdge::getAdjacentTriangles() const
{
	return _adjacentTriangles;
}

std::set<alg::MeshTriangle*>& alg::MeshEdge::getAdjacentTriangles()
{
	return _adjacentTriangles;
}

bool alg::MeshEdge::equal(const MeshEdge* pEdge) const
{
	for (size_t i = 0; i < EDGE_VERTEX_COUNT; i++)
	{
		if (!this->hasVertex(pEdge->getVertex(i)))
		{
			return false;
		}
	}
	return true;
}

math::Vector3 alg::MeshEdge::getDirection(const MeshVertex* destPoint) const
{
	math::Vector3 dir;
	if (destPoint == nullptr) return dir;
	if (destPoint->equal(_vertexes[0])) dir = _vertexes[0]->getPosition() - _vertexes[1]->getPosition();
	else if (destPoint->equal(_vertexes[1])) dir = _vertexes[1]->getPosition() - _vertexes[0]->getPosition();

	return dir;
}

/**
*	获取另一个端点
*/

alg::MeshVertex* alg::MeshEdge::getOtherPoint(const MeshVertex* onePoint) const
{
	if (onePoint == nullptr) return nullptr;
	if (onePoint->equal(_vertexes[0]))
	{
		return _vertexes[1];
	}
	else if (onePoint->equal(_vertexes[1]))
	{
		return _vertexes[0];
	}
	return nullptr;
}

/**
*	获取共端点另一个不相同的点
*/

alg::MeshVertex* alg::MeshEdge::GetOtherPointWithSharedPoint(MeshEdge* edge) const
{
	auto point = getSharedPoint(edge);
	if (point == nullptr) return nullptr;
	return getOtherPoint(point);
}

alg::MeshVertex* alg::MeshEdge::getSharedPoint(MeshEdge* edge) const
{
	if (edge == nullptr) return nullptr;
	if (_vertexes[0]->equal(edge->getVertex(0)) || _vertexes[0]->equal(edge->getVertex(1)))
	{
		return _vertexes[0];
	}
	if (_vertexes[1]->equal(edge->getVertex(0)) || _vertexes[1]->equal(edge->getVertex(1)))
	{
		return _vertexes[1];
	}
	return nullptr;
}
