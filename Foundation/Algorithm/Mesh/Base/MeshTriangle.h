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
		MeshTriangle();
		MeshTriangle(PointSet* pointSet, const math::Vector3& pointA, const math::Vector3& pointB, const math::Vector3& pointC);
		MeshTriangle(const MeshVertex* pVertexA, const MeshVertex* pVertexB, const MeshVertex* pVertexC);
		virtual ~MeshTriangle();
	public:
		/**
		*	设置顶点
		*/
		void setVertexes(PointSet* pointSet, const math::Vector3& pointA, const math::Vector3& pointB, const math::Vector3& pointC);
		/**
		*	设置顶点
		*/
		void setVertexes(const MeshVertex* pVertexA, const MeshVertex* pVertexB, const MeshVertex* pVertexC);
	public:
		/**
		*	设置顶点
		*/
		void setVertex(int index, const MeshVertex* pVertex);
		/**
		*	获取顶点索引
		*/
		int getIndexOfVertex(const MeshVertex* pVertex) const;
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
		*	获取位置
		*/
		math::Vector3 getPosition(int index) const;
		/**
		*	获取顶点信息
		*/
		std::array<MeshVertex*, TRIANGLE_VERTEX_AND_EDGE_COUNT>& getVertexes();
		/**
		*	获取顶点信息
		*/
		const std::array<MeshVertex*, TRIANGLE_VERTEX_AND_EDGE_COUNT>& getVertexes() const;
		/**
		*	获取排序后的顶点顺序
		*/
		std::vector<MeshVertex*> getOrderVertexes(const MeshVertex* pFirstVertex = nullptr, bool bClockWise = true) const;
		/**
		*	获取排序后的顶点顺序
		*/
		std::vector<math::Vector3> getOrderdPositions(bool bClockWise = true) const;
	public:
		/**
		*	设置边
		*/
		void setEdge(int index, const MeshEdge* pEdge);
		/**
		*	获取边索引
		*/
		int getIndexOfEdge(const MeshEdge* pEdge) const;
		/**
		*	是否包含顶点
		*/
		bool containEdge(const MeshEdge* pEdge) const;
		/**
		*	获取边
		*/
		const MeshEdge* getEdge(int index) const;
		/**
		*	获取边
		*/
		MeshEdge* getEdge(int index);
		/**
		*	获取边
		*/
		const MeshEdge* getEdgeByVertex(int vertexIndex0, int vertexIndex1) const;
		/**
		*	获取边
		*/
		MeshEdge* getEdgeByVertex(int vertexIndex0, int vertexIndex1);
		/**
		*	获取边信息
		*/
		std::array<MeshEdge*, TRIANGLE_VERTEX_AND_EDGE_COUNT>& getEdges();
		/**
		*	获取边信息
		*/
		const std::array<MeshEdge*, TRIANGLE_VERTEX_AND_EDGE_COUNT>& getEdges() const;
	public:
		/**
		*	是否相交
		*/
		bool intersects(const alg::MeshTriangle* triangle) const;
		/**
		*	是否相交
		*/
		bool intersects(const alg::MeshEdge* edge) const;
	public:
		/**
		*	获取外接圆
		*/
		const math::Circle& getCircumcircle() const;
		/**
		*	法线
		*/
		const math::Vector3& getNormal() const;
		/**
		*	与另外三角形是否有共边
		*/
		const MeshEdge* getSharedEdgeWith(const MeshTriangle* triangle) const;
		/**
		*	与另外三角形是否有共边
		*/
		bool hasSharedEdgeWith(const MeshTriangle* triangle) const;
		/**
		*	分解顶点与边的关系
		*/
		void decompose();
		/**
		*	获取共边三角形
		*/
		std::set<alg::MeshTriangle*> getSharedEdgeTriangles();
	public:
		/**
		*	是否相等
		*/
		bool equal(const MeshTriangle& vertex);
	protected:
		/**
		*	设置边
		*/
		void setEdges(const MeshEdge* pEdgeA, const MeshEdge* pEdgeB, const MeshEdge* pEdgeC);
	private:
		/**
		*	顶点
		*/
		std::array<MeshVertex*, TRIANGLE_VERTEX_AND_EDGE_COUNT> _vertexes;
		/**
		*	边
		*/
		std::array<MeshEdge*, TRIANGLE_VERTEX_AND_EDGE_COUNT> _edges;
		/**
		*	外接圆
		*/
		math::Circle _circumcircle;
		/**
		*	法线
		*/
		math::Vector3 _normal;
	};
}
