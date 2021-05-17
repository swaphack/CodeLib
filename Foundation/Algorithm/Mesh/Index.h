#pragma once

#include <vector>
#include <map>
#include "macros.h"

namespace alg
{

	/**
	*	线段索引
	*/
	struct LineIndex
	{
		/**
		*	顶点0索引
		*/
		int VerticeIndex0 = INVALID_INDEX_ID;
		/**
		*	顶点1索引
		*/
		int VerticeIndex1 = INVALID_INDEX_ID;
	public:
		LineIndex(int index0, int index1);
	public:
		/**
		*	是否是相同的线段
		*/
		bool operator==(const LineIndex& target) const;
		/**
		*	是否是相同的线段
		*/
		bool operator!=(const LineIndex& target) const;
	};

	/**
	*	三角形的边的情况
	*/
	struct TriangleIndex
	{	
		/**
		*	顶点索引
		*/
		int VerticeIndex[TRIANGLE_INDEX_COUNT] = { INVALID_INDEX_ID };

		/**
		*	边索引
		*/
		int EdgeIndex[TRIANGLE_INDEX_COUNT] = { INVALID_INDEX_ID };

		/**
		*	边关联三角形索引
		*/
		int EdgeLinkTriangleIndex[TRIANGLE_INDEX_COUNT] = { INVALID_INDEX_ID };

		TriangleIndex& operator=(const TriangleIndex& target);
		/**
		*	所有的边是否都有相邻的三角形
		*/
		bool isAllEdgeLinkToOtherTriangle();

		/**
		*	是否是相同的边
		*/
		bool hasSameEdge(const TriangleIndex& target, std::vector<LineIndex>& outEdges);

		/**
		*	排序
		*/
		static void sort(const TriangleIndex& target, TriangleIndex& outData);
	};
}

