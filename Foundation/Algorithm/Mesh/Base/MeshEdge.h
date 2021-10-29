#pragma once

#include "mathlib.h"
#include "MeshVertex.h"
#include "MeshProtocol.h"
#include <array>

namespace alg
{
	class MeshTriangle;
	class MeshVertex;
	class PointSet;

	/// <summary>
	/// 网格边
	/// </summary>
	class MeshEdge : public MeshProtocol
	{
#define EDGE_VERTEX_COUNT 2

	public:
		MeshEdge();
		MeshEdge(PointSet* pointSet, const math::Vector3& pointA, const math::Vector3& pointB);
		MeshEdge(const MeshVertex* pVertexA, const MeshVertex* pVertexB);
		virtual ~MeshEdge();
	public:
		/**
		*	设置顶点
		*/
		void setVertexes(PointSet* pointSet, const math::Vector3& pointA, const math::Vector3& pointB);
		/**
		*	设置顶点
		*/
		void setVertexes(const MeshVertex* pVertexA, const MeshVertex* pVertexB);
	public:
		/**
		*	设置顶点
		*/
		void setVertex(int index, const MeshVertex* pVertex);
		/**
		*	是否包含顶点
		*/
		bool hasVertex(const MeshVertex* pVertex) const;
		/**
		*	获取顶点
		*/
		const MeshVertex* getVertex(int index) const;
		/**
		*	获取顶点
		*/
		MeshVertex* getVertex(int index);
		/**
		*	获取坐标
		*/
		math::Vector3 getPosition(int index) const;
	public:
		/**
		*	获取线段
		*/
		const math::LineSegment3d& getLineSegment() const;
		/**
		*	与另一边是否相交
		*/
		bool intersects(const MeshEdge* edge) const;
		/**
		*	邻接三角形是否相交
		*/
		bool isAdjacentTriangleIntersect() const;
	public:
		/**
		*	添加共边三角形
		*/
		void addAdjacentTriangle(const MeshTriangle* triangle);
		/**
		*	移除共边三角形
		*/
		void removeAdjacentTriangle(const MeshTriangle* triangle);
		/**
		*	共边三角形
		*/
		const std::set<MeshTriangle*>& getAdjacentTriangles() const;
		/**
		*	共边三角形
		*/
		std::set<MeshTriangle*>& getAdjacentTriangles();
	public:
		/**
		*	是否相等
		*/
		bool equal(const MeshEdge* pEdge) const;
	public:
		/**
		*	获取方向
		*/
		math::Vector3 getDirection(const MeshVertex* destPoint);
		/**
		*	获取方向
		*/
		math::Vector3 getDirection(const MeshVertex* destPoint) const;

		/**
		*	获取另一个端点
		*/
		MeshVertex* getOtherPoint(const MeshVertex* onePoint) const;

		/**
		*	获取共端点另一个不相同的点
		*/
		MeshVertex* GetOtherPointWithSharedPoint(MeshEdge* edge) const;

		/**
		*	查找共点
		*/
		MeshVertex* getSharedPoint(MeshEdge* edge) const;
	private:
		/**
		*	共边三角形
		*/
		std::set<MeshTriangle*> _adjacentTriangles;
		/**
		*  顶点
		*/
		std::array<MeshVertex*, EDGE_VERTEX_COUNT> _vertexes;
		/**
		*  线段
		*/
		math::LineSegment3d _lineSegment;
	};
}
