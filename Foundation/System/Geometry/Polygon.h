#pragma once

#include "macros.h"

namespace sys
{
	struct AABB;
	struct Line2;
	/**
	*	平面几何的多边形
	*/ 
	struct Polygon
	{
		Vector2* points;
		int count;

		Polygon(Vector2* points, int count);

		~Polygon();
		/**
		*	获取包围盒
		*/
		AABB getBounds();
		/**
		*	获取包围盒
		*/
		AABB getBounds() const;
		/**
		*	是否包含点
		*/
		bool contains(const Vector2& point);
		/**
		*	是否包含线段
		*/
		bool contains(const Line2& line);
		/**
		*	是否与线段相交
		*/
		bool intersects(const Line2& line);
	public:
		/**
		*	是否是标准的多边形，顶点数大于等于3,并且相邻不存在共线的情况
		*/
		static bool isStandard(const Polygon& polygon);
		/**
		*	是否是凸多边形
		*/
		static bool isConvex(const Polygon& polygon);
	};
}