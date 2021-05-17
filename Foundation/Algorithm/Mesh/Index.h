#pragma once

#include <vector>
#include <map>
#include "macros.h"

namespace alg
{

	/**
	*	�߶�����
	*/
	struct LineIndex
	{
		/**
		*	����0����
		*/
		int VerticeIndex0 = INVALID_INDEX_ID;
		/**
		*	����1����
		*/
		int VerticeIndex1 = INVALID_INDEX_ID;
	public:
		LineIndex(int index0, int index1);
	public:
		/**
		*	�Ƿ�����ͬ���߶�
		*/
		bool operator==(const LineIndex& target) const;
		/**
		*	�Ƿ�����ͬ���߶�
		*/
		bool operator!=(const LineIndex& target) const;
	};

	/**
	*	�����εıߵ����
	*/
	struct TriangleIndex
	{	
		/**
		*	��������
		*/
		int VerticeIndex[TRIANGLE_INDEX_COUNT] = { INVALID_INDEX_ID };

		/**
		*	������
		*/
		int EdgeIndex[TRIANGLE_INDEX_COUNT] = { INVALID_INDEX_ID };

		/**
		*	�߹�������������
		*/
		int EdgeLinkTriangleIndex[TRIANGLE_INDEX_COUNT] = { INVALID_INDEX_ID };

		TriangleIndex& operator=(const TriangleIndex& target);
		/**
		*	���еı��Ƿ������ڵ�������
		*/
		bool isAllEdgeLinkToOtherTriangle();

		/**
		*	�Ƿ�����ͬ�ı�
		*/
		bool hasSameEdge(const TriangleIndex& target, std::vector<LineIndex>& outEdges);

		/**
		*	����
		*/
		static void sort(const TriangleIndex& target, TriangleIndex& outData);
	};
}

