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
	/// �����
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
		*	���ö���
		*/
		void setVertexes(MeshVertex* pVertexA, MeshVertex* pVertexB);
	public:
		/**
		*	�Ƿ��������
		*/
		bool containVertex(const MeshVertex* pVertex) const;
		/**
		*	��ȡ����
		*/
		const MeshVertex* getVertex(int index) const;
	public:
		/**
		*	��ӹ���������
		*/
		void addSharedPointTriangle(MeshTriangle* edge);
		/**
		*	�Ƴ�����������
		*/
		void removeSharedPointTriangle(MeshTriangle* edge);
		/**
		*	����������
		*/
		const std::set<MeshTriangle*>& getSharedEdgeTriangles() const;
		/**
		*	����������
		*/
		std::set<MeshTriangle*>& getSharedEdgeTriangles();
	public:
		/**
		*	�Ƿ����
		*/
		bool equal(const MeshEdge* pEdge) const;
	private:
		/**
		*	����������
		*/
		std::set<MeshTriangle*> _sharedEdgeTriangles;
		/**
		*  ����
		*/
		std::array<MeshVertex*, EDGE_VERTEX_COUNT> _vertexes;
	};
}
