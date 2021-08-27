#pragma once

#include <vector>
#include <map>
#include <set>

#include "mathlib.h"
#include "ProgressiveMeshes.h"

namespace alg
{
	class MeshVertex;
	class MeshEdge;
	class MeshTriangle;
	class PointSet;

	/**
	*	����μ����㷨
	*	�ϲ���
	*
	*/
	class PolygonReduction : public ProgressiveMeshes
	{
		struct CollapseInfo
		{
			math::Vector3 collapse;
			float cost = 0;
			MeshVertex* vertex = nullptr;
			MeshEdge* edge = nullptr;

			CollapseInfo() {}
			CollapseInfo(MeshVertex* pVertex) :vertex(pVertex) {}
		};
	public:
		PolygonReduction();
		~PolygonReduction();
	public:
		/**
		*	��ȡ����
		*	-1��Чֵ
		*/
		float getEdgeCost(const MeshVertex* pVertex0, const MeshVertex* pVertex1);
		/**
		*	���µ�Ĺ���
		*/
		void updateEdgeCostAtVertex(MeshVertex* pVertex);
	public:
		/**
		*	̮��
		*/
		void collapse(const std::vector<math::TrianglePoints>& triangles);
		/**
		*	̮��
		*/
		void collapse(const std::vector<math::Vector3>& vertices, const std::vector<int>& indices);
	private:
		/**
		*	��ȡ��Ϣ
		*/
		CollapseInfo* getCollapseInfo(MeshVertex* pVertex);
	private:
		/**
		*	�㼯��
		*/
		PointSet* _pointSet = nullptr;
		/**
		*	�������
		*/
		std::map<MeshVertex*, CollapseInfo> _vertexCollapseInfo;
	};
}