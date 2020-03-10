#pragma once

#include "Algebra/import.h"
#include "macros.h"

namespace math
{
	/**
	*	直线方程
	*	Ax + By + C = 0;
	*/
	struct Line2
	{
	public:
		/**
		*	参数
		*/
		Line2(float a, float b, float c);
		/**
		*	两点确定一条直线
		*/
		Line2(const Vector2& src, const Vector2& dest);
		Line2(const Line2& line);
	public:
		float getParamA() const;
		float getParamB() const;
		float getParamC() const;
		/**
		*	法向量
		*/
		const Vector2& getNormal() const;
		/**
		*	方向向量
		*/
		const Vector2& getDirection() const;
	public:
		/**
		*	点到直线的距离
		*/
		float getDistanceWithPoint(const Vector2& point);
		/**
		*	包含点
		*/
		bool contains(const Vector2& point);
		/**
		*	是否平行
		*/
		bool isParallel(const Line2& line);
		/**
		*	是否相交
		*/
		bool isIntersect(const Line2& line);
		/**
		*	点与直线的位置关系
		*/
		PointAndLinePositionType getPointPositionType(const Vector2& point);
	protected:
		float _paramA = 0;
		float _paramB = 0;
		float _paramC = 0;
		/**
		*	法向量
		*/
		Vector2 _normal;
		/**
		*	方向向量
		*/
		Vector2 _direction;
	};

}