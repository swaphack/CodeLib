#pragma once

#include "Vector3.h"

namespace math
{
	/**
	*	平面方程
	*	Ax + By + Cz + D = 0;
	*/
	struct Plane
	{
	public:
		/**
		*	三点确定一条平面
		*/
		Plane(const Vector3& point0, const Vector3& point1, const Vector3& point2);
		/**
		*	过点，且知道法向量
		*/
		Plane(const Vector3& point, const Vector3& normal);
		/**
		*	参数方程
		*/
		Plane(float a, float b, float c, float d);
		/**
		*	复制
		*/
		Plane(const Plane& plane);
		virtual ~Plane();
	public:
		float getParamA() const;
		float getParamB() const;
		float getParamC() const;
		float getParamD() const;
		/**
		*	法线
		*/
		const Vector3& normal() const;
	public:
		/**
		*	点到平面的距离
		*/
		float getDistanceWithPoint(const Vector3& point);
	protected:
		float _paramA = 0;
		float _paramB = 0;
		float _paramC = 0;
		float _paramD = 0;
		/**
		*	法线
		*/
		Vector3 _normal;
	};
}