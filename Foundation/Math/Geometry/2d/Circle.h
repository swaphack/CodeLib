#pragma once

#include "Algebra/import.h"

namespace math
{
	/**
	*	圆
	*/
	struct Circle
	{
	public:
		Circle();
		Circle(const Vector2& position, float radius);
		Circle(const Circle& circle);
		virtual ~Circle();
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