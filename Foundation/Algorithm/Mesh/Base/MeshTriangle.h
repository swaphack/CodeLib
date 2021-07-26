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
	*	����������
	*/
	class MeshTriangle : public MeshProtocol
	{
#define TRIANGLE_VERTEX_AND_EDGE_COUNT 3
	public:
		MeshTriangle();
		MeshTriangle(const math::Vector3& pointA, const math::Vector3& pointB, const math::Vector3& pointC);
		MeshTriangle(const MeshVertex* pVertexA, const MeshVertex* pVertexB, const MeshVertex* pVertexC);
		virtual ~MeshTriangle();
	private:
		/**
		*	���ö���
		*/
		void setVertexes(const math::Vector3& pointA, const math::Vector3& pointB, const math::Vector3& pointC);
		/**
		*	���ö���
		*/
		void setVertexes(const MeshVertex* pVertexA, const MeshVertex* pVertexB, const MeshVertex* pVertexC);
	public:
		/**
		*	�Ƿ��������
		*/
		bool containVertex(const MeshVertex* pVertex) const;
		/**
		*	�Ƿ��������
		*/
		bool containEdge(const MeshEdge* pEdge) const;
		/**
		*	��ȡ����
		*/
		const MeshVertex* getVertex(int index) const;
		/**
		*	��ȡ��
		*/
		const MeshEdge* getEdge(int index) const;
	public:
		/**
		*	�Ƿ����
		*/
		bool equal(const MeshTriangle& vertex);
	protected:
		/**
		*	���ñ�
		*/
		void setEdges(const MeshEdge* pEdgeA, const MeshEdge* pEdgeB, const MeshEdge* pEdgeC);
	private:
		/**
		*	����
		*/
		std::array<MeshVertex*, TRIANGLE_VERTEX_AND_EDGE_COUNT> _vertexes;
		/**
		*	��
		*/
		std::array<MeshEdge*, TRIANGLE_VERTEX_AND_EDGE_COUNT> _edges;
	};
}
