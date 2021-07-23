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
		MeshEdge(const math::Vector3& pointA, const math::Vector3& pointB);
		MeshEdge(const MeshVertex* pVertexA, const MeshVertex* pVertexB);
		MeshEdge(PointSet* pointSet, const math::Vector3& pointA, const math::Vector3& pointB);
		MeshEdge(PointSet* pointSet, int idx0, int idx1);
		virtual ~MeshEdge();
	public:
		/**
		*	设置顶点
		*/
		void setVertexes(MeshVertex* pVertexA, MeshVertex* pVertexB);
	public:
		/**
		*	是否包含顶点
		*/
		bool containVertex(const MeshVertex* pVertex) const;
		/**
		*	获取顶点
		*/
		const MeshVertex* getVertex(int index) const;
	public:
		/**
		*	添加共边三角形
		*/
		void addSharedPointTriangle(MeshTriangle* edge);
		/**
		*	移除共边三角形
		*/
		void removeSharedPointTriangle(MeshTriangle* edge);
		/**
		*	共边三角形
		*/
		const std::set<MeshTriangle*>& getSharedEdgeTriangles() const;
		/**
		*	共边三角形
		*/
		std::set<MeshTriangle*>& getSharedEdgeTriangles();
	public:
		/**
		*	是否相等
		*/
		bool equal(const MeshEdge* pEdge) const;
	private:
		/**
		*	共边三角形
		*/
		std::set<MeshTriangle*> _sharedEdgeTriangles;
		/**
		*  顶点
		*/
		std::array<MeshVertex*, EDGE_VERTEX_COUNT> _vertexes;
	};
}
