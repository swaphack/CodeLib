#pragma once

#include "Algebra/import.h"
#include "Geometry/base/Points.h"
namespace math
{
	// 线段
	struct LineSegment3d : public Points<Vector3, 2>
	{
	public:
		/**
		*	构造函数
		*/
		LineSegment3d();
		/**
		*	构造函数
		*/
		LineSegment3d(const Vector3& src, const Vector3& dest);
	public:
		CREATE_INDEX_VALUE(Src, 0, Vector3);
		CREATE_INDEX_VALUE(Dest, 1, Vector3);
		/**
		*	长度
		*/
		float getMagnitude() const;
		/**
		*	方向向量
		*/
		Vector3 getVector() const;
		/**
		*	是否包含点
		*/
		bool contains(const Vector3& point) const;
		/**
		*	是否包含线段
		*/
		bool contains(const LineSegment3d& line) const;
		/**
		*	线段是否相交
		*/
		bool intersects(const LineSegment3d& line, Vector3& point) const;
		/**
		*	到线段的最近点
		*/
		Vector3 closestPoint(const Vector3& point) const;
	public:
		/**
		*	点到直线的距离
		*	(x-x1)/(x2-x1)=(y-y1)/(y2-y1)=(z-z1)/(z2-z1)
		*	直线方程，是两平面的交线
		*	直线方程 a * x + b * y + c * z + d = 0
		*	向量积和面积关系
		*/
		static float distance(const LineSegment3d& line, const Vector3& point);
	};
}