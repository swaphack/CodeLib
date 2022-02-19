#pragma once

#include "mathlib.h"
#include "system.h"
#include <vector>
#include <map>

namespace alg
{
	namespace mesh
	{
		class MeshVertex;
		class MeshEdge;
		class MeshTriangle;
		class MeshPolygon;

		/**
		*	�㼯��
		*/
		class PointSet : public sys::Object
		{
		public:
			PointSet();
			PointSet(const std::vector<math::Vector3>& points);
			virtual ~PointSet();
		public:
			/**
			*	�����㼯
			*/
			static PointSet* create(int count, int width, int height);
		public:
			/**
			*	���ö���
			*/
			void setPoints(const std::vector<math::Vector3>& points);
			/**
			*	��ȡ��
			*/
			const math::Vector3* getPosition(int idx) const;
			/**
			*	��ȡ������
			*/
			int getPointCount() const;
		public:
			/**
			*	��������
			*/
			MeshVertex* createVertex(int idx0);
			/**
			*	��������
			*/
			MeshVertex* createVertex(const math::Vector3& point0);
			/**
			*	�Ƴ�����
			*/
			void removeVertex(MeshVertex* pVertex);
			/**
			*	��ȡ���ж���
			*/
			const std::map<std::string, MeshVertex*>& getVertexes() const;
		public:
			/**
			*	������
			*/
			MeshEdge* createEdge(int idx0, int idx1);
			/**
			*	������
			*/
			MeshEdge* createEdge(const math::Vector3& point0, const math::Vector3& point1);
			/**
			*	������
			*/
			MeshEdge* createEdge(const MeshVertex* pVertex0, const MeshVertex* pVertex1);
			/**
			*	�Ƴ���
			*/
			void removeEdge(MeshEdge* pEdge);
		public:
			/**
			*	����������
			*/
			MeshTriangle* createTriangle(int idx0, int idx1, int idx2);
			/**
			*	����������
			*/
			MeshTriangle* createTriangle(const math::Vector3& point0, const math::Vector3& point1, const math::Vector3& point2);
			/**
			*	����������
			*/
			MeshTriangle* createTriangle(const MeshVertex* pVertex0, const MeshVertex* pVertex1, const MeshVertex* pVertex2);
			/**
			*	����������
			*/
			MeshTriangle* createTriangle(const std::vector<MeshVertex*>& vertexes);
			/**
			*	�Ƴ�������
			*/
			void removeTriangle(MeshTriangle* pTriangle);
			/**
			*	��ȡ����������
			*/
			const std::map<std::string, MeshTriangle*>& getTriangles() const;
			/**
			*	�Ƿ����������
			*/
			bool containTriangle(const math::Vector3& point0, const math::Vector3& point1, const math::Vector3& point2) const;
			/**
			*	�Ƿ����������
			*/
			bool containTriangle(const MeshVertex* vertex0, const MeshVertex* vertex1, const MeshVertex* vertex2) const;
		public:
			/**
			*	���������
			*/
			MeshPolygon* createPolygon(const std::vector<int>& vecIndices);
			/**
			*	���������
			*/
			MeshPolygon* createPolygon(const std::vector<math::Vector3>& vecPoints);
			/**
			*	���������
			*/
			MeshPolygon* createPolygon(const std::vector<MeshVertex* >& vecVertexes);
			/**
			*	�Ƴ������
			*/
			void removePolygon(MeshPolygon* pPolygon);
		public:
			/**
			*	���
			*/
			void cleanup();

		public:
			/**
			*	��ȡ��ֵ
			*/
			static std::string getKey(const MeshVertex* pVertex);
			/**
			*	��ȡ��ֵ
			*/
			static std::string getKey(const MeshVertex* pVertex0, const MeshVertex* pVertex1);
			/**
			*	��ȡ��ֵ
			*/
			static std::string getKey(const MeshVertex* pVertex0, const MeshVertex* pVertex1, const MeshVertex* pVertex2);
			/**
			*	��ȡ��ֵ
			*/
			static std::string getKey(const std::vector<MeshVertex*>& vecVertex);
			/**
			*	��ȡ��ֵ
			*/
			static std::string getKey(const math::Vector3& point);
			/**
			*	��ȡ��ֵ
			*/
			static std::string getKey(const math::Vector3& point0, const math::Vector3& point1);
			/**
			*	��ȡ��ֵ
			*/
			static std::string getKey(const math::Vector3& point0, const math::Vector3& point1, const math::Vector3& point2);
			/**
			*	��ȡ��ֵ
			*/
			static std::string getKey(const std::vector<math::Vector3>& points);
		private:
			/**
			*	��������
			*/
			std::vector<math::Vector3> _vertices;
			/**
			*	����
			*/
			std::map<std::string, MeshVertex*> _meshVertexes;
			/**
			*	��
			*/
			std::map<std::string, MeshEdge*> _meshEdges;
			/**
			*	������
			*/
			std::map<std::string, MeshTriangle*> _meshTriangles;
			/**
			*	�����
			*/
			std::map<std::string, MeshPolygon*> _meshPolygons;
		};
	}
}