#pragma once


#include "mathlib.h"
#include "MeshProtocol.h"

namespace alg
{
	namespace mesh
	{
		class MeshTriangle;
		class MeshVertex;
		class MeshEdge;
		class PointSet;

		/// <summary>
		/// ��������
		/// </summary>
		class MeshPolygon : public MeshProtocol
		{
		public:
			MeshPolygon();
			MeshPolygon(PointSet* pointSet, const std::vector<math::Vector3>& points);
			MeshPolygon(const std::vector<MeshVertex*>& vertexes);
			virtual ~MeshPolygon();
		public:
			/**
			*	���ö���
			*/
			void setVertexes(PointSet* pointSet, const std::vector<math::Vector3>& points);
			/**
			*	���ö���
			*/
			void setVertexes(const std::vector<MeshVertex*>& vertexes);
		public:
			/**
			*	�Ƿ��������
			*/
			bool hasVertex(const MeshVertex* pVertex) const;
			/**
			*	��Ӷ���
			*/
			void addVertex(const MeshVertex* pVertex);
			/**
			*	�Ƴ�����
			*/
			void removeVertex(const MeshVertex* pVertex);
			/**
			*	��ȡ����
			*/
			const MeshVertex* getVertex(int index) const;
			/**
			*	��ȡ������
			*/
			math::Vector3 getPosition(int index) const;
			/**
			*	�������
			*/
			int getVertexCount() const;
		public:
			/**
			*	�Ƿ������
			*/
			bool containEdge(const MeshEdge* pEdge) const;
			/**
			*	��ӱ�
			*/
			void addEdge(const MeshEdge* pEdge);
		public:
			/**
			*	�Ƿ����
			*/
			bool equal(const MeshPolygon* pPolygon) const;
		private:
			/**
			*  ����
			*/
			std::vector<MeshVertex*> _vertexes;
		};
	}
}
