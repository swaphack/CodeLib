#include "MeshPolygon.h"
#include "MeshVertex.h"
#include "PointSet.h"

alg::MeshPolygon::MeshPolygon(const std::vector<math::Vector3>& points)
{
	std::vector<MeshVertex*> vertexes;

	for (auto item : points)
	{
		auto pVertex = new MeshVertex(item);
		if (pVertex) vertexes.push_back(pVertex);
	}

	this->setVertexes(vertexes);
}

alg::MeshPolygon::MeshPolygon(PointSet* pointSet, const std::vector<math::Vector3>& points)
{
	ASSERT(pointSet != nullptr);
	this->setPointSet(pointSet);

	std::vector<MeshVertex*> vertexes;
	for (auto item : points)
	{
		auto pVertex = pointSet->createVertex(item);
		if (pVertex) vertexes.push_back(pVertex);
	}

	this->setVertexes(vertexes);
}

alg::MeshPolygon::MeshPolygon(PointSet* pointSet, const std::vector<int>& indices)
{
	ASSERT(pointSet != nullptr);
	this->setPointSet(pointSet);

	std::vector<MeshVertex*> vertexes;
	for (auto item : indices)
	{
		auto pVertex = pointSet->createVertex(item);
		if (pVertex) vertexes.push_back(pVertex);
	}

	this->setVertexes(vertexes);
}

alg::MeshPolygon::~MeshPolygon()
{
	for (auto item : _vertexes)
	{
		SAFE_RELEASE(item);
	}
}

void alg::MeshPolygon::setVertexes(std::vector<MeshVertex*>& vertexes)
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
	std::sort(_vertexes.begin(), _vertexes.end(), [](const MeshVertex* a, const MeshVertex* b) {
		return math::CompareVec3(a->getPosition(), b->getPosition());
	});
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
