#pragma once

#include "Algebra/import.h"

namespace math
{
	struct Plane;
	/**
	*	直线方程
	*	(x - x0) / vx = (y - y0) / vy = (z - z0)/ vz
	*/
	struct Line3d
	{
	public:
		/**
		*	两点确认一条直线
		*/
		Line3d(const Vector3& src, const Vector3& dest);
		/**
		*	两平面相交，确认一条直线
		*/
		Line3d(const Plane& plane0, const Plane& plane1);
		Line3d(const Line3d& line);
		virtual ~Line3d();
	public:
		/**
		*	点
		*/
		const Vector3& getPoint() const;
		/**
		*	方向
		*/
		const Vector3& getDirection() const;
	public:
		/**
		*	点到直线的距离
		*/
		float getDistanceWithPoint(const Vector3& point);
		/**
		*	是否包含点
		*/
		bool contains(const Vector3& point);
		/**
		*	是否平行
		*/
		bool isParallel(const Line3d& line);
		/**
		*	是否相交
		*/
		bool isIntersect(const Line3d& line);
	private:
		/**
		* 点
		*/
		Vector3 _point;
		/**
		*	方向
		*/
		Vector3 _direction;
	};

}