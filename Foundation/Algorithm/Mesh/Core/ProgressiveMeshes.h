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
		*	���������㷨
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
			*	���ߣ�����һ�������滻ԭ�ж��㣩
			*	1. Remove any triangles that have both u and v as vertices (that is, remove triangles on the edge uv).
			*	2. Update the remaining triangles that use u as a vertex to use v instead.
			*	3. Remove vertex u.
			*/
			bool canContractEdgeReplaceWithDestVertex(PointSet* pointSet,
				MeshVertex* pSrcVertex, MeshVertex* pDestVertex,
				std::set<MeshTriangle*>& removeTraingles, std::set<MeshTriangle*>& addTraingles);
			/**
			*	���ߣ�����������е��滻�����㣩
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