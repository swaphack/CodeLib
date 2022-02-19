#pragma once

#include "mathlib.h"

#include <set>
#include <map>
#include <string>

namespace alg
{
	namespace mesh
	{
		class Delaunay;
		class MeshPolygon;
		class MeshEdge;
		class PointSet;
		class MeshTriangle;

		/**
		*	是一组由连接两邻点线段的垂直平分线组成的连续多边形组成。
		*	多边形内的任一点到构成该多边形的控制点的距离小于到其他多边形控制点的距离
		*/
		class Voronoi
		{
		public:
			Voronoi();
			virtual ~Voronoi();
		public:
			/**
			*	生成多边形
			*/
			bool createWithRect(const math::Rect& rect, Delaunay* delaunay,
				std::vector<math::Polygon>& polygons,
				std::vector<math::LineSegment2d>& lineSegments);
			/**
			*	点集
			*/
			PointSet* getPointSet();
		private:
			/**
			*	生成边
			*/
			std::set<MeshEdge*> generateEdgesMeshTriangle(const std::map<std::string, MeshTriangle*>& triangles);
		private:
			/**
			*	点集
			*/
			PointSet* _pointSet = nullptr;
		};
	}
}
