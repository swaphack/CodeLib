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
		Circle(const Vector3& position, float radius);
		Circle(const Circle& circle);
		virtual ~Circle();
	public:
		/**
		*	位置
		*/
		const Vector3& getPosition() const;
		/**
		*	半径
		*/
		float getRadius() const;
	public:
		/**
		*	是否包含点
		*/
		bool contains(const Vector3& point) const;
	private:
		/**
		*	原点坐标
		*/
		Vector3 _position;
		/**
		*	半径
		*/
		float _radius = 0;
	};
}