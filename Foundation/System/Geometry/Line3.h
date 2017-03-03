#pragma once

#include "macros.h"

namespace sys
{
	struct AABB;
	// 线段
	struct Line3
	{
		// 起点
		Vector3 src;
		// 终点
		Vector3 dest;
		/**
		*	构造函数
		*/
		Line3();
		/**
		*	构造函数
		*/
		Line3(const Vector3& src, const Vector3& dest);

		/**
		*	长度
		*/
		float getLength();
		/**
		*	方向向量
		*/
		Vector3 getVector();
		/**
		*	方向向量
		*/
		Vector3 getVector() const;
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
		bool contains(const Vector3& point);
		/**
		*	线段是否相交
		*/
		bool intersects(const Line3& line);
		/**
		*	到线段的最近点
		*/
		Vector3 closestPoint(const Vector3& point);
	public:
		/**
		*	点到直线的距离
		*	(x-x1)/(x2-x1)=(y-y1)/(y2-y1)=(z-z1)/(z2-z1)
		*	直线方程，是两平面的交线
		*	直线方程 a * x + b * y + c * z + d = 0
		*	向量积和面积关系
		*/
		static float distance(const Line3& line, const Vector3& point);
	};
}