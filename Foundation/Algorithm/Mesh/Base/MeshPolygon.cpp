#include "MeshPolygon.h"
#include "MeshVertex.h"
#include "PointSet.h"

alg::MeshPolygon::MeshPolygon()
{
}

alg::MeshPolygon::MeshPolygon(const std::vector<math::Vector3>& points)
{
	this->setVertexes(points);
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

alg::MeshPolygon* alg::MeshPolygon::create(const std::vector<math::Vector3>& points)
{
	auto item = CREATE_OBJECT(MeshPolygon);
	item->setVertexes(points);
	return item;
}

alg::MeshPolygon* alg::MeshPolygon::create(const std::vector<MeshVertex*>& vertexes)
{
	auto item = CREATE_OBJECT(MeshPolygon);
	item->setVertexes(vertexes);
	return item;
}

void alg::MeshPolygon::setVertexes(const std::vector<math::Vector3>& points)
{
	std::vector<MeshVertex*> vertexes;

	for (auto item : points)
	{
		auto pVertex = MeshVertex::create(item);
		if (pVertex) vertexes.push_back(pVertex);
	}

	this->setVertexes(vertexes);
}

void alg::MeshPolygon::setVertexes(const std::vector<MeshVertex*>& vertexes)
{
	for (auto item : vertexes)
	{
		SAFE_RETAIN(item);
	}
	for (auto item : _vertexes)
	{
		SAFE_RELEASE(item);
	}
	_vertexes = vertexes;
}

bool alg::MeshPolygon::containVertex(const MeshVertex* pVertex) const
{
	if (pVertex == nullptr)  return false;

	for (auto item : _vertexes)
	{
		if (item->equal(pVertex)) return true;
	}
	return false;
}

const alg::MeshVertex* alg::MeshPolygon::getVertex(int index) const
{
	if (index < 0 || index >= _vertexes.size()) return nullptr;

	return _vertexes[index];
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
