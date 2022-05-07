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
		/// 网格多边形
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
			*	设置顶点
			*/
			void setVertexes(PointSet* pointSet, const std::vector<math::Vector3>& points);
			/**
			*	设置顶点
			*/
			void setVertexes(const std::vector<MeshVertex*>& vertexes);
		public:
			/**
			*	是否包含顶点
			*/
			bool hasVertex(const MeshVertex* pVertex) const;
			/**
			*	添加顶点
			*/
			void addVertex(const MeshVertex* pVertex);
			/**
			*	移除顶点
			*/
			void removeVertex(const MeshVertex* pVertex);
			/**
			*	获取顶点
			*/
			const MeshVertex* getVertex(int index) const;
			/**
			*	获取顶坐标
			*/
			math::Vector3 getPosition(int index) const;
			/**
			*	顶点个数
			*/
			int getVertexCount() const;
		public:
			/**
			*	是否包含边
			*/
			bool containEdge(const MeshEdge* pEdge) const;
			/**
			*	添加边
			*/
			void addEdge(const MeshEdge* pEdge);
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
}
