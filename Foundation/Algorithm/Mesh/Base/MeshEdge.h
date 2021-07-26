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
		MeshEdge();
		MeshEdge(const math::Vector3& pointA, const math::Vector3& pointB);
		MeshEdge(const MeshVertex* pVertexA, const MeshVertex* pVertexB);
		virtual ~MeshEdge();
	public:
		/**
		*	���������
		*/
		static MeshEdge* create(const math::Vector3& pointA, const math::Vector3& pointB);
		/**
		*	���������
		*/
		static MeshEdge* create(const MeshVertex* pVertexA, const MeshVertex* pVertexB);
	public:
		/**
		*	���ö���
		*/
		void setVertexes(const math::Vector3& pointA, const math::Vector3& pointB);
		/**
		*	���ö���
		*/
		void setVertexes(const MeshVertex* pVertexA, const MeshVertex* pVertexB);
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
		void addSharedPointTriangle(const MeshTriangle* edge);
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
