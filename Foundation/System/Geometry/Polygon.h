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
		// 顶点
		Vector2* point32s;
		// 顶点数
		int32 count;

		Polygon();
		Polygon(const Polygon & polygon);
		Polygon(Vector2* point32s, int32 count);

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
		bool contains(const Vector2& point32);
		/**
		*	是否包含线段
		*/
		bool contains(const Line2& line);
		/**
		*	是否与线段相交
		*/
		bool int32ersects(const Line2& line);
		/**
		*	是否与多边形相交
		*/
		bool int32ersects(const Polygon& polygon);
		/**
		*	重载=
		*/
		Polygon& operator=(const Polygon& polygon);
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