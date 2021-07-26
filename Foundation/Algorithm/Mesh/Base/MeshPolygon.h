#pragma once


#include "mathlib.h"
#include "MeshProtocol.h"

namespace alg
{
	class MeshTriangle;
	class MeshVertex;
	class PointSet;

	/// <summary>
	/// 网格多边形
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
		*	设置顶点
		*/
		void setVertexes(const std::vector<math::Vector3>& points);
		/**
		*	设置顶点
		*/
		void setVertexes(const std::vector<MeshVertex*>& vertexes);
	public:
		/**
		*	是否包含顶点
		*/
		bool containVertex(const MeshVertex* pVertex) const;
		/**
		*	获取顶点
		*/
		const MeshVertex* getVertex(int index) const;
		/**
		*	顶点个数
		*/
		int getVertexCount() const;
	public:
		/**
		*	是否相等
		*/
		bool equal(const MeshPolygon* pPolygon) const;
	private:
		/**
		*  顶点
		*/
		std::vector<MeshVertex*> _vertexes;
	};
}
