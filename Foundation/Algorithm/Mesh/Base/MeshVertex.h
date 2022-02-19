#pragma once

#include "mathlib.h"
#include "system.h"
#include "MeshProtocol.h"
#include <set>

namespace alg
{
	namespace mesh
	{
		class MeshEdge;
		class PointSet;
		class MeshTriangle;

		/**
		*	网格顶点
		*/
		class MeshVertex : public MeshProtocol
		{
		public:
			MeshVertex();
			MeshVertex(const math::Vector3& position);
			virtual ~MeshVertex();
		public:
			/**
			*	位置
			*/
			void setPosition(const math::Vector3& position);
			/**
			*	位置
			*/
			const math::Vector3& getPosition() const;
		public:
			/**
			*	添加共点边
			*/
			void addAdjacentEdge(MeshEdge* edge);
			/**
			*	移除共点边
			*/
			void removeAdjacentEdge(MeshEdge* edge);
			/**
			*	共点边
			*/
			const std::set<MeshEdge*>& getAdjacentEdges() const;
			/**
			*	共点的边
			*/
			std::set<MeshEdge*>& getAdjacentEdges();
		public:
			/**
			*	添加邻边三角形
			*/
			void addAdjacentTriangle(MeshTriangle* triangle);
			/**
			*	移除邻边三角形
			*/
			void removeAdjacentTriangle(MeshTriangle* triangle);
			/**
			*	邻边三角形
			*/
			const std::set<MeshTriangle*>& getAdjacentTriangles() const;
			/**
			*	邻边三角形
			*/
			std::set<MeshTriangle*>& getAdjacentTriangles();
			/**
			*	邻接三角形是否相交
			*/
			bool isAdjacentTriangleIntersect() const;
		public:
			/**
			*	是否相等
			*/
			bool equal(const MeshVertex& vertex) const;
			/**
			*	是否相等
			*/
			bool equal(const MeshVertex* pVertex) const;
		private:
			/**
			*	相邻边
			*/
			std::set<MeshEdge*> _adjacentEdges;
			/**
			*	相邻三角形
			*/
			std::set<MeshTriangle*> _adjacentTriangles;
			/**
			*	位置
			*/
			math::Vector3 _position;
		};
	}
}
