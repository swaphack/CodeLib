#include "Index.h"
#include "mathlib.h"

/**
*	是否是相同的线段
*/

bool alg::LineIndex::operator==(const LineIndex& target) const
{
	return (target.VerticeIndex0 == VerticeIndex0 && target.VerticeIndex1 == VerticeIndex1)
		|| (target.VerticeIndex0 == VerticeIndex1 && target.VerticeIndex1 == VerticeIndex0);
}

bool alg::LineIndex::operator!=(const LineIndex& target) const
{
	return ! (*this == target);
}

alg::LineIndex::LineIndex(int index0, int index1) :VerticeIndex0(index0), VerticeIndex1(index0)
{

}

alg::TriangleIndex& alg::TriangleIndex::operator=(const TriangleIndex& target)
{
	memcpy(VerticeIndex, target.VerticeIndex, sizeof(VerticeIndex));
	memcpy(EdgeIndex, target.EdgeIndex, sizeof(EdgeIndex));
	memcpy(EdgeLinkTriangleIndex, target.EdgeLinkTriangleIndex, sizeof(EdgeLinkTriangleIndex));

	return *this;
}

bool alg::TriangleIndex::isAllEdgeLinkToOtherTriangle()
{
	for (int i = 0; i < TRIANGLE_INDEX_COUNT; i++)
	{
		if (EdgeLinkTriangleIndex[i] == INVALID_INDEX_ID)
		{
			return false;
		}
	}

	return true;
}

bool alg::TriangleIndex::hasSameEdge(const TriangleIndex& target, std::vector<LineIndex>& outEdges)
{
	return false;
}

void alg::TriangleIndex::sort(const TriangleIndex& target, TriangleIndex& outData)
{
	outData = target;

	std::map<int, int> match;
	for (int i = 0; i < TRIANGLE_INDEX_COUNT; i++)
	{
		match[outData.VerticeIndex[i]] = outData.EdgeLinkTriangleIndex[i];
	}
	std::qsort(outData.VerticeIndex, TRIANGLE_INDEX_COUNT, sizeof(outData.VerticeIndex[0]), math::CompareIntPtr);
	std::qsort(outData.EdgeIndex, TRIANGLE_INDEX_COUNT, sizeof(outData.EdgeIndex[0]), math::CompareIntPtr);
	for (int i = 0; i < TRIANGLE_INDEX_COUNT; i++)
	{
		outData.EdgeLinkTriangleIndex[i] = match[outData.VerticeIndex[i]];
	}
}
