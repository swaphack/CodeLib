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
	*	多边形减少算法
	*	合并点
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
		*	获取估价
		*	-1无效值
		*/
		float getEdgeCost(const MeshVertex* pVertex0, const MeshVertex* pVertex1);
		/**
		*	更新点的估价
		*/
		void updateEdgeCostAtVertex(MeshVertex* pVertex);
	public:
		/**
		*	坍塌
		*/
		void collapse(const std::vector<math::TrianglePoints>& triangles);
		/**
		*	坍塌
		*/
		void collapse(const std::vector<math::Vector3>& vertices, const std::vector<int>& indices);
	private:
		/**
		*	获取信息
		*/
		CollapseInfo* getCollapseInfo(MeshVertex* pVertex);
	private:
		/**
		*	点集合
		*/
		PointSet* _pointSet = nullptr;
		/**
		*	顶点估价
		*/
		std::map<MeshVertex*, CollapseInfo> _vertexCollapseInfo;
	};
}