#pragma once

#include "Algebra/import.h"
#include "Geometry/2d/LineSegment2.h"
#include "Geometry/3d/LineSegment.h"

namespace math
{
	/**
	*	OBB碰撞盒
	*	oriented bounding box(方向矩形边界框)
	*	
	*/
	struct OBB 
	{
	public:
		// 中性点
		Vector3 center;
		// 面积
		Vector3 size;
		// 外围
		Vector3 extents;
		// 旋转角度
		Vector3 rotation;
		// 最小坐标
		Vector3 minPos;
		// 最大坐标
		Vector3 maxPos;
	public:
		/**
		*	构造
		*/
		OBB(const Vector3& center, const Vector3& size, const Vector3& rotation);
		/**
		*	构造
		*/
		OBB(const Vector3& center, const Vector3& size);
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
		bool contains(const LineSegment2& line);
		/**
		*	是否包含线段
		*/
		bool contains(const LineSegment& line);
		/**
		*	是否与线段相交
		*/
		bool intersects(const LineSegment2& line);
		/**
		*	是否与线段相交
		*/
		bool intersects(const LineSegment& line);
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
	private:
		/**
		*	计算投影
		*/
		void calProjections();
	};
}