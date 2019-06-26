#pragma once

#include "macros.h"

namespace sys
{
	struct AABB;
	// 线段
	struct Line2
	{
		// 起点
		Vector2 src;
		// 终点
		Vector2 dest;
		/**
		*	构造函数
		*/
		Line2();
		/**
		*	构造函数
		*/
		Line2(const Vector2& src, const Vector2& dest);
		/**
		*	长度
		*/
		float getLength();
		/**
		*	方向向量
		*/
		Vector2 getVector();
		/**
		*	方向向量
		*/
		Vector2 getVector() const;
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
		*	线段是否相交
		*/
		bool int32ersects(const Line2& line);
		/**
		*	到线段的最近点
		*/
		Vector2 closestPoint32(const Vector2& point32);
	public:
		/**
		*	点到直线的距离
		*	(x-x1)/(x2-x1)=(y-y1)/(y2-y1)
		*	直线方程 a * x + b * y + c = 0
		*	向量积和面积关系
		*/
		static float distance(const Line2& line, const Vector2& point32);
	};
}