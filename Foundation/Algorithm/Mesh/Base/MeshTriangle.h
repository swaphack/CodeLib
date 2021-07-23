#pragma once

#include "mathlib.h"
#include "MeshProtocol.h"
#include <array>
namespace alg
{
	class MeshVertex;
	class MeshEdge;
	class PointSet;

	/**
	*	网格三角形
	*/
	class MeshTriangle : public MeshProtocol
	{
#define TRIANGLE_VERTEX_AND_EDGE_COUNT 3
	public:
		MeshTriangle(const math::Vector3& pointA, const math::Vector3& pointB, const math::Vector3& pointC);
		MeshTriangle(PointSet* pointSet, const math::Vector3& pointA, const math::Vector3& pointB, const math::Vector3& pointC);
		MeshTriangle(PointSet* pointSet, int idx0, int idx1, int idx2);
		virtual ~MeshTriangle();
	private:
		/**
		*	设置顶点
		*/
		void setVertexes(MeshVertex* pVertexA, MeshVertex* pVertexB, MeshVertex* pVertexC);
		/**
		*	设置边
		*/
		void setEdges(MeshEdge* pEdgeA, MeshEdge* pEdgeB, MeshEdge* pEdgeC);
	public:
		/**
		*	是否包含顶点
		*/
		bool containVertex(const MeshVertex* pVertex) const;
		/**
		*	是否包含顶点
		*/
		bool containEdge(const MeshEdge* pEdge) const;
		/**
		*	获取顶点
		*/
		const MeshVertex* getVertex(int index) const;
		/**
		*	获取边
		*/
		const MeshEdge* getEdge(int index) const;
	public:
		/**
		*	是否相等
		*/
		bool equal(const MeshTriangle& vertex);
	private:
		/**
		*	顶点
		*/
		std::array<MeshVertex*, TRIANGLE_VERTEX_AND_EDGE_COUNT> _vertexes;
		/**
		*	边
		*/
		std::array<MeshEdge*, TRIANGLE_VERTEX_AND_EDGE_COUNT> _edges;
	};
}
