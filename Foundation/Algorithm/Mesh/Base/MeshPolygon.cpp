#include "MeshPolygon.h"
#include "MeshVertex.h"
#include "MeshEdge.h"
#include "PointSet.h"

alg::MeshPolygon::MeshPolygon()
{
}

alg::MeshPolygon::MeshPolygon(PointSet* pointSet, const std::vector<math::Vector3>& points)
{
	this->setVertexes(pointSet, points);
}

alg::MeshPolygon::MeshPolygon(const std::vector<MeshVertex*>& vertexes)
{
	this->setVertexes(vertexes);
}

alg::MeshPolygon::~MeshPolygon()
{
	for (auto item : _vertexes)
	{
		SAFE_RELEASE(item);
	}
}

void alg::MeshPolygon::setVertexes(PointSet* pointSet, const std::vector<math::Vector3>& points)
{
	if (pointSet == nullptr) return;
	this->setPointSet(pointSet);

	std::vector<MeshVertex*> vertexes;
	for (auto item : points)
	{
		auto pVertex = pointSet->createVertex(item);
		if (pVertex) vertexes.push_back(pVertex);
	}

	this->setVertexes(vertexes);
}

void alg::MeshPolygon::setVertexes(const std::vector<MeshVertex*>& vertexes)
{
	for (int i = 0 ; i < vertexes.size(); i++)
	{
		SAFE_RETAIN(vertexes[i]);
	}
	for (int i = 0; i < _vertexes.size(); i++)
	{
		SAFE_RETAIN(_vertexes[i]);
	}
	_vertexes = vertexes;
}

bool alg::MeshPolygon::hasVertex(const MeshVertex* pVertex) const
{
	if (pVertex == nullptr)  return false;

	for (auto item : _vertexes)
	{
		if (item->equal(pVertex)) return true;
	}
	return false;
}

void alg::MeshPolygon::addVertex(const MeshVertex* pVertex)
{
	if (pVertex == nullptr) return;

	auto it = std::find(_vertexes.begin(), _vertexes.end(), pVertex);
	if (it == _vertexes.end())
	{
		auto vertex = (MeshVertex*)pVertex;
		SAFE_RETAIN(vertex);
		_vertexes.push_back(vertex);
	}
}

void alg::MeshPolygon::removeVertex(const MeshVertex* pVertex)
{
	if (pVertex == nullptr) return;

	auto it = std::find(_vertexes.begin(), _vertexes.end(), pVertex);
	if (it != _vertexes.end())
	{
		auto vertex = (MeshVertex*)pVertex;
		SAFE_RELEASE(vertex);
		_vertexes.erase(it);
	}
}

bool alg::MeshPolygon::containEdge(const MeshEdge* pEdge) const
{
	if (pEdge == nullptr) return false;
	
	int length = _vertexes.size();
	for (int i = 0; i < length; i++)
	{
		auto pVertex = getVertex(i);
		auto pPreVertex = getVertex((i - 1 + length) % length);
		auto pNextVertex = getVertex((i + 1) % length);

		if (pVertex->equal(pEdge->getVertex(0)))
		{
			if (pPreVertex->equal(pEdge->getVertex(1))) return true;
			else if (pNextVertex->equal(pEdge->getVertex(1))) return true;
		}
		if (pVertex->equal(pEdge->getVertex(1)))
		{
			if (pPreVertex->equal(pEdge->getVertex(0))) return true;
			else if (pNextVertex->equal(pEdge->getVertex(0))) return true;
		}
	}

	return false;
}

void alg::MeshPolygon::addEdge(const MeshEdge* pEdge)
{
	if (pEdge == nullptr) return;

	this->addVertex(pEdge->getVertex(0));
	this->addVertex(pEdge->getVertex(1));
}

const alg::MeshVertex* alg::MeshPolygon::getVertex(int index) const
{
	if (index < 0 || index >= _vertexes.size()) return nullptr;

	return _vertexes[index];
}

math::Vector3 alg::MeshPolygon::getPosition(int index) const
{
	auto pVertex = getVertex(index);
	if (pVertex == nullptr) return math::Vector3();
	return pVertex->getPosition();
}

int alg::MeshPolygon::getVertexCount() const
{
	return _vertexes.size();
}

bool alg::MeshPolygon::equal(const MeshPolygon* pPolygon) const
{
	if (pPolygon == nullptr) return false;
	if (pPolygon->getVertexCount() != this->getVertexCount())
	{
		return false;
	}

	int nCount = this->getVertexCount();
	for (size_t i = 0; i < nCount; i++)
	{
		if (!pPolygon->getVertex(i)->equal(this->getVertex(i)))
		{
			return false;
		}
	}

	return true;
}
