#pragma once

#include "Algebra/import.h"

namespace math
{
	/**
	*	点与直线的位置关系
	*/
	enum class PointAndLinePosition2DType
	{
		NONE,
		// 包含
		INCLUDE,
		// 在左边
		EXLUDE_LEFT,
		// 在右边
		EXLUDE_RIGHT,

	};

	/**
	*	直线方程
	*	Ax + By + C = 0;
	*/
	struct Line2d
	{
	public:
		/**
		*	参数
		*/
		Line2d(float a, float b, float c);
		/**
		*	两点确定一条直线
		*/
		Line2d(const Vector2& src, const Vector2& dest);
		Line2d(const Line2d& line);
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
		bool isParallel(const Line2d& line);
		/**
		*	是否相交
		*/
		bool isIntersect(const Line2d& line);
		/**
		*	点与直线的位置关系
		*/
		PointAndLinePosition2DType getPointPositionType(const Vector2& point);
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