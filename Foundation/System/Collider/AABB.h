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
		// 中心点
		Vector3 center;
		// 面积
		Vector3 size;
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
		bool contains(const Vector2& point);
		/**
		*	是否包含点
		*/
		bool contains(const Vector3& point);
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
		bool intersects(const Line2& line);
		/**
		*	是否与线段相交
		*/
		bool intersects(const Line3& line);
		/**
		*	是否包含盒子
		*/
		bool contains(const AABB& bounds);
		/**
		*	两盒子是否相交
		*/
		bool intersects(const AABB& bounds);

		/**
		*	重载=
		*/
		void operator=(const AABB& aabb);

		/**
		*	x轴的最小值
		*/
		float minX();
		/**
		*	y轴的最小值
		*/
		float minY();
		/**
		*	z轴的最小值
		*/
		float minZ();

		/**
		*	x轴的最大值
		*/
		float maxX();
		/**
		*	y轴的最大值
		*/
		float maxY();
		/**
		*	z轴的最大值
		*/
		float maxZ();

		/**
		*	x轴的最小值
		*/
		float minX() const;
		/**
		*	y轴的最小值
		*/
		float minY() const;
		/**
		*	z轴的最小值
		*/
		float minZ() const;

		/**
		*	x轴的最大值
		*/
		float maxX() const;
		/**
		*	y轴的最大值
		*/
		float maxY() const;
		/**
		*	z轴的最大值
		*/
		float maxZ() const;
	};
}