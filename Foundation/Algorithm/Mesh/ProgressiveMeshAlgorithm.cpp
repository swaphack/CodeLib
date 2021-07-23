#include "ProgressiveMeshAlgorithm.h"
#include "macros.h"
#include <map>

/*
alg::ProgressiveMeshAlgorithm::ProgressiveMeshAlgorithm()
{
}

alg::ProgressiveMeshAlgorithm::~ProgressiveMeshAlgorithm()
{
}

bool alg::ProgressiveMeshAlgorithm::reduceMesh(const std::vector<math::Triangle>& inData, std::vector<math::Triangle>& outData)
{
	if (inData.size() <  3)
	{
		return false;
	}

	Mesh inMeshData;
	if (!inMeshData.initWithTriangles(inData))
	{
		return false;
	}

	Mesh outMeshData;

	if (!reduceMesh(inMeshData, outMeshData))
	{
		return false;
	}

	return outMeshData.toTriangles(outData);
}

struct CompareLineIndex
{
	bool operator()(const alg::LineIndex& a, const alg::LineIndex& b) const
	{
		return a == b;
	}

};



bool alg::ProgressiveMeshAlgorithm::reduceMesh(const Mesh& inData, Mesh& outData)
{
	this->cleanUp();

	const std::vector<math::Vector3>& vertices = inData.getVertices();

	const std::vector<int>& indices = inData.getIndices();

	int triangleCount = indices.size() / TRIANGLE_INDEX_COUNT;
	if (triangleCount == 0)
	{
		return false;
	}

	std::vector<TriangleIndex> triangleIndices;
	std::map<LineIndex, int, CompareLineIndex> lineIndices;

	for (size_t i = 0; i < triangleCount; i+=TRIANGLE_INDEX_COUNT)
	{
		TriangleIndex tIndex;

		for (size_t j = 0; j < TRIANGLE_INDEX_COUNT; j++)
		{
			int verticeIndex = indices[i * TRIANGLE_INDEX_COUNT + j];
			tIndex.VerticeIndex[j] = verticeIndex;
			if (j == 1)
			{
				int lastIndex = indices[i * TRIANGLE_INDEX_COUNT + j - 1];

				LineIndex lineIndex(verticeIndex, lastIndex);
				auto it = lineIndices.find(lineIndex);
				//tIndex.EdgeIndex[j - 1] =
			}
		}
	}

	return false;
}

void alg::ProgressiveMeshAlgorithm::cleanUp()
{
	_triangleVertexInfos.clear();
}

*/