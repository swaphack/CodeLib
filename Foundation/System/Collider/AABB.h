#pragma once

#include "macros.h"

namespace sys
{
	struct Line2;
	struct Line3;

	/**
	*	AABB碰撞盒
	*	axially aligned bounding box(轴对齐矩形边界框)
	*/
	struct AABB
	{
	private:
		// 中心点
		Vector3 center;
		// 面积
		Vector3 size;
		// 最小坐标
		Vector3 minPos;
		// 最大坐标
		Vector3 maxPos;
	public:
		/**
		*	构造
		*/
		AABB(const Vector2& center, const Vector2& size);
		/**
		*	构造
		*/
		AABB(const Vector3& center, const Vector3& size);
		/**
		*	是否包含点
		*/
		bool contains(const Vector2& point32);
		/**
		*	是否包含点
		*/
		bool contains(const Vector3& point32);
		/**
		*	是否包含线段
		*/
		bool contains(const Line2& line);
		/**
		*	是否包含线段
		*/
		bool contains(const Line3& line);
		/**
		*	是否与线段相交
		*/
		bool int32ersects(const Line2& line);
		/**
		*	是否与线段相交
		*/
		bool int32ersects(const Line3& line);
		/**
		*	是否包含盒子
		*/
		bool contains(const AABB& bounds);
		/**
		*	两盒子是否相交
		*/
		bool int32ersects(const AABB& bounds);
		/**
		*	最小坐标
		*/
		inline const Vector3& Min() const { return minPos;  }
		/**
		*	最大坐标
		*/
		inline const Vector3& Max() const { return maxPos; }
		/**
		*	重载=
		*/
		void operator=(const AABB& aabb);
	};
}