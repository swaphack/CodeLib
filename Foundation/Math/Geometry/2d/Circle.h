#pragma once

#include "Algebra/import.h"

namespace math
{
	/**
	*	Բ
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
		*	Բ��
		*/
		const Vector2& getPosition() const;
		/**
		*	�뾶
		*/
		float getRadius() const;
	public:
		/**
		*	�Ƿ������
		*/
		bool contains(const Vector2& point);
	private:
		/**
		*	ԭ������
		*/
		Vector2 _position;
		/**
		*	�뾶
		*/
		float _radius = 0;
	};
}