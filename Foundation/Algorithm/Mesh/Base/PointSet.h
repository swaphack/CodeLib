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
		*	点集合
		*/
		class PointSet : public sys::Object
		{
		public:
			PointSet();
			PointSet(const std::vector<math::Vector3>& points);
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
			const math::Vector3* getPosition(int idx) const;
			/**
			*	获取点数量
			*/
			int getPointCount() const;
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
			/**
			*	获取所有顶点
			*/
			const std::map<std::string, MeshVertex*>& getVertexes() const;
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
			*	创建三角形
			*/
			MeshTriangle* createTriangle(const MeshVertex* pVertex0, const MeshVertex* pVertex1, const MeshVertex* pVertex2);
			/**
			*	创建三角形
			*/
			MeshTriangle* createTriangle(const std::vector<MeshVertex*>& vertexes);
			/**
			*	移除三角形
			*/
			void removeTriangle(MeshTriangle* pTriangle);
			/**
			*	获取所有三角形
			*/
			const std::map<std::string, MeshTriangle*>& getTriangles() const;
			/**
			*	是否包含三角形
			*/
			bool containTriangle(const math::Vector3& point0, const math::Vector3& point1, const math::Vector3& point2) const;
			/**
			*	是否包含三角形
			*/
			bool containTriangle(const MeshVertex* vertex0, const MeshVertex* vertex1, const MeshVertex* vertex2) const;
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
			*	创建多边形
			*/
			MeshPolygon* createPolygon(const std::vector<MeshVertex* >& vecVertexes);
			/**
			*	移除多边形
			*/
			void removePolygon(MeshPolygon* pPolygon);
		public:
			/**
			*	清空
			*/
			void cleanup();

		public:
			/**
			*	获取键值
			*/
			static std::string getKey(const MeshVertex* pVertex);
			/**
			*	获取键值
			*/
			static std::string getKey(const MeshVertex* pVertex0, const MeshVertex* pVertex1);
			/**
			*	获取键值
			*/
			static std::string getKey(const MeshVertex* pVertex0, const MeshVertex* pVertex1, const MeshVertex* pVertex2);
			/**
			*	获取键值
			*/
			static std::string getKey(const std::vector<MeshVertex*>& vecVertex);
			/**
			*	获取键值
			*/
			static std::string getKey(const math::Vector3& point);
			/**
			*	获取键值
			*/
			static std::string getKey(const math::Vector3& point0, const math::Vector3& point1);
			/**
			*	获取键值
			*/
			static std::string getKey(const math::Vector3& point0, const math::Vector3& point1, const math::Vector3& point2);
			/**
			*	获取键值
			*/
			static std::string getKey(const std::vector<math::Vector3>& points);
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
}