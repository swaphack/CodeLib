#pragma once

#include <vector>
#include <map>
#include <set>

#include "mathlib.h"

namespace alg
{
	namespace mesh
	{
		class MeshVertex;
		class MeshTriangle;
		class PointSet;

		/**
		*	渐进网格算法
		*	@href: http://hhoppe.com/
		*	@href: http://hhoppe.com/pm.pdf
		*
		*/
		class ProgressiveMeshes
		{
		public:
			ProgressiveMeshes();
			~ProgressiveMeshes();
		public:
			/**
			*	减边（用另一个顶点替换原有顶点）
			*	1. Remove any triangles that have both u and v as vertices (that is, remove triangles on the edge uv).
			*	2. Update the remaining triangles that use u as a vertex to use v instead.
			*	3. Remove vertex u.
			*/
			bool canContractEdgeReplaceWithDestVertex(PointSet* pointSet,
				MeshVertex* pSrcVertex, MeshVertex* pDestVertex,
				std::set<MeshTriangle*>& removeTraingles, std::set<MeshTriangle*>& addTraingles);
			/**
			*	减边（用两顶点的中点替换两顶点）
			*/
			bool canContractEdgeReplaceWithMiddleVertex(PointSet* pointSet,
				MeshVertex* pSrcVertex, MeshVertex* pDestVertex,
				std::set<MeshTriangle*>& removeTraingles, std::set<MeshTriangle*>& addTraingles);
		private:
			bool processContractEdgeReplaceWithMiddleVertex(PointSet* pointSet,
				MeshVertex* pSrcVertex, MeshVertex* pDestVertex,
				MeshVertex* pMiddleVertex,
				std::set<MeshTriangle*>& removeTraingles, std::set<MeshTriangle*>& addTraingles);
		};
	}
}