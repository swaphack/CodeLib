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
		MeshPolygon();
		MeshPolygon(const std::vector<math::Vector3>& points);
		MeshPolygon(const std::vector<MeshVertex*>& vertexes);
		virtual ~MeshPolygon();
	public:
		static MeshPolygon* create(const std::vector<math::Vector3>& points);
		static MeshPolygon* create(const std::vector<MeshVertex*>& vertexes);
	public:
		/**
		*	���ö���
		*/
		void setVertexes(const std::vector<math::Vector3>& points);
		/**
		*	���ö���
		*/
		void setVertexes(const std::vector<MeshVertex*>& vertexes);
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
