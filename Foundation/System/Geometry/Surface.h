#pragma once

#include "macros.h"

namespace sys
{
	struct Polygon;
	/**
	*	立体几何的面
	*/
	struct Surface
	{
		Vector3* points;
		int count;

		Surface(Vector3* points, int count);

		~Surface();
		/**
		*	法向量
		*/
		Vector3 normalVector();
		/**
		*	法向量
		*/
		Vector3 normalVector() const;
		/**
		*	是否包含点
		*	先判断是否共面，在判断投影是否包含
		*/
		bool contain(const Vector3& point);
	public:
		/**
		*	是否是标准的多边形，顶点数大于等于3,并且相邻不存在共线的情况
		*	且共面
		*/
		static bool isStandard(const Surface& surface);
		/**
		*	是否是凸多边形
		*/
		static bool isConvex(const Surface& surface);
		/**
		*	点与平面是否共面
		*/
		static bool isCoplanar(const Surface& surface, const Vector3& point);
		/**
		*	四点是否共面
		*/
		static bool isCoplanar(const Vector3& point0, const Vector3& point1, const Vector3& point2, 
			const Vector3& point3);
		/**
		*	投影到xoy面
		*/
		static Polygon projectOnXOY(const Surface& surface);
		/**
		*	投影到yoz面
		*/
		static Polygon projectOnYOZ(const Surface& surface);
		/**
		*	投影到xoz面
		*/
		static Polygon projectOnXOZ(const Surface& surface);
	};
}