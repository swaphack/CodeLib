#pragma once

#include "mathlib.h"
#include <vector>
#include <map>

namespace alg
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
		const math::Vector3* getPoint(int idx) const;
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
		*	�Ƴ�������
		*/
		void removeTriangle(MeshTriangle* pTriangle);
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
		*	�Ƴ������
		*/
		void removePolygon(MeshPolygon* pPolygon);
	public:
		/**
		*	���
		*/
		void cleanup();
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