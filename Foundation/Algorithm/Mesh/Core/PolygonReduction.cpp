#include "PolygonReduction.h"
#include "Mesh/Base/import.h"

alg::PolygonReduction::PolygonReduction()
{
	_pointSet = new PointSet();
}

alg::PolygonReduction::~PolygonReduction()
{
	SAFE_RELEASE(_pointSet);
}

float alg::PolygonReduction::getEdgeCost(const MeshVertex* pVertex0, const MeshVertex* pVertex1)
{
	if (pVertex0 == nullptr || pVertex1 == nullptr) return  -1;
	float fMagnitude = (pVertex0->getPosition() - pVertex1->getPosition()).getMagnitude();

	float maxValue = -1;
	for (auto triangle : pVertex0->getAdjacentTriangles())
	{
		float minValue = -1;
		if (triangle->hasVertex(pVertex1))
		{
			float temp = (1.0f - math::Vector3::dot(triangle->getNormal(), triangle->getNormal())) * 0.5f;
			if (minValue == -1 || temp < minValue)
			{
				minValue = temp;
			}
		}

		if (maxValue == -1 || maxValue < minValue)
		{
			maxValue = minValue;
		}
	}

	return maxValue * fMagnitude;
}

void alg::PolygonReduction::updateEdgeCostAtVertex(MeshVertex* pVertex)
{
	if (pVertex == nullptr) return;
	auto pCollapseInfo = getCollapseInfo(pVertex);
	if (pCollapseInfo == nullptr) return;
	if (pVertex->getAdjacentEdges().size() == 0)
	{
		pCollapseInfo->collapse = math::Vector3();
		pCollapseInfo->cost = -0.01f;
		return;
	}

	pCollapseInfo->cost = 1000000;
	pCollapseInfo->collapse = math::Vector3();

	for (auto item : pVertex->getAdjacentEdges())
	{
		auto neighbor = item->getOtherPoint(pVertex);
		float c = getEdgeCost(pVertex, neighbor);
		if (c < pCollapseInfo->cost)
		{
			pCollapseInfo->cost = c;
			pCollapseInfo->collapse = pVertex->getPosition() - neighbor->getPosition();
			pCollapseInfo->edge = _pointSet->createEdge(pVertex, neighbor);
		}
	}
}

void alg::PolygonReduction::collapse(const std::vector<math::TrianglePoints>& triangles)
{
	std::vector<math::Vector3> vertices;
	std::vector<int> indices;

	std::map<std::string, int> pointIndices;

	for (auto item : triangles)
	{
		for (int i = 0; i < 3; i++)
		{
			auto value = item[i];
			auto key = value.toString();
			int index = -1;
			auto it = pointIndices.find(key);
			if (it == pointIndices.end())
			{
				index = (int)pointIndices.size();
				vertices.push_back(value);
				pointIndices[key] = index;
			}
			else
			{
				index = it->second;
			}

			indices.push_back(index);
		}
	}

	this->collapse(vertices, indices);
}

void alg::PolygonReduction::collapse(const std::vector<math::Vector3>& vertices, const std::vector<int>& indices)
{
	_vertexCollapseInfo.clear();

	_pointSet->cleanup();
	_pointSet->setPoints(vertices);

	int count = indices.size() / 3;
	for (int i = 0; i < count; i++)
	{
		_pointSet->createTriangle(indices[i * 3 + 0], indices[i * 3 + 1], indices[i * 3 + 2]);
	}

	for (auto item : _pointSet->getVertexes())
	{
		updateEdgeCostAtVertex(item.second);
	}

	std::vector<CollapseInfo> collapseInfos;

	for (auto item : _vertexCollapseInfo)
	{
		collapseInfos.push_back(item.second);
	}
	
	std::sort(collapseInfos.begin(), collapseInfos.end(), [](const CollapseInfo& a, const CollapseInfo& b) {
		if (a.cost < 0) return true;
		if (b.cost < 0) return false;

		return a.cost < b.cost;
	});

	std::set<MeshTriangle*> removeTraingles;
	std::set<MeshTriangle*> addTraingles;
	for (auto item : collapseInfos)
	{
		removeTraingles.clear();
		addTraingles.clear();
		if (this->canContractEdgeReplaceWithDestVertex(_pointSet, item.edge->getVertex(0), item.edge->getVertex(1), 
			removeTraingles, addTraingles))
		{
			for (auto item : removeTraingles)
			{
				_pointSet->removeTriangle(item);
			}
		}
	}
}

alg::PolygonReduction::CollapseInfo* alg::PolygonReduction::getCollapseInfo(MeshVertex* pVertex)
{
	if (pVertex == nullptr)
	{
		return nullptr;
	}
	auto it = _vertexCollapseInfo.find(pVertex);
	if (it == _vertexCollapseInfo.end())
	{
		_vertexCollapseInfo[pVertex] = CollapseInfo(pVertex);
	}

	return &_vertexCollapseInfo[pVertex];
}
