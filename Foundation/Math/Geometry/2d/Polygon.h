#pragma once

#include "Algebra/import.h"
#include "Geometry/base/Line2.h"
#include <cstdint>

namespace math
{
	/**
	*	平面几何的多边形
	*/ 
	struct Polygon
	{
	public:
		// 顶点
		Vector2* points;
		// 顶点数
		int32_t count;
	public:
		Polygon();
		Polygon(const Polygon & polygon);
		Polygon(int32_t vcount, const Vector2* vpoints);

		virtual ~Polygon();
	public:
		void init(int32_t vcount, const Vector2* vpoints);
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
		/**
		*	是否与多边形相交
		*/
		bool intersects(const Polygon& polygon);
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