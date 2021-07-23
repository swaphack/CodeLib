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
		MeshTriangle(const math::Vector3& pointA, const math::Vector3& pointB, const math::Vector3& pointC);
		MeshTriangle(PointSet* pointSet, const math::Vector3& pointA, const math::Vector3& pointB, const math::Vector3& pointC);
		MeshTriangle(PointSet* pointSet, int idx0, int idx1, int idx2);
		virtual ~MeshTriangle();
	private:
		/**
		*	���ö���
		*/
		void setVertexes(MeshVertex* pVertexA, MeshVertex* pVertexB, MeshVertex* pVertexC);
		/**
		*	���ñ�
		*/
		void setEdges(MeshEdge* pEdgeA, MeshEdge* pEdgeB, MeshEdge* pEdgeC);
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
