#include "ProgressiveMeshes.h"
#include "Mesh/Base/import.h"

alg::mesh::ProgressiveMeshes::ProgressiveMeshes()
{
}

alg::mesh::ProgressiveMeshes::~ProgressiveMeshes()
{
}

bool alg::mesh::ProgressiveMeshes::canContractEdgeReplaceWithDestVertex(
	PointSet* pointSet, 
	MeshVertex* pSrcVertex, MeshVertex* pDestVertex,
	std::set<MeshTriangle*>& removeTraingles, std::set<MeshTriangle*>& addTraingles)
{
	if (pointSet == nullptr || pSrcVertex == nullptr || pDestVertex == nullptr) return false;

	
	for (auto triangle : pSrcVertex->getAdjacentTriangles())
	{
		// 移除顶点关联的三角形
		removeTraingles.insert(triangle);

		if (!triangle->hasVertex(pDestVertex))
		{
			// 生成新三角形
			auto vertexes = triangle->getVertexes();
			std::vector<MeshVertex*> vecVertex;
			for (auto item : vertexes)
			{
				if (item != pSrcVertex)
					vecVertex.push_back(item);
			}
			MeshTriangle* pTriangle = pointSet->createTriangle(vecVertex[0], vecVertex[1], pDestVertex);
			addTraingles.insert(pTriangle);
		}
	}

	for (auto triangle : removeTraingles)
	{
		pointSet->removeTriangle(triangle);
	}
	bool ret = true;
	for (auto triangle : addTraingles)
	{
		for (auto edge : triangle->getEdges())
		{
			if (edge->isAdjacentTriangleIntersect())
			{
				ret = false;
				break;
			}
		}

		if (!ret) break;
	}

	if (!ret)
	{
		for (auto triangle : addTraingles)
		{
			pointSet->removeTriangle(triangle);
		}
		for (auto triangle : removeTraingles)
		{
			pointSet->createTriangle(triangle->getVertex(0), triangle->getVertex(1), triangle->getVertex(2));
		}
		removeTraingles.clear();
		addTraingles.clear();
	}

	return ret;
}

bool alg::mesh::ProgressiveMeshes::canContractEdgeReplaceWithMiddleVertex(
	PointSet* pointSet,
	MeshVertex* pSrcVertex, MeshVertex* pDestVertex,
	std::set<MeshTriangle*>& removeTraingles, std::set<MeshTriangle*>& addTraingles)
{
	if (pointSet == nullptr || pSrcVertex == nullptr || pDestVertex == nullptr) return false;

	auto middlePosition = 0.5f * (pSrcVertex->getPosition() + pDestVertex->getPosition());
	auto pMiddleVertex = pointSet->createVertex(middlePosition);

	if (!processContractEdgeReplaceWithMiddleVertex(
		pointSet,
		pSrcVertex, pDestVertex, pMiddleVertex,
		removeTraingles, addTraingles))
	{
		pointSet->removeVertex(pMiddleVertex);
		return false;
	}

	if (!processContractEdgeReplaceWithMiddleVertex(
		pointSet,
		pDestVertex, pSrcVertex, pMiddleVertex,
		removeTraingles, addTraingles))
	{
		pointSet->removeVertex(pMiddleVertex);
		return false;
	}
	return true;
}

bool alg::mesh::ProgressiveMeshes::processContractEdgeReplaceWithMiddleVertex(
	PointSet* pointSet, 
	MeshVertex* pSrcVertex, MeshVertex* pDestVertex, 
	MeshVertex* pMiddleVertex, 
	std::set<MeshTriangle*>& removeTraingles, std::set<MeshTriangle*>& addTraingles)
{
	if (pointSet == nullptr || pSrcVertex == nullptr || pDestVertex == nullptr || pMiddleVertex == nullptr) return false;

	for (auto triangle : pSrcVertex->getAdjacentTriangles())
	{
		// 移除顶点关联的三角形
		removeTraingles.insert(triangle);

		if (!triangle->hasVertex(pDestVertex))
		{
			// 生成新三角形
			auto vertexes = triangle->getVertexes();
			std::vector<MeshVertex*> vecVertex;
			for (auto item : vertexes)
			{
				if (item != pSrcVertex)
					vecVertex.push_back(item);
			}
			MeshTriangle* pTriangle = pointSet->createTriangle(vecVertex[0], vecVertex[1], pMiddleVertex);
			addTraingles.insert(pTriangle);
		}
	}

	for (auto triangle : removeTraingles)
	{
		pointSet->removeTriangle(triangle);
	}
	bool ret = true;
	for (auto triangle : addTraingles)
	{
		for (auto edge : triangle->getEdges())
		{
			if (edge->isAdjacentTriangleIntersect())
			{
				ret = false;
				break;
			}
		}

		if (!ret) break;
	}

	if (!ret)
	{
		for (auto triangle : addTraingles)
		{
			pointSet->removeTriangle(triangle);
		}
		for (auto triangle : removeTraingles)
		{
			pointSet->createTriangle(triangle->getVertex(0), triangle->getVertex(1), triangle->getVertex(2));
		}
		removeTraingles.clear();
		addTraingles.clear();
		return false;
	}

	return true;
}

