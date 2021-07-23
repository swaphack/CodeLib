#pragma once

#include <vector>
#include <map>
#include <set>

#include "mathlib.h"

#include "Base/import.h"

namespace alg
{
	/*  渐进网格算法
	*	@href: http://hhoppe.com/
	*
	*/
	class ProgressiveMeshAlgorithm
	{
	public:
		ProgressiveMeshAlgorithm();
		~ProgressiveMeshAlgorithm();
	public:
		/**
		*	减面
		*/
		bool reduceMesh(const std::vector<math::Triangle>& inData, std::vector<math::Triangle>& outData);
		/**
		*	减面 未完成
		*/
		bool reduceMesh(const Mesh& inData, Mesh& outData);
	protected:
		/**
		*	清空
		*/
		void cleanUp();
	private:
		/**
		*	三角形的三个边与其他三角形共边的情况
		*/
		//std::map<int, TriangleEdge> _triangleEdgeInfos;

		/**
		*	每个顶点关联的三角形
		*/
		std::map<math::Vector3, std::set<int>, math::CompareVector3> _triangleVertexInfos;
	};
}