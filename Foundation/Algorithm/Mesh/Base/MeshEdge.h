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
		MeshEdge(PointSet* pointSet, const math::Vector3& pointA, const math::Vector3& pointB);
		MeshEdge(const MeshVertex* pVertexA, const MeshVertex* pVertexB);
		virtual ~MeshEdge();
	public:
		/**
		*	���ö���
		*/
		void setVertexes(PointSet* pointSet, const math::Vector3& pointA, const math::Vector3& pointB);
		/**
		*	���ö���
		*/
		void setVertexes(const MeshVertex* pVertexA, const MeshVertex* pVertexB);
	public:
		/**
		*	���ö���
		*/
		void setVertex(int index, const MeshVertex* pVertex);
		/**
		*	�Ƿ��������
		*/
		bool hasVertex(const MeshVertex* pVertex) const;
		/**
		*	��ȡ����
		*/
		const MeshVertex* getVertex(int index) const;
		/**
		*	��ȡ����
		*/
		MeshVertex* getVertex(int index);
		/**
		*	��ȡ����
		*/
		math::Vector3 getPosition(int index) const;
	public:
		/**
		*	��ȡ�߶�
		*/
		const math::LineSegment3d& getLineSegment() const;
		/**
		*	����һ���Ƿ��ཻ
		*/
		bool intersects(const MeshEdge* edge) const;
		/**
		*	�ڽ��������Ƿ��ཻ
		*/
		bool isAdjacentTriangleIntersect() const;
	public:
		/**
		*	��ӹ���������
		*/
		void addAdjacentTriangle(const MeshTriangle* triangle);
		/**
		*	�Ƴ�����������
		*/
		void removeAdjacentTriangle(const MeshTriangle* triangle);
		/**
		*	����������
		*/
		const std::set<MeshTriangle*>& getAdjacentTriangles() const;
		/**
		*	����������
		*/
		std::set<MeshTriangle*>& getAdjacentTriangles();
	public:
		/**
		*	�Ƿ����
		*/
		bool equal(const MeshEdge* pEdge) const;
	public:
		/**
		*	��ȡ����
		*/
		math::Vector3 getDirection(const MeshVertex* destPoint);
		/**
		*	��ȡ����
		*/
		math::Vector3 getDirection(const MeshVertex* destPoint) const;

		/**
		*	��ȡ��һ���˵�
		*/
		MeshVertex* getOtherPoint(const MeshVertex* onePoint) const;

		/**
		*	��ȡ���˵���һ������ͬ�ĵ�
		*/
		MeshVertex* GetOtherPointWithSharedPoint(MeshEdge* edge) const;

		/**
		*	���ҹ���
		*/
		MeshVertex* getSharedPoint(MeshEdge* edge) const;
	private:
		/**
		*	����������
		*/
		std::set<MeshTriangle*> _adjacentTriangles;
		/**
		*  ����
		*/
		std::array<MeshVertex*, EDGE_VERTEX_COUNT> _vertexes;
		/**
		*  �߶�
		*/
		math::LineSegment3d _lineSegment;
	};
}
