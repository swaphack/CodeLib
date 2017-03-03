#pragma once

#include "macros.h"

namespace sys
{
	struct Line3;
	struct Line2;

	/**
	*	OBB碰撞盒
	*	oriented bounding box(方向矩形边界框)
	*	
	*/
	struct OBB 
	{
		// 中性点
		Vector3 center;
		// 面积
		Vector3 size;
		// 旋转角度
		Vector3 rotation;

		/**
		*	构造
		*/
		OBB(const Vector3& center, const Vector3& size, const Vector3& rotation);
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
		bool contains(const OBB& bounds);
		/**
		*	两盒子是否相交
		*	分离轴定律：
		*	两个凸多边形物体，如果我们能找到一个轴，使得两个在物体在该轴上的投影互不重叠，则这两个物体之间没有碰撞发生，该轴为Separating Axis
		*
		*	两个多边形在所有轴上的投影都发生重叠，则判定为碰撞；否则，没有发生碰撞
		*/
		bool intersects(const OBB& bounds);

		/**
		*	重载=
		*/
		void operator=(const OBB& obb);

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