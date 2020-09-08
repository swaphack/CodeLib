#pragma once

#include "Algebra/import.h"

namespace math
{
	/**
	*	圆
	*/
	struct Circle2d
	{
	public:
		Circle2d();
		Circle2d(const Vector2& position, float radius);
		Circle2d(const Circle2d& circle);
		virtual ~Circle2d();
	public:
		/**
		*	圆形
		*/
		const Vector2& getPosition() const;
		/**
		*	半径
		*/
		float getRadius() const;
	public:
		/**
		*	是否包含点
		*/
		bool contains(const Vector2& point);
	private:
		/**
		*	原点坐标
		*/
		Vector2 _position;
		/**
		*	半径
		*/
		float _radius = 0;
	};
}