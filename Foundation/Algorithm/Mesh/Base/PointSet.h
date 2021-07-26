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
	*	点集合
	*/
	class PointSet : public sys::Object
	{
	public:
		PointSet();
		virtual ~PointSet();
	public:
		/**
		*	创建点集
		*/
		static PointSet* create(int count, int width, int height);
	public:
		/**
		*	设置顶点
		*/
		void setPoints(const std::vector<math::Vector3>& points);
		/**
		*	获取点
		*/
		const math::Vector3* getPoint(int idx) const;
	public:
		/**
		*	创建顶点
		*/
		MeshVertex* createVertex(int idx0);
		/**
		*	创建顶点
		*/
		MeshVertex* createVertex(const math::Vector3& point0);
		/**
		*	移除顶点
		*/
		void removeVertex(MeshVertex* pVertex);
	public:
		/**
		*	创建边
		*/
		MeshEdge* createEdge(int idx0, int idx1);
		/**
		*	创建边
		*/
		MeshEdge* createEdge(const math::Vector3& point0, const math::Vector3& point1);
		/**
		*	创建边
		*/
		MeshEdge* createEdge(const MeshVertex* pVertex0, const MeshVertex* pVertex1);
		/**
		*	移除边
		*/
		void removeEdge(MeshEdge* pEdge);
	public:
		/**
		*	创建三角形
		*/
		MeshTriangle* createTriangle(int idx0, int idx1, int idx2);
		/**
		*	创建三角形
		*/
		MeshTriangle* createTriangle(const math::Vector3& point0, const math::Vector3& point1, const math::Vector3& point2);
		/**
		*	移除三角形
		*/
		void removeTriangle(MeshTriangle* pTriangle);
	public:
		/**
		*	创建多边形
		*/
		MeshPolygon* createPolygon(const std::vector<int>& vecIndices);
		/**
		*	创建多边形
		*/
		MeshPolygon* createPolygon(const std::vector<math::Vector3>& vecPoints);
		/**
		*	移除多边形
		*/
		void removePolygon(MeshPolygon* pPolygon);
	public:
		/**
		*	清空
		*/
		void cleanup();
	private:
		/**
		*	顶点坐标
		*/
		std::vector<math::Vector3> _vertices;
		/**
		*	顶点
		*/
		std::map<std::string, MeshVertex*> _meshVertexes;
		/**
		*	边
		*/
		std::map<std::string, MeshEdge*> _meshEdges;
		/**
		*	三角形
		*/
		std::map<std::string, MeshTriangle*> _meshTriangles;
		/**
		*	多边形
		*/
		std::map<std::string, MeshPolygon*> _meshPolygons;
	};
}