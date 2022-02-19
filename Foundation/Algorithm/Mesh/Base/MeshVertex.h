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
		*	���񶥵�
		*/
		class MeshVertex : public MeshProtocol
		{
		public:
			MeshVertex();
			MeshVertex(const math::Vector3& position);
			virtual ~MeshVertex();
		public:
			/**
			*	λ��
			*/
			void setPosition(const math::Vector3& position);
			/**
			*	λ��
			*/
			const math::Vector3& getPosition() const;
		public:
			/**
			*	��ӹ����
			*/
			void addAdjacentEdge(MeshEdge* edge);
			/**
			*	�Ƴ������
			*/
			void removeAdjacentEdge(MeshEdge* edge);
			/**
			*	�����
			*/
			const std::set<MeshEdge*>& getAdjacentEdges() const;
			/**
			*	����ı�
			*/
			std::set<MeshEdge*>& getAdjacentEdges();
		public:
			/**
			*	����ڱ�������
			*/
			void addAdjacentTriangle(MeshTriangle* triangle);
			/**
			*	�Ƴ��ڱ�������
			*/
			void removeAdjacentTriangle(MeshTriangle* triangle);
			/**
			*	�ڱ�������
			*/
			const std::set<MeshTriangle*>& getAdjacentTriangles() const;
			/**
			*	�ڱ�������
			*/
			std::set<MeshTriangle*>& getAdjacentTriangles();
			/**
			*	�ڽ��������Ƿ��ཻ
			*/
			bool isAdjacentTriangleIntersect() const;
		public:
			/**
			*	�Ƿ����
			*/
			bool equal(const MeshVertex& vertex) const;
			/**
			*	�Ƿ����
			*/
			bool equal(const MeshVertex* pVertex) const;
		private:
			/**
			*	���ڱ�
			*/
			std::set<MeshEdge*> _adjacentEdges;
			/**
			*	����������
			*/
			std::set<MeshTriangle*> _adjacentTriangles;
			/**
			*	λ��
			*/
			math::Vector3 _position;
		};
	}
}
