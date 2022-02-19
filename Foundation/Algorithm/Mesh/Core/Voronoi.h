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
		*	��һ�����������ڵ��߶εĴ�ֱƽ������ɵ������������ɡ�
		*	������ڵ���һ�㵽���ɸö���εĿ��Ƶ�ľ���С�ڵ���������ο��Ƶ�ľ���
		*/
		class Voronoi
		{
		public:
			Voronoi();
			virtual ~Voronoi();
		public:
			/**
			*	���ɶ����
			*/
			bool createWithRect(const math::Rect& rect, Delaunay* delaunay,
				std::vector<math::Polygon>& polygons,
				std::vector<math::LineSegment2d>& lineSegments);
			/**
			*	�㼯
			*/
			PointSet* getPointSet();
		private:
			/**
			*	���ɱ�
			*/
			std::set<MeshEdge*> generateEdgesMeshTriangle(const std::map<std::string, MeshTriangle*>& triangles);
		private:
			/**
			*	�㼯
			*/
			PointSet* _pointSet = nullptr;
		};
	}
}
