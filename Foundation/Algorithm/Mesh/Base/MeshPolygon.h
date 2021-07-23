#pragma once


#include "mathlib.h"
#include "MeshProtocol.h"

namespace alg
{
	class MeshTriangle;
	class MeshVertex;
	class PointSet;

	/// <summary>
	/// ��������
	/// </summary>
	class MeshPolygon : public MeshProtocol
	{
	public:
		MeshPolygon(const std::vector<math::Vector3>& points);
		MeshPolygon(PointSet* pointSet, const std::vector<math::Vector3>& points);
		MeshPolygon(PointSet* pointSet, const std::vector<int>& indices);
		virtual ~MeshPolygon();
	public:
		/**
		*	���ö���
		*/
		void setVertexes(std::vector<MeshVertex*>& vertexes);
	public:
		/**
		*	�Ƿ��������
		*/
		bool containVertex(const MeshVertex* pVertex) const;
		/**
		*	��ȡ����
		*/
		const MeshVertex* getVertex(int index) const;
		/**
		*	�������
		*/
		int getVertexCount() const;
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
