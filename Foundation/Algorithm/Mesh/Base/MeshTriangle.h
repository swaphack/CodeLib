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
		MeshTriangle(PointSet* pointSet, const math::Vector3& pointA, const math::Vector3& pointB, const math::Vector3& pointC);
		MeshTriangle(const MeshVertex* pVertexA, const MeshVertex* pVertexB, const MeshVertex* pVertexC);
		virtual ~MeshTriangle();
	public:
		/**
		*	���ö���
		*/
		void setVertexes(PointSet* pointSet, const math::Vector3& pointA, const math::Vector3& pointB, const math::Vector3& pointC);
		/**
		*	���ö���
		*/
		void setVertexes(const MeshVertex* pVertexA, const MeshVertex* pVertexB, const MeshVertex* pVertexC);
	public:
		/**
		*	���ö���
		*/
		void setVertex(int index, const MeshVertex* pVertex);
		/**
		*	��ȡ��������
		*/
		int getIndexOfVertex(const MeshVertex* pVertex) const;
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
		*	��ȡλ��
		*/
		math::Vector3 getPosition(int index) const;
		/**
		*	��ȡ������Ϣ
		*/
		std::array<MeshVertex*, TRIANGLE_VERTEX_AND_EDGE_COUNT>& getVertexes();
		/**
		*	��ȡ������Ϣ
		*/
		const std::array<MeshVertex*, TRIANGLE_VERTEX_AND_EDGE_COUNT>& getVertexes() const;
		/**
		*	��ȡ�����Ķ���˳��
		*/
		std::vector<MeshVertex*> getOrderVertexes(const MeshVertex* pFirstVertex = nullptr, bool bClockWise = true) const;
		/**
		*	��ȡ�����Ķ���˳��
		*/
		std::vector<math::Vector3> getOrderdPositions(bool bClockWise = true) const;
	public:
		/**
		*	���ñ�
		*/
		void setEdge(int index, const MeshEdge* pEdge);
		/**
		*	��ȡ������
		*/
		int getIndexOfEdge(const MeshEdge* pEdge) const;
		/**
		*	�Ƿ��������
		*/
		bool containEdge(const MeshEdge* pEdge) const;
		/**
		*	��ȡ��
		*/
		const MeshEdge* getEdge(int index) const;
		/**
		*	��ȡ��
		*/
		MeshEdge* getEdge(int index);
		/**
		*	��ȡ��
		*/
		const MeshEdge* getEdgeByVertex(int vertexIndex0, int vertexIndex1) const;
		/**
		*	��ȡ��
		*/
		MeshEdge* getEdgeByVertex(int vertexIndex0, int vertexIndex1);
		/**
		*	��ȡ����Ϣ
		*/
		std::array<MeshEdge*, TRIANGLE_VERTEX_AND_EDGE_COUNT>& getEdges();
		/**
		*	��ȡ����Ϣ
		*/
		const std::array<MeshEdge*, TRIANGLE_VERTEX_AND_EDGE_COUNT>& getEdges() const;
	public:
		/**
		*	�Ƿ��ཻ
		*/
		bool intersects(const alg::MeshTriangle* triangle) const;
		/**
		*	�Ƿ��ཻ
		*/
		bool intersects(const alg::MeshEdge* edge) const;
	public:
		/**
		*	��ȡ���Բ
		*/
		const math::Circle& getCircumcircle() const;
		/**
		*	����
		*/
		const math::Vector3& getNormal() const;
		/**
		*	�������������Ƿ��й���
		*/
		const MeshEdge* getSharedEdgeWith(const MeshTriangle* triangle) const;
		/**
		*	�������������Ƿ��й���
		*/
		bool hasSharedEdgeWith(const MeshTriangle* triangle) const;
		/**
		*	�ֽⶥ����ߵĹ�ϵ
		*/
		void decompose();
		/**
		*	��ȡ����������
		*/
		std::set<alg::MeshTriangle*> getSharedEdgeTriangles();
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
		/**
		*	���Բ
		*/
		math::Circle _circumcircle;
		/**
		*	����
		*/
		math::Vector3 _normal;
	};
}
